#!/bin/bash
read -p "Enter filename: " file
read -p "Enter number of lines to display: " n
head -n "$n" "$file"
