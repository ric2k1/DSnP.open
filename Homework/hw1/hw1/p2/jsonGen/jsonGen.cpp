/****************************************************************************
  FileName     [ jsonGen.cpp ]
  PackageName  [ jsonGen ]
  Synopsis     [ JSON file generator ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <set>
#include "rnGen.h"

using namespace std;

RandomNumGen rnGen;
bool myStr2Int(const string& str, int& num);

int main(int argc, char **argv)
{
   // Usage: jgen <numElements>
   int numElms = 0;
   if (argc == 2) {
      if (!myStr2Int(string(argv[1]), numElms)) {
         cerr << "Error: " << argv[1] << " is not a valid number!!" << endl;
         exit (-1);
      }
   }
   else if (argc > 2) {
      cerr << "Error: extra argument (" << argv[2] << ")!!" << endl;
      exit (-1);
   }
   else {
      cerr << "Error: missing argument." << endl
           << "Please use \"jgen <numElements>\"" << endl;
      exit (-1);
   }

   set<string> nameCheck;
   cout << "{" << endl;
   for (int i = 0; i < numElms; ++i) {
      string str;
      do {
         int len = rnGen(9)+1;
         for (int j = 0; j < len; ++j) str += (rnGen(26) + 'a');
      } while (nameCheck.find(str) != nameCheck.end());
      nameCheck.insert(str);
      cout << "  \"" << str << "\" : " << rnGen(1999)-999;
      if (i != (numElms - 1)) cout << ",";
      cout << endl;
   }
   cout << "}" << endl;
}

bool
myStr2Int(const string& str, int& num)
{
   num = 0;
   size_t i = 0;
   int sign = 1;
   if (str[0] == '-') { sign = -1; i = 1; }
   bool valid = false;
   for (; i < str.size(); ++i) {
      if (isdigit(str[i])) {
         num *= 10;
         num += int(str[i] - '0');
         valid = true;
      }
      else return false;
   }
   num *= sign;
   return valid;
}

