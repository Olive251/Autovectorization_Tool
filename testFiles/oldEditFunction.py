#vectorization mode will be 0, 1, or 2
def editFunction(filename:str, vectorizationMode:int): 
    #setting up suffix and new filename for 
    vecTypeSuffix:str
    newFileName = filename + "_autoVTooled"
    fNameParts:list = filename.split(".")
    if vectorizationMode == 0:
        vecTypeSuffix = simd
        # newFileName = fNameParts[0] + simd + "." + fNameParts[1]
    elif vectorizationMode == 1:
        vecTypeSuffix = sve
        # newFileName = fNameParts[0] + sve + "." + fNameParts[1]
    elif vectorizationMode == 2:
        vecTypeSuffix = sve2
        # newFileName = fNameParts[0] + sve2 + "." + fNameParts[1]
    else:
        raise TypeError("vectorizationMode must be an integer 0-2")

    functionLines = getFunction(filename)

    declLineParts = functionLines[0].split("(")

    declLineParts[0] += vecTypeSuffix
    newDecl = declLineParts[0] + "(" + declLineParts[1]

    functionLines[0] = newDecl

    with open (newFileName, 'w') as new:
        for line in functionLines:
            new.write(line + '\n')