#!/bin/bash
read -p "Enter filename: " file
if [ -f "$file" ]; then
    wc "$file"
else
    echo "File not found."
fi
