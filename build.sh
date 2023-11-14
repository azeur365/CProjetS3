#!/bin/bash
# A script to compile main.c with gcc and include all header and source files

# Find all the header files in the current directory and store them in a variable
headers=$(find . -name "*.h")

# Find all the source files in the current directory and store them in a variable
sources=$(find . -name "*.c" -not -name "main.c")

# Compile main.c with gcc and include all the header and source files
gcc -w -o Build/main $headers $sources main.c