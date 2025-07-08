/****************************************************************************
  FileName     [ main.cpp ]
  PackageName  [ main ]
  Synopsis     [ Define main() function ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2007-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/
#include "cmdParser.h"

#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

namespace
{
void usage()
{
    std::cout << "Usage: cmdReader [ -File < doFile > ]\n";
}

void myexit()
{
    usage();
    std::exit(EXIT_FAILURE);
}

int myStrNCmp(const std::string &str1, const std::string &str2, unsigned length)
{
    assert(length > 0);
    const unsigned length2 = str2.size();
    if (length2 == 0)
        return -1;
    const unsigned length1 = str1.size();
    assert(length1 >= length);
    for (unsigned i = 0; i < length1; ++i) {
        if (i == length2)
            return (i < length) ? 1 : 0;
        const char ch1 =
            (std::isupper(str1[i])) ? std::tolower(str1[i]) : str1[i];
        const char ch2 =
            (std::isupper(str2[i])) ? std::tolower(str2[i]) : str2[i];
        if (ch1 != ch2)
            return (ch1 - ch2);
    }
    return (length1 - length2);
}
}  // anonymous namespace

int main(int argc, char **argv)
{
    CmdParser cmd;

    if (argc == 3) {  // -File <doFile>
        if (myStrNCmp("-File", argv[1], 2) == 0) {
            if (!cmd.openDofile(argv[2])) {
                std::cerr << "Error: cannot open file \"" << argv[2]
                          << "\"!!\n";
                myexit();
            }
        }
        else {
            std::cerr << "Error: unknown argument \"" << argv[1] << "\"!!\n";
            myexit();
        }
    }
    else if (argc != 1) {
        std::cerr << "Error: illegal number of argument (" << argc << ")!!\n";
        myexit();
    }

    cmd.readCmd();      // press "Ctrl-d" to break
    std::cout << '\n';  // a blank line between each command

    return 0;
}
