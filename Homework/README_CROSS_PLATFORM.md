# Cross-Platform LLVM Coding Standards Setup

This project enforces LLVM coding standards across macOS and Linux platforms. Windows support is not yet implemented.

## 🎯 Quick Start

### For All Platforms

1. **Clone the repository**:

   ```bash
   git clone <repository-url>
   cd Homework
   ```

2. **Run the cross-platform setup**:

   ```bash
   ./scripts/setup-cross-platform.sh
   ```

3. **Test the setup**:
   ```bash
   ./scripts/check-style.sh hw1/hw1/p2/p2Main.cpp
   ```

## 🖥️ Platform-Specific Setup

### macOS

#### Prerequisites

- **Homebrew** (recommended package manager)
- **Git** (for version control)
- **VS Code** or your preferred editor

#### Installation

```bash
# Install Homebrew (if not installed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install LLVM tools
brew install llvm

# Run setup
./scripts/setup-cross-platform.sh
```

#### macOS-Specific Notes

- LLVM tools are installed via Homebrew
- Git hooks are automatically configured
- VS Code integration is fully supported
- `.DS_Store` files are automatically ignored

### Linux

#### Prerequisites

- **Package manager** (apt, yum, dnf, or pacman)
- **Git** (for version control)
- **VS Code** or your preferred editor

#### Installation by Distribution

**Ubuntu/Debian:**

```bash
sudo apt-get update
sudo apt-get install clang-format clang-tidy
./scripts/setup-cross-platform.sh
```

**CentOS/RHEL:**

```bash
sudo yum install clang-tools-extra
./scripts/setup-cross-platform.sh
```

**Fedora:**

```bash
sudo dnf install clang-tools-extra
./scripts/setup-cross-platform.sh
```

**Arch Linux:**

```bash
sudo pacman -S clang
./scripts/setup-cross-platform.sh
```

#### Linux-Specific Notes

- LLVM tools are installed via your distribution's package manager
- Git hooks are automatically configured
- Editor configurations work across different Linux distributions
- Platform-specific temporary files are ignored

## 🛠️ Editor Support

### VS Code (Recommended)

- Automatic formatting on save
- Real-time static analysis
- C++17 IntelliSense support
- See `README_VSCODE_AUTO_CHECK.md` for detailed setup

### Vim/Neovim

- `.editorconfig` provides basic formatting
- Use `clang-format` integration plugins
- Configure for LLVM style

### Emacs

- `.editorconfig` provides basic formatting
- Use `clang-format` integration
- Configure for LLVM style

### Other Editors

- `.editorconfig` provides cross-editor consistency
- Manual integration with clang-format/clang-tidy

## 📋 What Gets Tracked vs Ignored

### ✅ Tracked Files (Essential for Standards)

- `.clang-format` - Formatting rules
- `.clang-tidy` - Static analysis rules
- `scripts/` - All setup and check scripts
- `*.md` - All documentation files
- `.editorconfig` - Cross-editor consistency

### ❌ Ignored Files (Platform/Editor Specific)

- `.vscode/settings.json` - User-specific VS Code settings
- `.idea/` - JetBrains IDE files
- `*.swp`, `*.swo` - Vim temporary files
- `.DS_Store` - macOS system files
- `*~` - Linux backup files
- `*.o`, `*.a`, `*.so` - Build artifacts

## 🔧 Configuration Files

### Core Configuration

- `.clang-format` - LLVM formatting rules
- `.clang-tidy` - Static analysis configuration
- `.editorconfig` - Cross-editor consistency
- `.gitignore` - Platform-agnostic ignore rules

### Scripts

- `scripts/setup-cross-platform.sh` - Main setup script
- `scripts/check-style.sh` - Style checking script
- `scripts/auto-check.sh` - Auto-checking script
- `scripts/setup-hooks.sh` - Git hooks setup
- `scripts/pre-commit` - Pre-commit hook

## 🧪 Testing Your Setup

### Test Formatting

```bash
# Create a poorly formatted file
echo 'int main(){int x=1;if(x==1){cout<<"hello"<<endl;}}' > test.cpp

# Check formatting
./scripts/check-style.sh test.cpp

# Should show formatting issues
```

### Test Static Analysis

```bash
# Check existing files
./scripts/check-style.sh hw1/hw1/p2/p2Main.cpp
```

### Test Git Hooks

```bash
# Make a change to a C++ file
echo "// test" >> hw1/hw1/p2/p2Main.cpp

# Try to commit
git add hw1/hw1/p2/p2Main.cpp
git commit -m "test"

# Should trigger pre-commit checks
```

## 🚨 Troubleshooting

### Common Issues

**1. LLVM tools not found**

```bash
# macOS
brew install llvm

# Ubuntu/Debian
sudo apt-get install clang-format clang-tidy

# CentOS/RHEL
sudo yum install clang-tools-extra
```

**2. Permission denied**

```bash
chmod +x scripts/*.sh
```

**3. Git hooks not working**

```bash
./scripts/setup-hooks.sh
```

**4. Editor not formatting**

- Check if `.clang-format` exists in project root
- Verify editor integration with clang-format
- Check `.editorconfig` settings

### Platform-Specific Issues

**macOS:**

- If Homebrew LLVM conflicts with Xcode, use: `export PATH="/usr/local/opt/llvm/bin:$PATH"`
- For Apple Silicon Macs, use: `export PATH="/opt/homebrew/opt/llvm/bin:$PATH"`

**Linux:**

- If clang-tidy not found, install `clang-tools-extra` package
- For older distributions, may need to add LLVM repository

## 📚 Documentation

- `LLVM_CODING_STANDARDS.md` - Detailed coding standards
- `README_VSCODE_AUTO_CHECK.md` - VS Code specific setup
- `SETUP_MACOS.md` - macOS specific instructions
- `SETUP_LINUX.md` - Linux specific instructions
- `VSCODE_AUTO_CHECK.md` - VS Code auto-check setup

## 🤝 Contributing

When contributing to this project:

1. **Follow LLVM standards** - All code must pass clang-format and clang-tidy
2. **Test on multiple platforms** - Ensure compatibility with macOS and Linux
3. **Update documentation** - Keep platform-specific instructions current
4. **Use cross-platform scripts** - Prefer the provided setup scripts

## 📞 Support

For issues:

1. Check platform-specific documentation
2. Run `./scripts/setup-cross-platform.sh` to verify setup
3. Test with `./scripts/check-style.sh`
4. Check editor integration

---

**Note:** Windows support is planned but not yet implemented. The project focuses on macOS and Linux compatibility.
