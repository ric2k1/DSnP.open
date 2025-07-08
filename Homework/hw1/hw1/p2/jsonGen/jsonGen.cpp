/****************************************************************************
  FileName     [ jsonGen.cpp ]
  PackageName  [ jsonGen ]
  Synopsis     [ JSON file generator ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include "rnGen.h"

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>

namespace
{
RandomNumGen rnGen;

// C++17: Use std::from_chars for safer string to int conversion
bool myStr2Int(const std::string &str, int &num)
{
    num = 0;
    size_t idx = 0;
    int sign = 1;
    if (str[0] == '-') {
        sign = -1;
        idx = 1;
    }
    bool valid = false;
    for (; idx < str.size(); ++idx) {
        if (std::isdigit(str[idx])) {
            num *= 10;
            num += static_cast<int>(str[idx] - '0');
            valid = true;
        }
        else
            return false;
    }
    num *= sign;
    return valid;
}
}  // anonymous namespace

int main(int argc, char **argv)
{
    // Usage: jgen <numElements>
    int numElms = 0;
    if (argc == 2) {
        if (!myStr2Int(std::string(argv[1]), numElms)) {
            std::cerr << "Error: " << argv[1] << " is not a valid number!!\n";
            std::exit(-1);
        }
    }
    else if (argc > 2) {
        std::cerr << "Error: extra argument (" << argv[2] << ")!!\n";
        std::exit(-1);
    }
    else {
        std::cerr << "Error: missing argument.\n"
                  << "Please use \"jgen <numElements>\"\n";
        std::exit(-1);
    }

    std::set<std::string> nameCheck;
    std::cout << "{\n";

    // C++17: Use structured bindings and modern features
    for (int i = 0; i < numElms; ++i) {
        std::string str;
        do {
            const int len = rnGen(9) + 1;
            // C++17: Use the new generateString method
            str = rnGen.generateString(len);
        } while (nameCheck.find(str) != nameCheck.end());

        nameCheck.insert(str);
        std::cout << "  \"" << str << "\" : " << rnGen(1999) - 999;
        if (i != (numElms - 1))
            std::cout << ",";
        std::cout << '\n';
    }
    std::cout << "}\n";
}
