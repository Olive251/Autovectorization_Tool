#TODO
# -MAYBE move the avt_resolverTemplate out of a .c file and into this file
#   OR figue out how bundling, etc works in python
# -write Makefile to utilize the *_AutoVTooled.c file
# -run the Makefile
# 
# Rework
# -Need to do some reworking:
# -avt should open the main.c
#   -THEN do what run currently does for each user created imported file
# -fix writeIfuncBits
#   -currently writes
#   -not breaking anything but NOT best practice compliant
#
# -HOW TO GET IMPORTED FILES
# header file names don't neccessarily correlate to their source file name
# Might be better to do it with all *.c files in the directory that aren't main?
#   Buuuut then that fails to consider programs that don't have main.c as their entry
#   Could search through every *.c file that doesn't contain a main(){}? 
# Easiest way to do this would be to make a class that uses instances of current AVT for each include

import sys

# Function suffixes
nonsve = '_NonSVE'
sve = '_SVE'
sve2 = '_SVE2'

class autoVectorTool:
    def __init__(self, filename:str):
        self._filename = filename
        self._newFile = ""
        self.orig_functionLines = self.getFunction()
        self._functionName = ""
        
    def run(self):
        functSVE2 = self.editFunction(self.orig_functionLines.copy(), sve2)
        functSVE = self.editFunction(self.orig_functionLines.copy(), sve)
        functNonSVE = self.editFunction(self.orig_functionLines.copy(), nonsve)

        fNameParts = self._filename.split(".")
        self._newFile = fNameParts[0] + "_AutoVTooled." + fNameParts[1]

        self.writeFunction(functSVE2)
        self.writeFunction(functSVE)
        self.writeFunction(functNonSVE)

        self.writeIFuncBits()

    def writeIFuncBits(self):
        # TODO
        # Get resolver and ifunc templates
        # Replace foo with _functionName
        # Write new functions to file with writeFunction()
        print("writeIFuncBits called")

        with open("avt_resolverTemplate.c", 'r') as template:
            t = template.read().splitlines()
            newIfuncBits:list = []

            for line in t:
                if "foo" in line:
                    line = line.replace("foo", self._functionName)
                    print(line)
                newIfuncBits.append(line)
            self.writeFunction(newIfuncBits)

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

    def writeFunction(self, functionLines:list):
        with open(self._newFile, 'a') as file:
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
#==============================================================================#

class avtFactorum:
    def __init__(self, filename:str):
        self._main = filename
        self._files = self.getImportFiles()

    def getImportFiles(self):
        #get imported user files (ie Function.c) from main
        #return list of said files
        pass

    def buildMakefile(self):
        #TODO
        # create the Makefile
        pass

    def run():
        #for each file in _files
        #  -build and run an avt
        #buildMakefile()
        #run maker file
        pass


if __name__ == "__main__":
    #TODO - update to use avtFactorium once completed
    avt = autoVectorTool(sys.argv[1])
    avt.run()