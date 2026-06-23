#!/bin/bash
while true; do
    echo "1. Create 2. Delete 3. Copy 4. List 5. Exit"
    read -p "Enter choice: " choice
    case $choice in
    1) read -p "File to create: " f; touch "$f"; echo "Created." ;;
    2) read -p "File to delete: " f; rm "$f"; echo "Deleted." ;;
    3) read -p "Source: " s; read -p "Destination: " d; cp "$s" "$d"; echo "Copied." ;;
    4) ls -lh ;;
    5) exit 0 ;;
    *) echo "Invalid choice." ;;
    esac
done
