#!/bin/bash

# Auto-check script for VS Code save events
# Usage: ./auto-check.sh <filename>

set -e

if [ $# -eq 0 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

FILE="$1"
EXTENSION="${FILE##*.}"

# Only process C/C++ files
if [[ "$EXTENSION" =~ ^(cpp|cc|cxx|h|hpp)$ ]]; then
    echo "Auto-checking: $FILE"
    
    # Get the directory of the file
    DIR="$(dirname "$FILE")"
    cd "$DIR"
    
    # Run clang-format to fix formatting
    if command -v clang-format >/dev/null 2>&1; then
        echo "Formatting with clang-format..."
        clang-format -i "$(basename "$FILE")"
    fi
    
    # Run clang-tidy for static analysis
    if command -v clang-tidy >/dev/null 2>&1; then
        echo "Running static analysis with clang-tidy..."
        clang-tidy "$(basename "$FILE")" -- -std=c++17 2>/dev/null || true
    fi
    
    echo "Auto-check completed for: $FILE"
else
    echo "Skipping non-C++ file: $FILE"
fi 