# Setup Instructions for macOS

## Prerequisites

1. **Install LLVM Tools**:
   ```bash
   # macOS (using Homebrew)
   brew install llvm
   
   # Linux (Ubuntu/Debian)
   sudo apt-get install clang-format clang-tidy
   
   # Linux (CentOS/RHEL)
   sudo yum install clang-tools-extra
   
   # Linux (Arch)
   sudo pacman -S clang
   ```

2. **Install Git** (if not already installed)

3. **Install your preferred editor**:
   - VS Code: https://code.visualstudio.com/
   - Vim/Neovim: https://neovim.io/
   - Emacs: https://www.gnu.org/software/emacs/

## Setup Steps

1. **Clone the repository**:
   ```bash
   git clone <repository-url>
   cd Homework
   ```

2. **Run the setup script**:
   ```bash
   ./scripts/setup-cross-platform.sh
   ```

3. **Configure your editor** (see README_VSCODE_AUTO_CHECK.md for VS Code)

4. **Test the setup**:
   ```bash
   ./scripts/check-style.sh hw1/hw1/p2/p2Main.cpp
   ```

## Platform-Specific Notes

### macOS
- LLVM tools are installed via package manager
- Git hooks are automatically configured
- Editor configurations are set up for consistency

## Troubleshooting

If you encounter issues:

1. **LLVM tools not found**: Reinstall LLVM tools
2. **Permission denied**: Make scripts executable: `chmod +x scripts/*.sh`
3. **Git hooks not working**: Run `./scripts/setup-hooks.sh`

## Support

For issues specific to macOS, please check the platform-specific documentation.
