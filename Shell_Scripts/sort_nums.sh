#!/bin/bash
read -p "Enter numbers separated by spaces: " -a nums
echo "Sorted numbers: $(printf "%s\n" "${nums[@]}" | sort -n | tr '\n' ' ')"
