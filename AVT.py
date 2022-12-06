#TODO
# -create resolver and ifunc templates and store as class data members
# -create writeResolver() to replace "foo" in templates with _functionName
# -append those functions to the new file
# -write makerfile to utilize the *_AutoVTooled.c file
# -run the makerfile
# 
# Rework
# -Need to do some reworking:
# -avt should open the main.c
#   -THEN do what run currently does for each user created imported file
# Easiest way to do this would be to make a class that uses instances of current AVT for each include

import sys

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

        self.writeIFuncBits()
        self.buildMakerFile()

        #TODO - run the makerfile

    def writeIFuncBits(self):
        # TODO
        # Get resolver and ifunc templates
        # Replace foo with _functionName
        # Write new functions to file with writeFunction()
        pass

    def buildMakerFile(self):
        #TODO
        # create the makerfile
        pass

    def editFunction(self, functionLines:list, vectorizationSuffix:str = ""):
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

class avtFactorium:
    def __init__(self, filename:str):
        self._main = filename
        self._files = self.getImportFiles()
        pass

    def getImportFiles(self):
        #get imported user files (ie Function.c) from main
        #return list of said files
        pass

    def runFactorium():
        #run avt for each file in _files
        pass


if __name__ == "__main__":
    #TODO - update to use avtFactorium once completed
    avt = autoVectorTool(sys.argv[1])
    avt.run()