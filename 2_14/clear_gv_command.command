#!/bin/bash
# Recursively deletes all files with ".gv" extension
cd "$(dirname "$0")"
for file in `find . -type f -name "*.gv"`
do
   rm $file
done
