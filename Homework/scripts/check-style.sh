#!/bin/bash
# Script to check and format C++ code according to LLVM coding standards

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    if [ $1 -eq 0 ]; then
        echo -e "${GREEN}✓${NC} $2"
    else
        echo -e "${RED}✗${NC} $2"
    fi
}

print_info() {
    echo -e "${YELLOW}→${NC} $1"
}

# Check if required tools are installed
check_tools() {
    local missing_tools=()
    
    if ! command -v clang-format &> /dev/null; then
        missing_tools+=("clang-format")
    fi
    
    if ! command -v clang-tidy &> /dev/null; then
        missing_tools+=("clang-tidy")
    fi
    
    if [ ${#missing_tools[@]} -ne 0 ]; then
        echo -e "${RED}Error: Missing required tools:${NC}"
        for tool in "${missing_tools[@]}"; do
            echo "  - $tool"
        done
        echo ""
        echo "Please install LLVM/Clang tools:"
        echo "  macOS:  brew install llvm"
        echo "  Ubuntu: sudo apt-get install clang-format clang-tidy"
        echo "  CentOS: sudo yum install clang-tools-extra"
        return 1
    fi
    
    return 0
}

# Function to format files
format_files() {
    local dir=$1
    local dry_run=$2
    
    print_info "Formatting C++ files in $dir..."
    
    if [ "$dry_run" = true ]; then
        find "$dir" -name "*.cpp" -o -name "*.h" -o -name "*.hpp" | while read file; do
            if clang-format -style=file -dry-run -Werror "$file" 2>/dev/null; then
                print_status 0 "$file (no changes needed)"
            else
                print_status 1 "$file (needs formatting)"
            fi
        done
    else
        find "$dir" -name "*.cpp" -o -name "*.h" -o -name "*.hpp" | while read file; do
            clang-format -style=file -i "$file"
            print_status 0 "$file (formatted)"
        done
    fi
}

# Function to run clang-tidy
run_tidy() {
    local dir=$1
    local fix=$2
    
    print_info "Running clang-tidy on $dir..."
    
    local tidy_args=""
    if [ "$fix" = true ]; then
        tidy_args="-fix"
    fi
    
    find "$dir" -name "*.cpp" | while read file; do
        # Skip files in lib directories
        if [[ "$file" == *"/lib/"* ]]; then
            continue
        fi
        
        echo "Checking $file..."
        if [ "$fix" = true ]; then
            clang-tidy $tidy_args "$file" -- -std=c++11 -I../include -I../../include
        else
            clang-tidy "$file" -- -std=c++11 -I../include -I../../include
        fi
    done
}

# Main script
main() {
    echo "LLVM Coding Standards Checker"
    echo "============================="
    echo ""
    
    # Check for required tools
    if ! check_tools; then
        exit 1
    fi
    
    # Parse arguments
    local command=$1
    local target=$2
    
    if [ -z "$command" ]; then
        echo "Usage: $0 <command> [target]"
        echo ""
        echo "Commands:"
        echo "  check    - Check formatting without making changes"
        echo "  format   - Apply formatting to files"
        echo "  tidy     - Run clang-tidy checks"
        echo "  tidy-fix - Run clang-tidy and apply fixes"
        echo "  all      - Run format and tidy"
        echo ""
        echo "Targets:"
        echo "  hw1, hw2, hw3, hw4, hw5, hw6, hw7, fraig"
        echo "  all - check all homework directories"
        echo ""
        echo "Examples:"
        echo "  $0 check hw1      # Check formatting for hw1"
        echo "  $0 format hw2     # Format all files in hw2"
        echo "  $0 tidy all       # Run clang-tidy on all homeworks"
        exit 1
    fi
    
    # Determine target directories
    local dirs=()
    if [ "$target" = "all" ] || [ -z "$target" ]; then
        dirs=(hw1 hw2 hw3 hw4 hw5 hw6 hw7 fraig)
    else
        dirs=($target)
    fi
    
    # Change to Homework directory
    cd "$(dirname "$0")/.." || exit 1
    
    # Execute command
    case $command in
        check)
            for dir in "${dirs[@]}"; do
                if [ -d "$dir" ]; then
                    format_files "$dir" true
                fi
            done
            ;;
        format)
            for dir in "${dirs[@]}"; do
                if [ -d "$dir" ]; then
                    format_files "$dir" false
                fi
            done
            ;;
        tidy)
            for dir in "${dirs[@]}"; do
                if [ -d "$dir" ]; then
                    run_tidy "$dir" false
                fi
            done
            ;;
        tidy-fix)
            for dir in "${dirs[@]}"; do
                if [ -d "$dir" ]; then
                    run_tidy "$dir" true
                fi
            done
            ;;
        all)
            for dir in "${dirs[@]}"; do
                if [ -d "$dir" ]; then
                    format_files "$dir" false
                    run_tidy "$dir" false
                fi
            done
            ;;
        *)
            echo "Unknown command: $command"
            exit 1
            ;;
    esac
}

main "$@" 