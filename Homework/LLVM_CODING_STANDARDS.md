# LLVM Coding Standards for DSnP Homework Projects

This document explains how to use LLVM coding standards and tools for the homework projects.

## Overview

LLVM coding standards help maintain consistent, readable, and high-quality C++ code. We use two main tools:

1. **clang-format**: Automatically formats code according to style rules
2. **clang-tidy**: Performs static analysis and suggests improvements

## Installation

### macOS

```bash
brew install llvm
```

### Ubuntu/Debian

```bash
sudo apt-get update
sudo apt-get install clang-format clang-tidy
```

### CentOS/RHEL

```bash
sudo yum install clang-tools-extra
```

## Configuration Files

- `.clang-format`: Defines code formatting rules based on LLVM style
- `.clang-tidy`: Configures static analysis checks

These files are located in the `Homework/` directory and apply to all subprojects.

## Using the Style Checker Script

We provide a convenient script `scripts/check-style.sh` to run these tools:

### Basic Usage

```bash
cd Homework
./scripts/check-style.sh <command> [target]
```

### Commands

- `check`: Check formatting without making changes
- `format`: Apply formatting to files
- `tidy`: Run clang-tidy checks
- `tidy-fix`: Run clang-tidy and apply fixes
- `all`: Run both format and tidy

### Targets

- Individual homework: `hw1`, `hw2`, `hw3`, `hw4`, `hw5`, `hw6`, `hw7`, `fraig`
- All homeworks: `all`

### Examples

```bash
# Check formatting for hw1 (dry run)
./scripts/check-style.sh check hw1

# Format all files in hw2
./scripts/check-style.sh format hw2

# Run static analysis on all homeworks
./scripts/check-style.sh tidy all

# Format and analyze hw3
./scripts/check-style.sh all hw3
```

## Manual Usage

### Using clang-format

```bash
# Check if formatting is needed (dry run)
clang-format -style=file -dry-run -Werror yourfile.cpp

# Format a single file
clang-format -style=file -i yourfile.cpp

# Format all C++ files in a directory
find . -name "*.cpp" -o -name "*.h" | xargs clang-format -style=file -i
```

### Using clang-tidy

```bash
# Check a file
clang-tidy yourfile.cpp -- -std=c++11

# Check and fix issues
clang-tidy -fix yourfile.cpp -- -std=c++11

# Check with custom includes
clang-tidy yourfile.cpp -- -std=c++11 -I../include
```

## Key Style Rules

Based on LLVM style with these adjustments:

### Indentation

- Use 4 spaces (no tabs)
- Indent case labels
- Indent namespace contents

### Naming Conventions

- Classes/Structs: `CamelCase`
- Functions/Methods: `camelBack`
- Variables: `camelBack`
- Private members: `_memberName` (with underscore prefix)
- Macros: `UPPER_CASE`

### Braces

- Opening braces on new line for functions, classes, and namespaces
- Opening braces on same line for control statements

### Example

```cpp
class MyClass {
public:
    MyClass();

    void doSomething();
    int getValue() const { return _value; }

private:
    int _value;
    std::string _name;
};

void MyClass::doSomething()
{
    if (condition) {
        // code
    } else {
        // code
    }

    for (int i = 0; i < 10; ++i) {
        // code
    }
}
```

## Workflow Recommendations

1. **Before committing**: Run `check-style.sh check <hw>` to verify formatting
2. **Format code**: Run `check-style.sh format <hw>` to fix formatting
3. **Check quality**: Run `check-style.sh tidy <hw>` for static analysis
4. **Fix issues**: Address warnings from clang-tidy manually or with `tidy-fix`

## Excluding Files

Some files (like those in `lib/` directories) are automatically excluded from checks. The reference implementations and provided code should not be modified.

## Integration with Editors

### VS Code

Install the "C/C++" extension and it will automatically use `.clang-format`.

### Vim

Add to `.vimrc`:

```vim
map <C-K> :pyf /usr/share/clang/clang-format.py<cr>
imap <C-K> <c-o>:pyf /usr/share/clang/clang-format.py<cr>
```

### Emacs

```elisp
(load "/usr/share/clang/clang-format.el")
(global-set-key [C-M-tab] 'clang-format-region)
```

## Notes

- The tools are configured for C++11 standard as used in the course
- Don't format or modify provided library files or reference implementations
- Focus on your own implementation files (those listed in `MustExist.txt`)
- The style checker is a tool to help maintain consistency, not a strict requirement for homework submission
