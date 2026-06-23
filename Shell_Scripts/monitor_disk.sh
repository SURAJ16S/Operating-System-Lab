#!/bin/bash
THRESHOLD=80
USAGE=$(df -h / | awk 'NR==2 {gsub("%",""); print $5}')
if [ "$USAGE" -ge "$THRESHOLD" ]; then
    echo "WARNING: Disk usage is at ${USAGE}%" | mail -s "Disk Alert" user@localhost
fi
