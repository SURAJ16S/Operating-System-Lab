#!/bin/bash
read -p "Enter filename: " file
read -p "Enter number of lines to display: " n
tail -n "$n" "$file"
