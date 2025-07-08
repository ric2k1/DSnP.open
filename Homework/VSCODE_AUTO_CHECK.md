# VS Code Auto-Save Formatting and Static Analysis Configuration

## Feature Overview

This configuration implements automatic operations in VS Code when saving C++ files:

1. **Automatic Formatting**: Uses clang-format to format code according to LLVM coding standards
2. **Static Analysis**: Uses clang-tidy for code quality checks
3. **Error Display**: Shows formatting and static analysis issues in the editor

## Required VS Code Extensions

Please install the following extensions:

- `ms-vscode.cpptools` - C/C++ support
- `llvm-vs-code-extensions.vscode-clangd` - LLVM language server
- `ms-vscode.cpptools-extension-pack` - C++ extension pack
- `ms-vscode.makefile-tools` - Makefile support

## Configuration Details

### 1. Auto-Save Settings

- `files.autoSave`: "afterDelay" - Auto-save after 1 second delay
- `files.autoSaveDelay`: 1000 - 1 second delay

### 2. Formatting Settings

- `editor.formatOnSave`: true - Auto-format on save
- `C_Cpp.clang_format_style`: "file" - Use .clang-format file in project root

### 3. Static Analysis Settings

- `C_Cpp.default.clangTidyEnabled`: true - Enable clang-tidy
- `C_Cpp.default.clangTidyChecks`: "modernize-_,readability-_,performance-_,bugprone-_" - Check rules

### 4. C++17 Support

- `C_Cpp.default.cppStandard`: "c++17" - Use C++17 standard

## Usage

### Automatic Checking (Recommended)

1. Open VS Code
2. Open the project folder (Homework directory)
3. Edit any .cpp or .h file
4. Auto-formatting and static analysis will occur when saving

### Manual Checking

1. Press `Ctrl+Shift+P` (Windows/Linux) or `Cmd+Shift+P` (macOS)
2. Type "Tasks: Run Task"
3. Select one of the following tasks:
   - "Check Code Style" - Run complete style check
   - "Format Code" - Format code only
   - "Static Analysis" - Run static analysis only

### Keyboard Shortcuts

- `Ctrl+S` (Windows/Linux) or `Cmd+S` (macOS) - Save and auto-check
- `Shift+Alt+F` - Manually format current file

## Troubleshooting

### 1. If Auto-formatting Doesn't Work

- Check if clang-format is installed
- Confirm .clang-format file exists in project root
- Check if file association settings are correct

### 2. If Static Analysis Doesn't Work

- Check if clang-tidy is installed
- Confirm .clang-tidy file exists in project root
- Check C++ standard settings

### 3. If Extensions Don't Work

- Restart VS Code
- Check if extensions are properly installed
- View error messages in VS Code output panel

## File Structure

```
Homework/
├── .vscode/
│   ├── settings.json      # VS Code settings
│   ├── tasks.json         # Task configuration
│   ├── launch.json        # Debug configuration
│   └── extensions.json    # Recommended extensions
├── scripts/
│   ├── check-style.sh     # Style checking script
│   └── auto-check.sh      # Auto-checking script
├── .clang-format          # Formatting configuration
└── .clang-tidy           # Static analysis configuration
```

## Verify Configuration

1. Open any .cpp file
2. Intentionally write some incorrectly formatted code
3. Save the file
4. Observe if code is auto-formatted
5. Check static analysis warnings in VS Code problem panel

## Important Notes

- Auto-checking only triggers when saving C++ files
- Static analysis results will show in VS Code problem panel
- Formatting is applied immediately without manual confirmation
- It's recommended to run complete style check before committing code
