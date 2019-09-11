all: test.out check_compiler

test.out:
	@g++ -std=c++11 test.cpp -o test.out
	@echo "Compile success!!"
	@./test.out
	@rm -rf ./test.out
check_compiler:
	@COMPILER_1=$$(g++ --version 2>&1| grep g++);COMPILER_2=$$(g++ --version | grep clang);\
	if [ "$${COMPILER_2}" != "" ];\
	then echo "compiling using clang!! Please redirect";\
	elif [ "$${COMPILER_1}" = "" ];\
	then echo "Error: g++ not found";\
	else echo "compiler check pass !!";\
	fi
	@echo
	@echo "compiler using :"
	@echo "$$(g++ --version)"
