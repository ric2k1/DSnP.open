/****************************************************************************
  FileName     [ taskMgr.h ]
  PackageName  [ task ]
  Synopsis     [ Header file for task Manager ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2014-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#ifndef TASK_MGR
#define TASK_MGR

#include <iostream>
#include <string>
#include "myHashSet.h"
#include "myMinHeap.h"

using namespace std;

class TaskNode
{
#define NAME_LEN  6
#define LOAD_RN   20000

public:
   TaskNode();
   TaskNode(const string& n, size_t l) : _name(n), _load(l) {}
   ~TaskNode() {}

   void operator += (size_t l) { _load += l; }
   bool operator == (const TaskNode& n) const { return _name == n._name; }
   bool operator < (const TaskNode& n) const { return _load < n._load; }
   size_t operator () () const;

   const string& getName() const { return _name; }
   size_t getLoad() const { return _load; }

   friend ostream& operator << (ostream& os, const TaskNode& n);

private:
   string   _name;
   size_t   _load;
};

class TaskMgr
{
public:
   TaskMgr(size_t nMachines);
   ~TaskMgr() {}

   void clear();

   size_t size() const { return _taskHeap.size(); }
   bool empty() { return size() == 0; }

   const TaskNode& min() const { return _taskHeap.min(); }
   void add(size_t nMachines);
   bool add(const string&, size_t);
   void remove(size_t nMachines);
   bool remove(const string&);
   bool assign (size_t l);
   bool query(TaskNode& n) { return _taskHash.query(n); }
   void printAllHash() const;
   void printAllHeap() const;

private:
   MinHeap<TaskNode>   _taskHeap;
   HashSet<TaskNode>   _taskHash;
};

#endif // TASK_MGR
