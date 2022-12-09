# Auto-Vectorization-Tool

AVT can currently be made executable by adding it to your /PATH

OR a copy can be placed in your desired directory and called using "py" or "python3"

> ie: "py avt helloWorld.c"

AVT can also modify a related Makefile and call make in the current directory by adding "-m" to the call arguments

> ie: "py avt helloWorld.c -m"

## Limitations

-Writes code for NonSVE, SVE, and SVE2. Is not granular.

## Update Log

-Dec 9: AVT is now able to handle multiple functions in a target file

-Dec 9: AVT can now handle all return types
