# Auto-Vectorization-Tool

AVT can currently be made executable by adding it to your /PATH

OR a copy can be placed in your desired directory and called using "py" or "python3"

>single file:   "py avt helloWorld.c"

>multi-file:    "py avt helloWorld.c foo.c"

AVT can also modify a related Makefile and call make in the current directory by adding "-m" to the call arguments

>"py avt helloWorld.c -m"

AVT can also target user specified autovectorization types

>"py avt helloWorld.c -nsve -sve -sve2" 

## Limitations

-Only for c and c++ files

-Only able to be used in aarch64 systems

## Update Log

-Dec 9:
> AVT is now able to handle multiple functions in a target file

> AVT can now handle all return types

-Dec 10:
> User can now target multiple files

> User can now select which autovectorization type to utilize with ifunc
