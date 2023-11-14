#!/bin/bash
# A script to run the build script and execute the main program

# Run the build script
./build.sh

# Check if the build was successful
if [ $? -eq 0 ]; then
    # Run the main program
    ./Build/main
else
    # Print an error message
    echo "Build failed"
fi
