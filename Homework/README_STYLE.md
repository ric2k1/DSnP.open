# LLVM Coding Standards Setup for DSnP Homework

This directory now includes LLVM coding standards configuration and tools for maintaining consistent C++ code style across all homework projects.

## Quick Start

1. **Install the required tools**:

   ```bash
   # macOS
   brew install llvm

   # Ubuntu/Debian
   sudo apt-get install clang-format clang-tidy
   ```

   See [INSTALL_TOOLS.md](INSTALL_TOOLS.md) for detailed installation instructions.

2. **Check code style**:

   ```bash
   cd Homework
   ./scripts/check-style.sh check hw1
   ```

3. **Format code**:

   ```bash
   ./scripts/check-style.sh format hw1
   ```

4. **Setup git hooks** (optional):
   ```bash
   ./scripts/setup-hooks.sh
   ```

## Files Overview

### Configuration Files

- `.clang-format` - Code formatting rules based on LLVM style
- `.clang-tidy` - Static analysis and code quality checks
- `.gitignore` - Ignore temporary files created by tools
- `.vscode/settings.json` - VS Code integration settings

### Scripts

- `scripts/check-style.sh` - Main script for checking and formatting code
- `scripts/pre-commit` - Git hook for automatic style checking
- `scripts/setup-hooks.sh` - Install git hooks

### Documentation

- `LLVM_CODING_STANDARDS.md` - Detailed guide on using the tools and style rules
- `INSTALL_TOOLS.md` - Installation instructions for all platforms
- `STYLE_EXAMPLE.md` - Before/after examples of code formatting
- `README_STYLE.md` - This file

## Key Commands

```bash
# Check all homeworks for style issues
./scripts/check-style.sh check all

# Format a specific homework
./scripts/check-style.sh format hw3

# Run static analysis
./scripts/check-style.sh tidy hw5

# Apply all checks and formatting
./scripts/check-style.sh all fraig
```

## Important Notes

1. **Don't modify library or reference files** - The tools automatically skip files in `lib/` and `ref/` directories

2. **Focus on your implementation files** - Only format files you're supposed to modify (check `MustExist.txt`)

3. **Style checking is optional** - These tools help maintain code quality but are not required for homework submission

4. **Backup your work** - Always commit or backup your code before running formatting tools

## VS Code Integration

If you use VS Code, the `.vscode/settings.json` file will:

- Enable automatic formatting on save
- Configure proper C++ IntelliSense
- Set correct indentation and style preferences

## Getting Help

- Run scripts without arguments to see usage information
- Check individual documentation files for detailed guides
- The style checker will provide specific error messages and suggestions

## Workflow Example

```bash
# 1. Make changes to your homework
cd Homework/hw2
vim cmdReader.cpp

# 2. Check style before committing
../scripts/check-style.sh check hw2

# 3. Fix any issues
../scripts/check-style.sh format hw2

# 4. Verify changes
git diff

# 5. Commit your work
git add .
git commit -m "Implement command reader functions"
```

Remember: The goal is to write clean, consistent, and maintainable code. These tools are here to help, not to hinder your learning!
