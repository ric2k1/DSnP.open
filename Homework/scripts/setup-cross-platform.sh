#!/bin/bash

# Cross-platform setup script for LLVM Coding Standards
# Supports macOS and Linux platforms
# Usage: ./setup-cross-platform.sh

set -e

echo "Setting up LLVM Coding Standards for cross-platform development..."
echo "================================================================"

# Detect platform
PLATFORM=""
if [[ "$OSTYPE" == "darwin"* ]]; then
    PLATFORM="macOS"
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    PLATFORM="Linux"
else
    echo "Warning: Unsupported platform detected: $OSTYPE"
    echo "This script is designed for macOS and Linux only."
    echo "Windows support is not yet implemented."
    PLATFORM="Unknown"
fi

echo "Detected platform: $PLATFORM"

# Check if we're in the right directory
if [ ! -f ".clang-format" ] || [ ! -f ".clang-tidy" ]; then
    echo "Error: Please run this script from the Homework directory"
    echo "Make sure .clang-format and .clang-tidy files exist"
    exit 1
fi

# Function to check and install LLVM tools
check_llvm_tools() {
    echo "Checking LLVM tools..."
    
    local clang_format_path=""
    local clang_tidy_path=""
    
    # Check for clang-format
    if command -v clang-format >/dev/null 2>&1; then
        clang_format_path=$(which clang-format)
        echo "✓ clang-format found: $clang_format_path"
    else
        echo "✗ clang-format not found"
        return 1
    fi
    
    # Check for clang-tidy
    if command -v clang-tidy >/dev/null 2>&1; then
        clang_tidy_path=$(which clang-tidy)
        echo "✓ clang-tidy found: $clang_tidy_path"
    else
        echo "✗ clang-tidy not found"
        return 1
    fi
    
    return 0
}

# Function to install LLVM tools on macOS
install_llvm_macos() {
    echo "Installing LLVM tools on macOS..."
    
    if command -v brew >/dev/null 2>&1; then
        echo "Using Homebrew to install LLVM..."
        brew install llvm
        echo "✓ LLVM installed via Homebrew"
    else
        echo "Error: Homebrew not found. Please install Homebrew first:"
        echo "  /bin/bash -c \"\$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)\""
        exit 1
    fi
}

# Function to install LLVM tools on Linux
install_llvm_linux() {
    echo "Installing LLVM tools on Linux..."
    
    if command -v apt-get >/dev/null 2>&1; then
        echo "Using apt to install LLVM..."
        sudo apt-get update
        sudo apt-get install -y clang-format clang-tidy
        echo "✓ LLVM installed via apt"
    elif command -v yum >/dev/null 2>&1; then
        echo "Using yum to install LLVM..."
        sudo yum install -y clang-tools-extra
        echo "✓ LLVM installed via yum"
    elif command -v dnf >/dev/null 2>&1; then
        echo "Using dnf to install LLVM..."
        sudo dnf install -y clang-tools-extra
        echo "✓ LLVM installed via dnf"
    elif command -v pacman >/dev/null 2>&1; then
        echo "Using pacman to install LLVM..."
        sudo pacman -S --noconfirm clang
        echo "✓ LLVM installed via pacman"
    else
        echo "Error: No supported package manager found."
        echo "Please install LLVM manually:"
        echo "  - Ubuntu/Debian: sudo apt-get install clang-format clang-tidy"
        echo "  - CentOS/RHEL: sudo yum install clang-tools-extra"
        echo "  - Arch Linux: sudo pacman -S clang"
        exit 1
    fi
}

