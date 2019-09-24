/****************************************************************************
  FileName     [ testAsc.cpp ]
  PackageName  [ N/A ]
  Synopsis     [ To test your keyboard mapping ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2007-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
#include <iomanip>
#include <cassert>
#include "cmdCharDef.h"

using namespace std;

//----------------------------------------------------------------------
//    External funcitons
//----------------------------------------------------------------------
void mybeep();
char mygetc(istream&);
ParseChar getChar(istream&);

//----------------------------------------------------------------------
//    Global static funcitons
//----------------------------------------------------------------------
int main()
{
   char ch;
   cout << "Press \"Ctrl-d\" to quit" << endl;
   while (1) {
      ParseChar pch = getChar(cin);
      if (pch == INPUT_END_KEY) {
         cout << "Input end" << endl;
         break;
      }
      switch (pch) {
         case LINE_BEGIN_KEY: cout << "Line begin" << endl; break;
         case LINE_END_KEY:   cout << "Line end" << endl; break;
         case HOME_KEY:       cout << "Home key" << endl; break;
         case END_KEY:        cout << "End key" << endl; break;
         case BACK_SPACE_KEY: cout << "Backspace" << endl; break;
         case DELETE_KEY:     cout << "Delete" << endl; break;
         case INSERT_KEY:     cout << "Insert" << endl; break;
         case NEWLINE_KEY:    cout << "New line" << endl; break;
         case TAB_KEY:        cout << "Tab key" << endl; break;
         case ARROW_UP_KEY:   cout << "Arrow up" << endl; break;
         case ARROW_DOWN_KEY: cout << "Arrow down" << endl; break;
         case ARROW_RIGHT_KEY:cout << "Arrow right" << endl; break;
         case ARROW_LEFT_KEY: cout << "Arrow left" << endl; break;
         case PG_UP_KEY:      cout << "Page up" << endl; break;
         case PG_DOWN_KEY:    cout << "Page down" << endl; break;
         case UNDEFINED_KEY:  cout << "<Undefined>!!" << endl; mybeep(); break;
         default:             cout << char(pch) << endl; break;
                              // printable character
      }
   }
}
