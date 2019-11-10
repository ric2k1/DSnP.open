/****************************************************************************
  FileName     [ array.h ]
  PackageName  [ util ]
  Synopsis     [ Define dynamic array package ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2005-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>
#include <algorithm>

using namespace std;

// NO need to implement class ArrayNode
//
template <class T>
class Array
{
public:
   // TODO: decide the initial value for _isSorted
   Array() : _data(0), _size(0), _capacity(0) {}
   ~Array() { delete []_data; }

   // DO NOT add any more data member or function for class iterator
   class iterator
   {
      friend class Array;

   public:
      iterator(T* n= 0): _node(n) {}
      iterator(const iterator& i): _node(i._node) {}
      ~iterator() {} // Should NOT delete _node

      // TODO: implement these overloaded operators
      const T& operator * () const { return (*this); }
      T& operator * () { return (*_node); }
      iterator& operator ++ () { return (*this); }
      iterator operator ++ (int) { return (*this); }
      iterator& operator -- () { return (*this); }
      iterator operator -- (int) { return (*this); }

      iterator operator + (int i) const { return (*this); }
      iterator& operator += (int i) { return (*this); }

      iterator& operator = (const iterator& i) { return (*this); }

      bool operator != (const iterator& i) const { return false; }
      bool operator == (const iterator& i) const { return false; }

   private:
      T*    _node;
   };

   // TODO: implement these functions
   iterator begin() const { return 0; }
   iterator end() const { return 0; }
   bool empty() const { return false; }
   size_t size() const { return 0; }

   T& operator [] (size_t i) { return _data[0]; }
   const T& operator [] (size_t i) const { return _data[0]; }

   void push_back(const T& x) { }
   void pop_front() { }
   void pop_back() { }

   bool erase(iterator pos) { return false; }
   bool erase(const T& x) { return false; }

   iterator find(const T& x) { return end(); }

   void clear() { }

   // [Optional TODO] Feel free to change, but DO NOT change ::sort()
   void sort() const { if (!empty()) ::sort(_data, _data+_size); }

   // Nice to have, but not required in this homework...
   // void reserve(size_t n) { ... }
   // void resize(size_t n) { ... }

private:
   // [NOTE] DO NOT ADD or REMOVE any data member
   T*            _data;
   size_t        _size;       // number of valid elements
   size_t        _capacity;   // max number of elements
   mutable bool  _isSorted;   // (optionally) to indicate the array is sorted

   // [OPTIONAL TODO] Helper functions; called by public member functions
};

#endif // ARRAY_H
