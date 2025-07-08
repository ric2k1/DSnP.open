#!/bin/bash

# VS Code Auto-Setup Script for LLVM Coding Standards
# This script helps set up VS Code for automatic formatting and static analysis

set -e

echo "Setting up VS Code for automatic LLVM coding standards checking..."

# Check if we're in the right directory
if [ ! -f ".clang-format" ] || [ ! -f ".clang-tidy" ]; then
    echo "Error: Please run this script from the Homework directory"
    echo "Make sure .clang-format and .clang-tidy files exist"
    exit 1
fi

# Check if VS Code is installed
if ! command -v code >/dev/null 2>&1; then
    echo "Warning: VS Code command line tool not found"
    echo "Please install VS Code and add it to your PATH"
    echo "Or run this script manually after opening VS Code"
fi

# Check if required tools are installed
echo "Checking required tools..."

if ! command -v clang-format >/dev/null 2>&1; then
    echo "Error: clang-format not found. Please install LLVM tools first."
    echo "Run: brew install llvm"
    exit 1
fi

if ! command -v clang-tidy >/dev/null 2>&1; then
    echo "Error: clang-tidy not found. Please install LLVM tools first."
    echo "Run: brew install llvm"
    exit 1
fi

echo "✓ clang-format found"
echo "✓ clang-tidy found"

# Make scripts executable
chmod +x scripts/*.sh

echo "✓ Made scripts executable"

# Create VS Code workspace if it doesn't exist
if [ ! -d ".vscode" ]; then
    mkdir -p .vscode
    echo "✓ Created .vscode directory"
fi

echo ""
echo "Setup completed successfully!"
echo ""
echo "Next steps:"
echo "1. Open VS Code"
echo "2. Open the Homework folder as workspace"
echo "3. Install recommended extensions when prompted"
echo "4. Start editing C++ files - they will be auto-formatted on save"
echo ""
echo "To test the setup:"
echo "1. Open any .cpp file"
echo "2. Write some poorly formatted code"
echo "3. Save the file (Cmd+S on macOS, Ctrl+S on Windows/Linux)"
echo "4. Watch it get automatically formatted!"
echo ""
echo "Manual tasks available:"
echo "- Ctrl+Shift+P -> 'Tasks: Run Task' -> 'Check Code Style'"
echo "- Ctrl+Shift+P -> 'Tasks: Run Task' -> 'Format Code'"
echo "- Ctrl+Shift+P -> 'Tasks: Run Task' -> 'Static Analysis'" 