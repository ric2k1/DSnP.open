/****************************************************************************
  FileName     [ taskCmd.cpp ]
  PackageName  [ task ]
  Synopsis     [ Define task package commands ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2014-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#include <cassert>
#include <iostream>
#include <iomanip>
#include "taskMgr.h"
#include "taskCmd.h"
#include "util.h"

using namespace std;

extern TaskMgr* taskMgr;

bool
initTaskCmd()
{
   if (!(cmdMgr->regCmd("TASKInit", 5, new TaskInitCmd) &&
         cmdMgr->regCmd("TASKNew", 5, new TaskNewCmd) &&
         cmdMgr->regCmd("TASKRemove", 5, new TaskRemoveCmd) &&
         cmdMgr->regCmd("TASKQuery", 5, new TaskQueryCmd) &&
         cmdMgr->regCmd("TASKAssign", 5, new TaskAssignCmd)
      )) {
      cerr << "Registering \"task\" commands fails... exiting" << endl;
      return false;
   }
   return true;
}

//----------------------------------------------------------------------
//    TASKInit <(size_t numMachines)>
//----------------------------------------------------------------------
CmdExecStatus
TaskInitCmd::exec(const string& option)
{
   // check option
   string token;
   if (!CmdExec::lexSingleOption(option, token, false))
      return CMD_EXEC_ERROR;
   int numMachines;
   if (!myStr2Int(token, numMachines) || numMachines <= 0)
      return CmdExec::errorOption(CMD_OPT_ILLEGAL, token);
   if (taskMgr) {
      cout << "Warning: Deleting task manager..." << endl;
      delete taskMgr;
   }
   taskMgr = new TaskMgr(numMachines);
   cout << "Task manager is initialized (" << numMachines << ")" << endl;
   return CMD_EXEC_DONE;
}

void
TaskInitCmd::usage(ostream& os) const
{
   os << "Usage: TASKInit <(size_t numMachines)>" << endl;
}

void
TaskInitCmd::help() const
{
   cout << setw(15) << left << "TASKInit: "
        << "Initialize task manager" << endl;
}

//----------------------------------------------------------------------
//    TASKNew <-Random (size_t numMachines) |
//             -Name (string name) (size_t load)>
//----------------------------------------------------------------------
CmdExecStatus
TaskNewCmd::exec(const string& option)
{
   if (!taskMgr) {
      cerr << "Error: task manager is not initialized!" << endl;
      return CMD_EXEC_ERROR;
   }
   // check option
   vector<string> options;
   if (!CmdExec::lexOptions(option, options))
      return CMD_EXEC_ERROR;
   if (options.empty())
      return CmdExec::errorOption(CMD_OPT_MISSING, "");

   bool doRandom = false, doName = false;
   int numMachines, load;
   string name;
   for (size_t i = 0, n = options.size(); i < n; ++i) {
      if (myStrNCmp("-Random", options[i], 2) == 0) {
         if (doRandom || doName)
            return CmdExec::errorOption(CMD_OPT_EXTRA,options[i]);
         doRandom = true;
	 if (++i >= n)
            return CmdExec::errorOption(CMD_OPT_MISSING,options[i-1]);
         if (!myStr2Int(options[i], numMachines) || numMachines <= 0)
            return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[i]);
      }
      else if (myStrNCmp("-Name", options[i], 2) == 0) {
         if (doRandom || doName)
            return CmdExec::errorOption(CMD_OPT_EXTRA,options[i]);
         doName = true;
	 if (++i >= n)
            return CmdExec::errorOption(CMD_OPT_MISSING,options[i-1]);
         if (!isValidVarName(options[i]))
            return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[i]);
         name = options[i];
	 if (++i >= n)
            return CmdExec::errorOption(CMD_OPT_MISSING,options[i-1]);
         if (!myStr2Int(options[i], load) || load <= 0)
            return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[i]);
      }
      else
         return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[i]);
   }

   if (doRandom) {
      taskMgr->add(numMachines);
      cout << "... " << numMachines << " new task nodes are added." << endl;
   }
   else { // doName
      assert(doName); 
      if (!taskMgr->add(name, load))
         cerr << "Error: Task node (" << name << ") already exists.\n";
   }
   return CMD_EXEC_DONE;
}

void
TaskNewCmd::usage(ostream& os) const
{
   os << "Usage: TASKNew <-Random (size_t numMachines) |\n"
      << "                -Name (string name) (size_t load)>" << endl;
}

void
TaskNewCmd::help() const
{
   cout << setw(15) << left << "TASKNew: "
        << "Add new task nodes" << endl;
}

//----------------------------------------------------------------------
//    TASKRemove <-Random (size_t numMachines) | -Name (string name)>
//----------------------------------------------------------------------
CmdExecStatus
TaskRemoveCmd::exec(const string& option)
{
   if (!taskMgr) {
      cerr << "Error: task manager is not initialized!" << endl;
      return CMD_EXEC_ERROR;
   }
   // check option
   vector<string> options;
   if (!CmdExec::lexOptions(option, options, 2))
      return CMD_EXEC_ERROR;

   if (myStrNCmp("-Random", options[0], 2) == 0) {
      int numMachines;
      if (!myStr2Int(options[1], numMachines) || numMachines <= 0)
         return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[1]);
      int n = taskMgr->size();
      if (numMachines < n) {
         taskMgr->remove(numMachines);
         cout << "... " << numMachines << " task nodes are removed." << endl;
      }
      else {
         taskMgr->clear();
         if (numMachines > n)
            cerr << "Warning: specified number (" << numMachines << ") is"
                 << " greater than the number of task nodes!!" << endl;
         cout << "... All the task nodes are removed." << endl;
      }
   }
   else if (myStrNCmp("-Name", options[0], 2) == 0) {
      if (!isValidVarName(options[1]))
         return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[1]);
      if (!taskMgr->remove(options[1]))
         cerr << "Error: Task node (" << options[1] << ") does not exist.\n";
   }
   else
      return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[0]);

   return CMD_EXEC_DONE;
}

void
TaskRemoveCmd::usage(ostream& os) const
{
   os << "Usage: TASKRemove <-Random (size_t numMachines) |"
      << " -Name (string name)>" << endl;
}

void
TaskRemoveCmd::help() const
{
   cout << setw(15) << left << "TASKRemove: "
        << "Remove existing task nodes" << endl;
}

//----------------------------------------------------------------------
//    TASKQuery <(string name) | -HAsh | -HEap | -MINimum >
//----------------------------------------------------------------------
CmdExecStatus
TaskQueryCmd::exec(const string& option)
{
   if (!taskMgr) {
      cerr << "Error: task manager is not initialized!" << endl;
      return CMD_EXEC_ERROR;
   }
   // check option
   string token;
   if (!CmdExec::lexSingleOption(option, token, false))
      return CMD_EXEC_ERROR;
   if (myStrNCmp("-HAsh", token, 3) == 0) {
      taskMgr->printAllHash();
      cout << "Number of tasks: " << taskMgr->size() << endl;
   }
   // hidden option
   else if (myStrNCmp("-HEap", token, 3) == 0) {
      taskMgr->printAllHeap();
      cout << "Number of tasks: " << taskMgr->size() << endl;
   }
   else if (myStrNCmp("-MINimum", token, 4) == 0) {
      if (taskMgr->empty()) {
         cerr << "Error: task manager is empty!" << endl;
         return CMD_EXEC_ERROR;
      }
      cout << "Min task node: " << taskMgr->min() << endl;
   }
   else if (isValidVarName(token)) {
      TaskNode n(token, 0);
      if (taskMgr->query(n)) { cout << "Query succeeds: " << n << endl; }
      else cerr << "Query fails!" << endl;
   }
   else
      return CmdExec::errorOption(CMD_OPT_ILLEGAL, token);
   return CMD_EXEC_DONE;
}

void
TaskQueryCmd::usage(ostream& os) const
{
   os << "Usage: TASKQuery <(string name) | -HAsh | -HEap | -MINimum >"
      << endl;
}

void
TaskQueryCmd::help() const
{
   cout << setw(15) << left << "TASKQuery: "
        << "Query task manager" << endl;
}

//----------------------------------------------------------------------
//    TASKAssign <(size_t load)> [-Repeat (size_t repeats)]
//----------------------------------------------------------------------
CmdExecStatus
TaskAssignCmd::exec(const string& option)
{
   if (!taskMgr) {
      cerr << "Error: task manager is not initialized!" << endl;
      return CMD_EXEC_ERROR;
   }
   // check option
   vector<string> options;
   if (!CmdExec::lexOptions(option, options))
      return CMD_EXEC_ERROR;
   if (options.empty())
      return CmdExec::errorOption(CMD_OPT_MISSING, "");

   bool doRepeat = false;
   int load = -1, repeats;
   for (size_t i = 0, n = options.size(); i < n; ++i) {
      if (myStrNCmp("-Repeat", options[i], 2) == 0) {
         if (doRepeat) return CmdExec::errorOption(CMD_OPT_EXTRA,options[i]);
	 if (++i >= n)
            return CmdExec::errorOption(CMD_OPT_MISSING,options[i-1]);
         if (!myStr2Int(options[i], repeats) || repeats <= 0)
            return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[i]);
         doRepeat = true;
      }
      else {
         if (load != -1)
            return CmdExec::errorOption(CMD_OPT_EXTRA,options[i]);
         if (!myStr2Int(options[i], load) || load <= 0)
            return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[i]);
      }
   }
   if (load == -1)
      return CmdExec::errorOption(CMD_OPT_MISSING, "");

   if (!doRepeat) repeats = 1;
   for (int i = 0; i < repeats; ++i) {
      if (taskMgr->assign(load))
         cout << "Task assignment succeeds..." << endl
              << "Updating min: " << taskMgr->min() << endl;
      else cerr << "Task assignment fails!" << endl;
   }
   return CMD_EXEC_DONE;
}

void
TaskAssignCmd::usage(ostream& os) const
{
   os << "Usage: TASKAssign <(size_t load)> [-Repeat (size_t repeats)]\n";
}

void
TaskAssignCmd::help() const
{
   cout << setw(15) << left << "TASKAssign: "
        << "Assign load to the minimum task node(s)\n";
}

