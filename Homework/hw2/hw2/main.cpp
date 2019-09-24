/****************************************************************************
  FileName     [ main.cpp ]
  PackageName  [ main ]
  Synopsis     [ Define main() function ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2007-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/
#include <string.h>
#include <cstdlib>
#include <cassert>
#include "cmdParser.h"

using namespace std;

static void
usage()
{
   cout << "Usage: cmdReader [ -File < doFile > ]" << endl;
}

static void
myexit()
{
   usage();
   exit(-1);
}

static int
myStrNCmp(const string& s1, const string& s2, unsigned n)
{
   assert(n > 0);
   unsigned n2 = s2.size();
   if (n2 == 0) return -1;
   unsigned n1 = s1.size();
   assert(n1 >= n);
   for (unsigned i = 0; i < n1; ++i) {
      if (i == n2)
         return (i < n)? 1 : 0;
      char ch1 = (isupper(s1[i]))? tolower(s1[i]) : s1[i];
      char ch2 = (isupper(s2[i]))? tolower(s2[i]) : s2[i];
      if (ch1 != ch2)
         return (ch1 - ch2);
   }
   return (n1 - n2);
}

int
main(int argc, char** argv)
{
   CmdParser cmd;
   ifstream dof;

   if (argc == 3) {  // -File <doFile>
      if (myStrNCmp("-File", argv[1], 2) == 0) {
         if (!cmd.openDofile(argv[2])) {
            cerr << "Error: cannot open file \"" << argv[2] << "\"!!\n";
            myexit();
         }
      }
      else {
         cerr << "Error: unknown argument \"" << argv[1] << "\"!!\n";
         myexit();
      }
   }
   else if (argc != 1) {
      cerr << "Error: illegal number of argument (" << argc << ")!!\n";
      myexit();
   }

   cmd.readCmd();  // press "Ctrl-d" to break
   cout << endl;  // a blank line between each command

   return 0;
}
