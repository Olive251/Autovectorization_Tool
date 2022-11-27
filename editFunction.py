# Possible function suffixes
simd = '_ASIMD'
sve = '_SVE'
sve2 = 'SVE2'

#vectorization mode will be 0, 1, or 2
def editFunction(filename:str, vectorizationMode:int): 

    #setting up suffix and new filename for 
    vecTypeSuffix:str
    newFileName:str
    fNameParts:list = filename.split(".")
    if vectorizationMode == 0:
        vecTypeSuffix = simd
        newFileName = fNameParts[0] + simd + "." + fNameParts[1]
    elif vectorizationMode == 1:
        vecTypeSuffix = sve
        newFileName = fNameParts[0] + sve + "." + fNameParts[1]
    elif vectorizationMode == 2:
        vecTypeSuffix = sve2
        newFileName = fNameParts[0] + sve2 + "." + fNameParts[1]
    else:
        raise TypeError("vectorizationMode must be an integer 0-2")


    with open (filename, 'r') as src:
        src_orig = src.read().splitlines()

        newLines:list = []

        for line in src_orig:
            if "void" in line:

                lineParts = line.split("(")
                lineParts[0] += vecTypeSuffix

                line = lineParts[0] + "(" + lineParts[1]
                
            newLines.append(line)

    with open (newFileName, 'w') as new:
        for line in newLines:
            new.write(line + '\n')
                