# Function to setup Git hooks
setup_git_hooks() {
    echo "Setting up Git hooks..."
    
    if [ -d ".git" ]; then
        # Make scripts executable
        chmod +x scripts/*.sh
        
        # Copy pre-commit hook
        if [ -f "scripts/pre-commit" ]; then
            cp scripts/pre-commit .git/hooks/
            chmod +x .git/hooks/pre-commit
            echo "✓ Pre-commit hook installed"
        fi
        
        # Setup hooks directory
        if [ -f "scripts/setup-hooks.sh" ]; then
            ./scripts/setup-hooks.sh
            echo "✓ Git hooks setup completed"
        fi
    else
        echo "Warning: Not in a Git repository. Git hooks not installed."
    fi
}

# Function to setup editor configurations
setup_editor_configs() {
    echo "Setting up editor configurations..."
    
    # Create .editorconfig for cross-editor consistency
    cat > .editorconfig << 'EOF'
# EditorConfig is awesome: https://EditorConfig.org

# top-most EditorConfig file
root = true

# Unix-style newlines with a newline ending every file
[*]
end_of_line = lf
insert_final_newline = true
charset = utf-8
trim_trailing_whitespace = true

# C/C++ files
[*.{c,cpp,h,hpp,cc,cxx}]
indent_style = space
indent_size = 4
max_line_length = 80

# Makefiles
[Makefile]
indent_style = tab

# Markdown files
[*.md]
trim_trailing_whitespace = false
EOF
    
    echo "✓ .editorconfig created"
}

# Function to create platform-specific setup instructions
create_platform_instructions() {
    local platform="$1"
    local filename="SETUP_$(echo "$platform" | tr '[:lower:]' '[:upper:]').md"
    
    cat > "$filename" << EOF
# Setup Instructions for $platform

## Prerequisites

1. **Install LLVM Tools**:
   \`\`\`bash
   # macOS (using Homebrew)
   brew install llvm
   
   # Linux (Ubuntu/Debian)
   sudo apt-get install clang-format clang-tidy
   
   # Linux (CentOS/RHEL)
   sudo yum install clang-tools-extra
   
   # Linux (Arch)
   sudo pacman -S clang
   \`\`\`

2. **Install Git** (if not already installed)

3. **Install your preferred editor**:
   - VS Code: https://code.visualstudio.com/
   - Vim/Neovim: https://neovim.io/
   - Emacs: https://www.gnu.org/software/emacs/

## Setup Steps

1. **Clone the repository**:
   \`\`\`bash
   git clone <repository-url>
   cd Homework
   \`\`\`

2. **Run the setup script**:
   \`\`\`bash
   ./scripts/setup-cross-platform.sh
   \`\`\`

3. **Configure your editor** (see README_VSCODE_AUTO_CHECK.md for VS Code)

4. **Test the setup**:
   \`\`\`bash
   ./scripts/check-style.sh hw1/hw1/p2/p2Main.cpp
   \`\`\`

## Platform-Specific Notes

### $platform
- LLVM tools are installed via package manager
- Git hooks are automatically configured
- Editor configurations are set up for consistency

## Troubleshooting

If you encounter issues:

1. **LLVM tools not found**: Reinstall LLVM tools
2. **Permission denied**: Make scripts executable: \`chmod +x scripts/*.sh\`
3. **Git hooks not working**: Run \`./scripts/setup-hooks.sh\`

## Support

For issues specific to $platform, please check the platform-specific documentation.
EOF
    
    echo "✓ Created $filename"
}

# Main setup process
echo "Starting cross-platform setup..."

# Check/Install LLVM tools
if ! check_llvm_tools; then
    echo "LLVM tools not found. Installing..."
    case $PLATFORM in
        "macOS")
            install_llvm_macos
            ;;
        "Linux")
            install_llvm_linux
            ;;
        *)
            echo "Error: Unsupported platform for automatic installation"
            echo "Please install LLVM tools manually"
            exit 1
            ;;
    esac
    
    # Verify installation
    if ! check_llvm_tools; then
        echo "Error: LLVM tools installation failed"
        exit 1
    fi
fi

# Setup Git hooks
setup_git_hooks

# Setup editor configurations
setup_editor_configs

# Create platform-specific instructions
create_platform_instructions "$PLATFORM"

echo ""
echo "================================================================"
echo "Cross-platform setup completed successfully!"
echo "================================================================"
echo ""
echo "Next steps:"
echo "1. Configure your preferred editor"
echo "2. Test the setup with: ./scripts/check-style.sh hw1/hw1/p2/p2Main.cpp"
echo "3. Start coding with LLVM standards enforced!"
echo ""
echo "Platform-specific instructions created: SETUP_${PLATFORM^^}.md"
echo ""
echo "For VS Code users, see: README_VSCODE_AUTO_CHECK.md"
echo "For general setup, see: LLVM_CODING_STANDARDS.md" 