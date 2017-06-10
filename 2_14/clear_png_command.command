#!/bin/bash
# Recursively deletes all files with ".png" extension
cd "$(dirname "$0")"
for file in `find . -type f -name "*.png"`
do
   rm $file
done
