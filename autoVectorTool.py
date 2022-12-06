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


def autoVectorTool(filename:str):
    orig_functionLines = getFunction(filename)

    functSVE2 = editFunction(orig_functionLines.copy(), sve2)
    functSVE = editFunction(orig_functionLines.copy(), sve)
    functNonSVE = editFunction(orig_functionLines.copy(), nonsve)

    fNameParts = filename.split(".")
    newFile = fNameParts[0] + "_AutoVTooled." + fNameParts[1]

    writeFunction(newFile, functSVE2)
    writeFunction(newFile, functSVE)
    writeFunction(newFile, functNonSVE)

def editFunction(functionLines:list, vectorizationSuffix:str):
    declaration = functionLines[0]

    declParts = declaration.split("(")

    declPts2 = declParts[0].split(" ")
    declPts2[1] = "*" + declPts2[1]
    declParts[0] = declPts2[0] + " " + declPts2[1]
    declParts[0] += vectorizationSuffix

    newDeclaration = declParts[0] + "(" + declParts[1]
    functionLines[0] = newDeclaration

    return functionLines

def writeFunction(filename:str, functionLines:list):
    with open(filename, 'a') as file:
        file.write('\n')
        for line in functionLines:
            file.write(line + '\n')

# Currently: Can retrieve a single function as a list of strings
# TODO: utilize makeFunctionLineList() to be able to return a list of lists of function lines
# ...(to clarify, return an array of functions broken down by lines)
def getFunction(filename:str):
    with open (filename, 'r') as src:
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

def makeFunctionLineList(functionLines:list):
    return functionLines       