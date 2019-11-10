/****************************************************************************
  FileName     [ adtTest.h ]
  PackageName  [ main ]
  Synopsis     [ Define AdtTest class and commands ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2007-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/
#ifndef ADT_TEST_H
#define ADT_TEST_H

#include <iostream>
#include <string>
#include "cmdParser.h"


using namespace std;

//----------------------------------------------------------------------
//    Type define for linear ADT test program
//----------------------------------------------------------------------

#if defined  TEST_DLIST

      #undef   TEST_ARRAY
      #undef   TEST_BST
      #undef   RANDOM_ACCESS

      #define  ADT         "dlist"
      #define  AdtType     DList

      #include "dlist.h"

#elif defined  TEST_ARRAY

      #undef   TEST_DLIST
      #undef   TEST_BST
      #define  RANDOM_ACCESS

      #define  ADT         "array"
      #define  AdtType     Array

      #include "array.h"

#elif defined  TEST_BST

      #undef   TEST_DLIST
      #undef   TEST_ARRAY
      #undef   RANDOM_ACCESS

      #define  ADT         "bst"
      #define  AdtType     BSTree

      #include "bst.h"

#endif // TEST_DLIST


//----------------------------------------------------------------------
//    Classes for ADT test program
//----------------------------------------------------------------------
class AdtTestObj
{
public:
   AdtTestObj();
   AdtTestObj(const string& s)
   : _str(s) { if (int(_str.size()) > _strLen) _str.resize(_strLen); }
   AdtTestObj(const AdtTestObj& o) : _str(o._str) {}

   bool operator == (const AdtTestObj& o) const { return (_str == o._str); }
   bool operator != (const AdtTestObj& o) const { return (_str != o._str); }
   bool operator < (const AdtTestObj& o) const { return (_str < o._str); }
   bool operator <= (const AdtTestObj& o) const { return (_str <= o._str); }
   bool operator > (const AdtTestObj& o) const { return (_str > o._str); }
   bool operator >= (const AdtTestObj& o) const { return (_str >= o._str); }

   static void setLen(int len) { _strLen = len; }
   static int getLen() { return _strLen; }

   friend ostream& operator << (ostream& os, const AdtTestObj& o);

private:
   string      _str;  // _str.length() should alywas <= _strLen
   static int  _strLen;
};

class AdtTest
{
#define N 4  // number of AdtTestObj printed per line

public:
   void reset(int len) { deleteAll(); AdtTestObj::setLen(len); }

   size_t size() const { return _container.size(); }

   void add(const AdtTestObj& o) {
      #ifdef TEST_BST
      _container.insert(o);
      #else
      _container.push_back(o);
      #endif
   }
   void add() { add(AdtTestObj()); }

   void deleteAll() { _container.clear(); }
   bool deleteObj(const AdtTestObj& o) { return _container.erase(o); }
   void deleteFront(size_t repeat = 1) {
      for (size_t i = 0; i < repeat; ++i) _container.pop_front(); }
   void deleteBack(size_t repeat = 1) {
      for (size_t i = 0; i < repeat; ++i) _container.pop_back(); }
   void deleteRandom(size_t repeat = 1) {
      size_t s = _container.size();
      for (size_t i = 0; i < repeat; ++i) {
         size_t pos = rnGen(s);
         if (_container.erase(getPos(pos))) --s;
      }
   }

   // return true if FOUND
   bool find(const AdtTestObj& n) {
      AdtType<AdtTestObj>::iterator li = _container.find(n);
      return (li != _container.end());
   }

   void sort() { _container.sort(); }

   void print(bool reverse = false, bool verbose = false) const {
      #ifdef TEST_BST
      if (verbose)
         _container.print();  // for BST only
      #endif
      cout << "=== ADT (" << ADT << ") ===" << endl;
      if (reverse) printBackward();
      else printForward();
      cout << endl;
   }

   // DO nothing if index is invalid
   void printData(size_t index) const {
      AdtType<AdtTestObj>::iterator li = getPos(index);
      if (li != _container.end())
         printData(index, li, index%N);
   }

private:
   AdtType<AdtTestObj>   _container;

   // private functions
   // return end() if 'pos' passes the end
   AdtType<AdtTestObj>::iterator getPos(size_t pos) const {
      #ifdef RANDOM_ACCESS
         if (pos >= _container.size()) return _container.end();
         return (_container.begin() + pos);
      #else
         size_t i = 0;
         AdtType<AdtTestObj>::iterator li = _container.begin();
         AdtType<AdtTestObj>::iterator lj = _container.end();
         while ((li != lj) && (i++ != pos)) ++li;
         return li;
      #endif // RANDOM_ACCESS
   }
   void printForward() const {
      size_t idx = 0;
      AdtType<AdtTestObj>::iterator li = _container.begin();
      for (; li != _container.end(); ++li)
         printData(idx++, li, N-1);
   }
   void printBackward() const {
      if (_container.empty()) return;
      size_t idx = _container.size() - 1;
      size_t r = (idx + 1) % N;
      AdtType<AdtTestObj>::iterator li = _container.end(); --li;
      #ifdef RANDOM_ACCESS
         for (int i = idx; i >= 0; --i)
            printData(idx--, li--, r);
      #else // for DList and BST
         do {
            printData(idx, li, r);
            --idx;
         } while (li-- != _container.begin());
      #endif // RANDOM_ACCESS
   }
   void printData(size_t idx, AdtType<AdtTestObj>::iterator li,
                  size_t r) const {
      cout << "[" << setw(3) << right << idx << "] = "
           << setw(3) << right << *li << "   ";
      if (idx % N == r) cout << endl;
   }
};


//----------------------------------------------------------------------
//    Classes for linear ADT test commands
//----------------------------------------------------------------------
CmdClass(AdtResetCmd);
CmdClass(AdtAddCmd);
CmdClass(AdtDeleteCmd);
CmdClass(AdtQueryCmd);
CmdClass(AdtSortCmd);
CmdClass(AdtPrintCmd);

#endif // ADT_TEST_H
