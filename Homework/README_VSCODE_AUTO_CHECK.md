# VS Code Auto-Save Formatting and Static Analysis - Complete Guide

## 🎯 Feature Overview

This configuration implements automatic operations in VS Code when saving C++ files:

✅ **Automatic Formatting**: Uses clang-format to format code according to LLVM coding standards  
✅ **Static Analysis**: Uses clang-tidy for code quality checks  
✅ **Error Display**: Shows formatting and static analysis issues in the editor  
✅ **C++17 Support**: Full support for C++17 standard features

## 🚀 Quick Start

### 1. Run Auto-Setup Script

```bash
cd Homework
./scripts/setup-vscode.sh
```

### 2. Open VS Code

```bash
code .
```

### 3. Install Recommended Extensions

VS Code will prompt to install recommended extensions, please click "Install All".

### 4. Start Coding

Now every time you save a C++ file, it will be automatically formatted and checked!

## 📋 Required Tools

Ensure the following tools are installed:

- **LLVM Toolchain**: `brew install llvm`
- **VS Code**: Download and install from official website
- **VS Code Extensions**: C/C++, clangd, etc.

## ⚙️ Configuration Details

### Auto-Save Settings

- Auto-save after 1 second delay
- Auto-format on save
- Run static analysis on save

### Formatting Rules

- Use LLVM coding standards
- 4-space indentation
- 80 character line width limit
- Auto-alignment and line breaks

### Static Analysis Rules

- Modernization checks (modernize-\*)
- Readability checks (readability-\*)
- Performance checks (performance-\*)
- Bug-prone checks (bugprone-\*)

## 🎮 Usage

### Automatic Checking (Recommended)

1. Edit any .cpp or .h file
2. Press `Cmd+S` (macOS) or `Ctrl+S` (Windows/Linux) to save
3. Observe automatic code formatting and static analysis results

### Manual Checking

1. Press `Cmd+Shift+P` (macOS) or `Ctrl+Shift+P` (Windows/Linux)
2. Type "Tasks: Run Task"
3. Select tasks:
   - **Check Code Style** - Complete style check
   - **Format Code** - Format only
   - **Static Analysis** - Static analysis only

### Keyboard Shortcuts

- `Cmd+S` / `Ctrl+S` - Save and auto-check
- `Shift+Alt+F` - Manually format current file
- `Cmd+Shift+P` / `Ctrl+Shift+P` - Command palette

## 📁 File Structure

```
Homework/
├── .vscode/
│   ├── settings.json      # VS Code settings
│   ├── tasks.json         # Task configuration
│   ├── launch.json        # Debug configuration
│   └── extensions.json    # Recommended extensions
├── scripts/
│   ├── check-style.sh     # Style checking script
│   ├── auto-check.sh      # Auto-checking script
│   └── setup-vscode.sh    # Auto-setup script
├── .clang-format          # Formatting configuration
├── .clang-tidy           # Static analysis configuration
└── VSCODE_AUTO_CHECK.md  # Detailed documentation
```

## 🧪 Test Configuration

### Test Auto-formatting

1. Open any .cpp file
2. Intentionally write some incorrectly formatted code:

```cpp
int main(){
int x=1;
if(x==1){
cout<<"hello"<<endl;
}
}
```

3. Save the file
4. Observe code auto-formatted to:

```cpp
int main() {
    int x = 1;
    if (x == 1) {
        cout << "hello" << endl;
    }
}
```

### Test Static Analysis

1. Open any .cpp file
2. Add some problematic code
3. Save the file
4. Check static analysis warnings in VS Code problem panel

## 🔧 Troubleshooting

### Problem 1: Auto-formatting Not Working

**Solution:**

- Check if clang-format is installed: `which clang-format`
- Confirm .clang-format file exists
- Restart VS Code

### Problem 2: Static Analysis Not Working

**Solution:**

- Check if clang-tidy is installed: `which clang-tidy`
- Confirm .clang-tidy file exists
- Check C++ standard settings

### Problem 3: Extensions Not Working

**Solution:**

- Restart VS Code
- Check if extensions are properly installed
- View error messages in VS Code output panel

### Problem 4: Script Permission Errors

**Solution:**

```bash
chmod +x scripts/*.sh
```

## 📊 Supported C++17 Features

This configuration fully supports C++17 features:

- ✅ Structured Bindings
- ✅ std::optional
- ✅ std::variant
- ✅ if constexpr
- ✅ Fold Expressions
- ✅ Class Template Argument Deduction (CTAD)
- ✅ Inline Variables

## 🎯 Best Practices

1. **Run Complete Checks Regularly**: Use "Check Code Style" task
2. **Check Problem Panel**: Pay attention to static analysis warnings
3. **Use C++17 Features**: Take full advantage of modern C++ features
4. **Keep Code Clean**: Let auto-formatting maintain consistent code style

## 📞 Get Help

If you encounter issues:

1. Check `VSCODE_AUTO_CHECK.md` detailed documentation
2. Run `./scripts/setup-vscode.sh` to reset
3. Check if tools are properly installed
4. View error messages in VS Code output panel

---

**Enjoy the automated coding experience!** 🎉
