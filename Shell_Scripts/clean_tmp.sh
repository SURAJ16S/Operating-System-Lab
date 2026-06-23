#!/bin/bash
THRESHOLD=80
USAGE=$(df -h /tmp | awk 'NR==2 {gsub("%",""); print $5}')
if [ "$USAGE" -ge "$THRESHOLD" ]; then
    echo "Threshold exceeded. Cleaning /tmp..."
    rm -rf /tmp/*
    echo "Cleanup complete."
fi
