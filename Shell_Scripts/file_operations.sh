#!/bin/bash

# Step 1:
# Create file with .sh extension

# Step 2:
# Give execute permission
# chmod +x filemenu.sh

# Step 3:
# Run program
# ./filemenu.sh
# OR
# bash filemenu.sh

while true
do
    echo ""
    echo "===== FILE MENU ====="
    echo "1.Create File"
    echo "2.Delete File"
    echo "3.Copy File"
    echo "4.List Files"
    echo "5.Exit"

    read -p "Enter choice: " ch

    if [ $ch -eq 1 ]
    then
        read -p "Enter file name to create: " file
        touch $file
        echo "File Created"

    elif [ $ch -eq 2 ]
    then
        read -p "Enter file name to delete: " file
        rm $file
        echo "File Deleted"

    elif [ $ch -eq 3 ]
    then
        read -p "Enter source file: " source
        read -p "Enter destination file: " dest
        cp $source $dest
        echo "File Copied"

    elif [ $ch -eq 4 ]
    then
        ls

    elif [ $ch -eq 5 ]
    then
        echo "Program Closed"
        break

    else
        echo "Invalid Choice"
    fi

done