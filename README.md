# DSnP.open - C++ Programming and Data Structures Learning Project

[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://isocpp.org/std/the-standard)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Mac%20%7C%20Linux-lightgrey.svg)]()

## 📚 Project Overview

DSnP.open is an open-source C++ programming teaching project designed to help learners master C++ programming skills through practical implementation of various fundamental data structures. This project adopts modern C++17 standards and follows LLVM coding conventions, providing a high-quality programming practice environment for learners.

## 🎯 Learning Objectives

- Master modern C++17 programming language features
- Understand and implement fundamental data structures (arrays, linked lists, trees, graphs, etc.)
- Learn algorithm design and analysis
- Develop good programming habits and code standards
- Enhance problem-solving abilities and programming thinking

## 📁 Project Structure

```
DSnP.open/
├── Notes/           # 📖 Course Materials
│   ├── 01. C++ Review - The Basic (Variables, Classes, IO Streams).pdf
│   ├── 02. C++ Review - More on Functions, Variables, Classes.pdf
│   ├── 03. C++ Review - Overloading and Polymorphism.pdf
│   ├── 04. Memory Management and Exception Handling.pdf
│   ├── 05. Computational Complexity.pdf
│   ├── 06. List and Array.pdf
│   ├── 07. Tree (Part I).pdf
│   ├── 08. Graph and Circuit.pdf
│   ├── 09. C++ Review - More on IO Streams.pdf
│   ├── 10. Lex and Yacc.pdf
│   ├── 11. Heap Set and Map.pdf
│   └── 12. Cache vs Hash.pdf
├── Homework/        # 📝 Programming Assignments
│   ├── hw1/         # Basic C++ syntax and JSON processing
│   ├── hw2/         # Command line parser
│   ├── hw3/         # Database JSON operations
│   ├── hw4/         # Memory management
│   ├── hw5/         # Abstract Data Types (ADT)
│   ├── hw6/         # Circuit simulator
│   ├── hw7/         # Task manager
│   └── fraig/       # Advanced circuit optimization
├── Practices/       # 🛠️ Supplementary Exercises
│   ├── Practice_01.pdf
│   ├── Practice_02.pdf
│   ├── Practice_03.pdf
│   ├── Practice_04.pdf
│   └── Practice_09.pdf
└── README.md        # Project documentation
```

## 🚀 Quick Start

### Requirements

- **Compiler**: C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- **Operating System**: macOS or Linux
- **Build Tools**: Make
- **Code Analysis Tools**: clang-format, clang-tidy (recommended)

### Installing Dependencies

#### macOS

```bash
# Install Homebrew (if not installed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install LLVM toolchain
brew install llvm

# Install Make (usually pre-installed)
# brew install make
```

#### Ubuntu/Debian

```bash
# Install build tools
sudo apt update
sudo apt install build-essential make

# Install LLVM toolchain
sudo apt install clang-format clang-tidy
```

### Building and Running

1. **Clone the project**

```bash
git clone https://github.com/ric2k1/DSnP.open.git
cd DSnP.open
```

2. **Select assignment directory and read the homework description**

```bash
cd Homework/hw1/hw1
# Read Homework_1.{docx,pdf}
```

3. **Write your solutions and build the project**

```bash
# Finish your implementations
make clean
make
```

4. **Run tests**

```bash
# tests are usually under "tests" or "testcases" directories
# dofiles are usually named as "do*"
# scripts to automatically run dofiles are usually named "run*"
```

## 📖 Learning Path

```bash
# Note: These slides are C++11 compatible, not C++17.
# We may update them in the future.
```

### Phase 1: C++ Fundamentals (Notes 01-04)

- **Objective**: Master basic C++ syntax, class design, memory management
- **Practice**: Complete hw1-hw2 assignments
- **Focus**: Variables, functions, classes, inheritance, exception handling

### Phase 2: Data Structures Fundamentals (Notes 05-08)

- **Objective**: Understand algorithm complexity, implement basic data structures
- **Practice**: Complete hw3-hw5 assignments
- **Focus**: Basic operations of arrays, linked lists, trees, graphs

### Phase 3: Advanced Topics (Notes 09-12)

- **Objective**: Master advanced C++ features and algorithm optimization
- **Practice**: Complete hw6-hw7 and fraig project
- **Focus**: IO streams, parsers, caching, hash tables

## 🛠️ Development Tools Configuration

### VS Code Configuration

The project includes VS Code configuration files supporting:

- Automatic code formatting (clang-format)
- Static code analysis (clang-tidy)
- Intelligent code completion
- Debugging support

```bash
# Run configuration script
./setup_vscode.sh
```

### Coding Standards

The project follows LLVM coding conventions:

- Use 4-space indentation
- Function names use camelCase
- Class names use PascalCase
- Constants use UPPER_CASE with underscores
- Avoid using `using namespace std`

## 📋 Assignment Descriptions

### hw1: Basic C++ Syntax

- **Objective**: Familiarize with basic C++ syntax and JSON processing
- **Content**: Implement JSON parsing and generation functionality
- **Skills**: String processing, file I/O, class design

### hw2: Command Line Parser

- **Objective**: Learn command line argument parsing
- **Content**: Implement interactive command line interface
- **Skills**: String parsing, state machines, user interaction

### hw3: Database JSON Operations

- **Objective**: Master basic database operations
- **Content**: Implement simple JSON database
- **Skills**: Data persistence, query language, error handling

### hw4: Memory Management

- **Objective**: Deep understanding of memory management
- **Content**: Implement memory allocator and garbage collection
- **Skills**: Pointer operations, memory layout, performance optimization

### hw5: Abstract Data Types

- **Objective**: Implement fundamental data structures
- **Content**: Arrays, binary search trees, doubly linked lists
- **Skills**: Template programming, algorithm implementation, performance analysis

### hw6: Circuit Simulator

- **Objective**: Learn graph theory and circuit design
- **Content**: Implement digital circuit simulator
- **Skills**: Graph algorithms, state simulation, file parsing

### hw7: Task Manager

- **Objective**: Comprehensive application of learned knowledge
- **Content**: Implement multi-task scheduling system
- **Skills**: System design, concurrent programming, performance optimization

### fraig: Advanced Circuit Optimization

- **Objective**: Advanced algorithms and optimization techniques
- **Content**: Circuit equivalence checking and optimization
- **Skills**: SAT solving, algorithm optimization, large-scale data processing

## 🤝 Contributing

We welcome code contributions and improvement suggestions!

### Contribution Process

1. Fork this project
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Create a Pull Request

### Code Standards

- Follow LLVM coding conventions
- Add appropriate comments and documentation
- Ensure code passes all tests
- Update relevant documentation

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

Thanks to all developers and learners who have contributed to this project!

## 📞 Contact

For questions or suggestions, please contact us through:

- Create an Issue
- Send email to (cyhuang at ntu dot edu dot tw)
- Join our discussion group on [FB](https://www.facebook.com/groups/537247269679215/)

---

**Happy Coding! 🚀**
