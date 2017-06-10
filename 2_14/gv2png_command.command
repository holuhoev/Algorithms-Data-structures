#!/bin/bash
# This script generate PNG images from graphs specified
# in graphviz format (DOT language) with ".gv" extension
cd "$(dirname "$0")" # Open the directory which this script is placed in
for file in `find . -type f -name "*.gv"` # Recursively looks for files with ".gv" extension
do
   short_name=${file%.*} # Extracts extension
   full_name=$short_name".png" # Adds needed extension
   `dot -Tpng $file>$full_name` # Generate PNG
done
