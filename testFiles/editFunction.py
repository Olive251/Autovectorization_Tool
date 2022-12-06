# This portion of the project will control the creation of a modified copy of the source function file
# CURRENTLY: The function simply appends a suffix onto the name of the file passed into the function.

#PLANNING: The next step will be to make another function which:
    # -Determines system capabilities (ASIMD, SVE, SVE2)
    # -Calls the editFunction for the function.c file with vectorizationMode determined by system 

# Possible function suffixes
simd = '_ASIMD'
sve = '_SVE'
sve2 = 'SVE2'

def makeFunctionLineList(functionLines:list):
    return functionLines

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




# #vectorization mode will be 0, 1, or 2
# def editFunction(filename:str, vectorizationMode:int): 
#     #setting up suffix and new filename for 
#     vecTypeSuffix:str
#     newFileName = filename + "_autoVTooled"
#     fNameParts:list = filename.split(".")
#     if vectorizationMode == 0:
#         vecTypeSuffix = simd
#         # newFileName = fNameParts[0] + simd + "." + fNameParts[1]
#     elif vectorizationMode == 1:
#         vecTypeSuffix = sve
#         # newFileName = fNameParts[0] + sve + "." + fNameParts[1]
#     elif vectorizationMode == 2:
#         vecTypeSuffix = sve2
#         # newFileName = fNameParts[0] + sve2 + "." + fNameParts[1]
#     else:
#         raise TypeError("vectorizationMode must be an integer 0-2")

#     functionLines = getFunction(filename)

#     declLineParts = functionLines[0].split("(")

#     declLineParts[0] += vecTypeSuffix
#     newDecl = declLineParts[0] + "(" + declLineParts[1]

#     functionLines[0] = newDecl

#     with open (newFileName, 'w') as new:
#         for line in functionLines:
#             new.write(line + '\n')