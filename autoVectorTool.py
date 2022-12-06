#TODO
# -get file
# -write C code to determine system capability into C file
# -write implementations of C code for all capabilities using editFunction()
# -write ifunc resolver function

#Possible Changes
# -Should make this into a class.
    # Would allow saving the original function name in order to replace "foo"s in a resolver template

# Function suffixes
nonsve = '_NonSVE'
sve = '_SVE'
sve2 = 'SVE2'

class autoVectorTool:

    def __init__(self, filename:str):
        self._filename = filename
        self.orig_functionLines = self.getFunction()
        self._functionName = ""
        
    def run(self):

        functSVE2 = self.editFunction(self.orig_functionLines.copy(), sve2)
        functSVE = self.editFunction(self.orig_functionLines.copy(), sve)
        functNonSVE = self.editFunction(self.orig_functionLines.copy(), nonsve)

        fNameParts = self._filename.split(".")
        newFile = fNameParts[0] + "_AutoVTooled." + fNameParts[1]

        self.writeFunction(newFile, functSVE2)
        self.writeFunction(newFile, functSVE)
        self.writeFunction(newFile, functNonSVE)

    def editFunction(self, functionLines:list, vectorizationSuffix:str):
        declaration = functionLines[0]

        declParts = declaration.split("(")

        declPts2 = declParts[0].split(" ")

        if not self._functionName:
            self._functionName = declPts2[1]

        declPts2[1] = "*" + declPts2[1]
        declParts[0] = declPts2[0] + " " + declPts2[1]
        declParts[0] += vectorizationSuffix

        newDeclaration = declParts[0] + "(" + declParts[1]
        functionLines[0] = newDeclaration

        return functionLines

    def writeFunction(self, filename:str, functionLines:list):
        with open(filename, 'a') as file:
            file.write('\n')
            for line in functionLines:
                file.write(line + '\n')

    # Currently: Can retrieve a single function as a list of strings
    # TODO: utilize makeFunctionLineList() to be able to return a list of lists of function lines
    # ...(to clarify, return an array of functions broken down by lines)
    def getFunction(self):
        with open (self._filename, 'r') as src:
            src_orig = src.read().splitlines()

            functionLines:list = []

            isFunctionLine = False
            openBrackets = 0

            for line in src_orig:
                if isFunctionLine is False:
                    if "{" in line:
                        isFunctionLine = True
                        openBrackets = openBrackets + 1
                        functionLines.append(line)
                else:
                    if "{" in line:
                        openBrackets = openBrackets + 1
                        functionLines.append(line)
                    elif "}" in line:
                        openBrackets = openBrackets - 1
                        functionLines.append(line)
                        if openBrackets == 0:
                            isFunctionLine = False
                            break
                    else:
                        functionLines.append(line)
        
            return functionLines

    def makeFunctionLineList(self, functionLines:list):
        return functionLines       