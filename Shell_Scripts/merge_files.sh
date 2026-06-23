#!/bin/bash
read -p "Enter File 1: " f1
read -p "Enter File 2: " f2
read -p "Enter Output File: " out
cat "$f1" "$f2" > "$out"
echo "Files merged into $out successfully."
