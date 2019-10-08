/****************************************************************************
  FileName     [ dbJson.h ]
  PackageName  [ db ]
  Synopsis     [ Define database JSON classes ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2015-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/
#ifndef DB_JSON_H
#define DB_JSON_H

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

struct DBSortKey;
struct DBSortValue;

class DBJsonElem
{
public:
   // TODO: define constructor & member functions on your own
   DBJsonElem() {}
   DBJsonElem(const string& k, int v): _key(k), _value(v) {}

   const string& key() const { return _key; }
   string& key() { return _key; }
   const int& value() const { return _value; }
   int& value() { return _value; }

   friend ostream& operator << (ostream&, const DBJsonElem&);

private:
   string  _key;   // DO NOT change this definition. Use it to store key.
   int     _value; // DO NOT change this definition. Use it to store value.
};

class DBJson
{
public:
   // TODO: define constructor & member functions on your own
   DBJson() {}
   bool add(const DBJsonElem&); // return false if key is repeated
   float ave() const;
   int max(size_t&) const;
   int min(size_t&) const;
   void sort(const DBSortKey&);
   void sort(const DBSortValue&);
   int sum() const;

   // Basic access functions
   void reset();
   size_t size() const { return _obj.size(); }
   bool empty() const { return _obj.empty(); }
   DBJsonElem& operator [] (size_t i) { return _obj[i]; }
   const DBJsonElem& operator [] (size_t i) const { return _obj[i]; }

   // TODO modify these two functions according to the comments
   // return true if JSON file hasn't been read in
   bool operator !() { return false; }
   // return this if JSON file has been read in; return NLL if not.
   operator void* () const { return NULL; }

   // Read DBJson
   friend istream& operator >> (istream& is, DBJson& j);
   friend ostream& operator << (ostream& os, const DBJson& j);

private:
   vector<DBJsonElem>       _obj;  // DO NOT change this definition.
                                   // Use it to store JSON elements.
};

struct DBSortKey
{
   bool operator() (const DBJsonElem& m1, const DBJsonElem& m2) const {
      return (m1.key() < m2.key());
   }
};

struct DBSortValue
{
   bool operator() (const DBJsonElem& m1, const DBJsonElem& m2) const {
      return (m1.value() < m2.value());
   }
};

#endif // DB_JSON_H
