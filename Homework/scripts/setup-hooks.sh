#!/bin/bash
# Setup script for git hooks

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

echo "Setting up git hooks for LLVM coding standards..."

# Check if we're in a git repository
if [ ! -d "$REPO_ROOT/.git" ]; then
    echo "Error: Not in a git repository root!"
    echo "Please run this script from the repository root."
    exit 1
fi

# Create hooks directory if it doesn't exist
mkdir -p "$REPO_ROOT/.git/hooks"

# Copy pre-commit hook
if [ -f "$SCRIPT_DIR/pre-commit" ]; then
    cp "$SCRIPT_DIR/pre-commit" "$REPO_ROOT/.git/hooks/pre-commit"
    chmod +x "$REPO_ROOT/.git/hooks/pre-commit"
    echo "✓ Pre-commit hook installed successfully!"
else
    echo "✗ pre-commit script not found!"
    exit 1
fi

echo ""
echo "Git hooks setup complete!"
echo ""
echo "The pre-commit hook will:"
echo "  - Check C++ files for LLVM coding standards before each commit"
echo "  - Prevent commits if formatting issues are found"
echo "  - Skip checks for library and reference files"
echo ""
echo "To bypass the hook (not recommended):"
echo "  git commit --no-verify"
echo ""
echo "To remove the hook:"
echo "  rm $REPO_ROOT/.git/hooks/pre-commit" 