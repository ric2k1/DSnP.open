# Installing LLVM Tools for Code Style Checking

This guide provides detailed instructions for installing clang-format and clang-tidy on different operating systems.

## macOS

### Option 1: Using Homebrew (Recommended)

```bash
# Install Homebrew if not already installed
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install LLVM (includes clang-format and clang-tidy)
brew install llvm

# Add LLVM to PATH (add to ~/.zshrc or ~/.bash_profile)
echo 'export PATH="/usr/local/opt/llvm/bin:$PATH"' >> ~/.zshrc
# Or for Intel Macs:
echo 'export PATH="/usr/local/opt/llvm/bin:$PATH"' >> ~/.zshrc
# For Apple Silicon Macs:
echo 'export PATH="/opt/homebrew/opt/llvm/bin:$PATH"' >> ~/.zshrc

# Reload shell configuration
source ~/.zshrc
```

### Option 2: Install only clang-format

```bash
brew install clang-format
```

## Ubuntu/Debian

### Option 1: Using APT (Recommended)

```bash
# Update package list
sudo apt-get update

# Install clang-format and clang-tidy
sudo apt-get install clang-format clang-tidy

# Install a specific version (e.g., version 14)
sudo apt-get install clang-format-14 clang-tidy-14
```

### Option 2: Install latest LLVM

```bash
# Add LLVM repository
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
sudo add-apt-repository "deb http://apt.llvm.org/focal/ llvm-toolchain-focal main"

# Install LLVM tools
sudo apt-get update
sudo apt-get install clang-format clang-tidy
```

## CentOS/RHEL/Fedora

### For CentOS 8/RHEL 8/Fedora

```bash
# Install development tools
sudo dnf groupinstall "Development Tools"

# Install clang tools
sudo dnf install clang-tools-extra
```

### For CentOS 7/RHEL 7

```bash
# Enable EPEL repository
sudo yum install epel-release

# Install clang tools
sudo yum install clang-tools-extra
```

## Windows

### Option 1: Using Visual Studio

- Install Visual Studio 2019 or later
- In the installer, select "Desktop development with C++"
- Under "Individual components", select "C++ Clang tools for Windows"

### Option 2: Using LLVM installer

1. Download LLVM installer from: https://releases.llvm.org/
2. Run the installer and add LLVM to system PATH
3. Restart your terminal/IDE

### Option 3: Using Chocolatey

```powershell
# Install Chocolatey if not installed
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))

# Install LLVM
choco install llvm
```

## Verifying Installation

After installation, verify the tools are working:

```bash
# Check clang-format
clang-format --version

# Check clang-tidy
clang-tidy --version
```

## Troubleshooting

### Command not found

- Make sure the LLVM bin directory is in your PATH
- Try using the full path to the executable
- Restart your terminal after installation

### Permission denied

- Use `sudo` for system-wide installation
- Check file permissions

### Version conflicts

- If you have multiple versions installed, use version-specific commands:
  ```bash
  clang-format-14 --version
  clang-tidy-14 --version
  ```

## Alternative: Using Docker

If you prefer not to install tools locally, you can use Docker:

```dockerfile
# Create a Dockerfile
FROM ubuntu:20.04
RUN apt-get update && apt-get install -y clang-format clang-tidy
WORKDIR /workspace
```

```bash
# Build and run
docker build -t cpp-tools .
docker run -v $(pwd):/workspace cpp-tools clang-format --style=file -i yourfile.cpp
```

## Next Steps

After installation:

1. Navigate to the Homework directory
2. Test the installation with: `./scripts/check-style.sh check hw1`
3. Read `LLVM_CODING_STANDARDS.md` for usage instructions
