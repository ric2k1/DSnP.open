/****************************************************************************
  FileName     [ util.cpp ]
  PackageName  [ util ]
  Synopsis     [ Define global utility functions ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2017-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// List all the file names under "dir" with prefix "prefix"
// Ignore "." and ".."
//
int listDir
(vector<string>& files, const string& prefix, const string& dir = ".")
{
   DIR *dp;
   dirent *dirp;
   if ((dp = opendir(dir.c_str())) == NULL) {
      cerr << "Error(" << errno << "): failed to open " << dir << "!!\n";
      return errno;
   }

   const char *pp = prefix.size()? prefix.c_str(): 0;
   while ((dirp = readdir(dp)) != NULL) {
      if (string(dirp->d_name) == "." ||
          string(dirp->d_name) == "..") continue;
      if (!pp || strncmp(dirp->d_name, pp, prefix.size()) == 0)
         files.push_back(string(dirp->d_name));
   }
   sort(files.begin(), files.end());
   closedir(dp);
   return 0;
}
