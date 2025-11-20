#!/bin/bash

DIRECTORY="$1"
DESTINATION="$2"

total_lines_matched=0
files_moved_count=0

mkdir -p "$DESTINATION"

for file in "$DIRECTORY"/*; do
    if [ -f "$file" ]; then
        matches=$(grep -c "moveme" "$file")
        if [ "$matches" -gt 0 ]; then
            total_lines_matched=$((total_lines_matched + matches))
            files_moved_count=$((files_moved_count + 1))
            mv "$file" "$DESTINATION"
        fi
    fi
done

echo "$total_lines_matched"
echo "$files_moved_count"
