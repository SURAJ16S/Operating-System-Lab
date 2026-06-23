#!/bin/bash
read -p "Enter first number: " n1
read -p "Enter second number: " n2
read -p "Enter operation (+, -, *, /): " op
echo "Result: $(echo "scale=2; $n1 $op $n2" | bc)"
