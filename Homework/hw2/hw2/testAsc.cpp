/****************************************************************************
  FileName     [ testAsc.cpp ]
  PackageName  [ test ]
  Synopsis     [ Test ASCII code ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2007-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/
#include "cmdCharDef.h"

#include <iostream>

int main()
{
    std::cout << "Press \"Ctrl-d\" to quit\n";
    while (true) {
        const ParseChar parseChar = getChar(std::cin);
        if (parseChar == INPUT_END_KEY) {
            std::cout << "Input end\n";
            break;
        }
        if (parseChar == LINE_BEGIN_KEY) {
            std::cout << "Line begin\n";
        }
        else if (parseChar == LINE_END_KEY) {
            std::cout << "Line end\n";
        }
        else if (parseChar == HOME_KEY) {
            std::cout << "Home key\n";
        }
        else if (parseChar == END_KEY) {
            std::cout << "End key\n";
        }
        else if (parseChar == BACK_SPACE_KEY) {
            std::cout << "Backspace\n";
        }
        else if (parseChar == DELETE_KEY) {
            std::cout << "Delete\n";
        }
        else if (parseChar == INSERT_KEY) {
            std::cout << "Insert\n";
        }
        else if (parseChar == NEWLINE_KEY) {
            std::cout << "New line\n";
        }
        else if (parseChar == TAB_KEY) {
            std::cout << "Tab key\n";
        }
        else if (parseChar == ARROW_UP_KEY) {
            std::cout << "Arrow up\n";
        }
        else if (parseChar == ARROW_DOWN_KEY) {
            std::cout << "Arrow down\n";
        }
        else if (parseChar == ARROW_RIGHT_KEY) {
            std::cout << "Arrow right\n";
        }
        else if (parseChar == ARROW_LEFT_KEY) {
            std::cout << "Arrow left\n";
        }
        else if (parseChar == PG_UP_KEY) {
            std::cout << "Page up\n";
        }
        else if (parseChar == PG_DOWN_KEY) {
            std::cout << "Page down\n";
        }
        else if (parseChar == UNDEFINED_KEY) {
            std::cout << "<Undefined>!!\n";
        }
        else {
            std::cout << static_cast<char>(parseChar) << '\n';
        }
    }
    return 0;
}
