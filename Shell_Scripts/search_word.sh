#!/bin/bash
read -p "Enter word to search: " word
read -p "Enter filename: " file
count=$(grep -o -i "$word" "$file" | wc -l)
echo "The word '$word' occurs $count times in $file."
