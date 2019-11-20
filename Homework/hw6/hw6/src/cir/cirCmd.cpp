/****************************************************************************
  FileName     [ cirCmd.cpp ]
  PackageName  [ cir ]
  Synopsis     [ Define basic cir package commands ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2008-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#include <cassert>
#include <iostream>
#include <iomanip>
#include "cirMgr.h"
#include "cirGate.h"
#include "cirCmd.h"
#include "util.h"

using namespace std;

extern CirMgr* cirMgr;

bool
initCirCmd()
{
   if (!(cmdMgr->regCmd("CIRRead", 4, new CirReadCmd) &&
         cmdMgr->regCmd("CIRPrint", 4, new CirPrintCmd) &&
         cmdMgr->regCmd("CIRGate", 4, new CirGateCmd) &&
         cmdMgr->regCmd("CIRWrite", 4, new CirWriteCmd)
      )) {
      cerr << "Registering \"cir\" commands fails... exiting" << endl;
      return false;
   }
   return true;
}

enum CirCmdState
{
   // Order matters! Do not change the order!!
   CIRINIT,
   CIRREAD,
   // dummy end
   CIRCMDTOT
};

static CirCmdState curCmd = CIRINIT;

//----------------------------------------------------------------------
//    CIRRead <(string fileName)> [-Replace]
//----------------------------------------------------------------------
CmdExecStatus
CirReadCmd::exec(const string& option)
{
   // check option
   vector<string> options;
   if (!CmdExec::lexOptions(option, options))
      return CMD_EXEC_ERROR;
   if (options.empty())
      return CmdExec::errorOption(CMD_OPT_MISSING, "");

   bool doReplace = false;
   string fileName;
   for (size_t i = 0, n = options.size(); i < n; ++i) {
      if (myStrNCmp("-Replace", options[i], 2) == 0) {
         if (doReplace) return CmdExec::errorOption(CMD_OPT_EXTRA,options[i]);
         doReplace = true;
      }
      else {
         if (fileName.size())
            return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[i]);
         fileName = options[i];
      }
   }

   if (cirMgr != 0) {
      if (doReplace) {
         cerr << "Note: original circuit is replaced..." << endl;
         curCmd = CIRINIT;
         delete cirMgr; cirMgr = 0;
      }
      else {
         cerr << "Error: circuit already exists!!" << endl;
         return CMD_EXEC_ERROR;
      }
   }
   cirMgr = new CirMgr;

   if (!cirMgr->readCircuit(fileName)) {
      curCmd = CIRINIT;
      delete cirMgr; cirMgr = 0;
      return CMD_EXEC_ERROR;
   }

   curCmd = CIRREAD;

   return CMD_EXEC_DONE;
}

void
CirReadCmd::usage(ostream& os) const
{
   os << "Usage: CIRRead <(string fileName)> [-Replace]" << endl;
}

void
CirReadCmd::help() const
{
   cout << setw(15) << left << "CIRRead: "
        << "read in a circuit and construct the netlist" << endl;
}

//----------------------------------------------------------------------
//    CIRPrint [-Summary | -Netlist | -PI | -PO | -FLoating ]
//----------------------------------------------------------------------
CmdExecStatus
CirPrintCmd::exec(const string& option)
{
   // check option
   string token;
   if (!CmdExec::lexSingleOption(option, token))
      return CMD_EXEC_ERROR;

   if (!cirMgr) {
      cerr << "Error: circuit is not yet constructed!!" << endl;
      return CMD_EXEC_ERROR;
   }
   if (token.empty() || myStrNCmp("-Summary", token, 2) == 0)
      cirMgr->printSummary();
   else if (myStrNCmp("-Netlist", token, 2) == 0)
      cirMgr->printNetlist();
   else if (myStrNCmp("-PI", token, 3) == 0)
      cirMgr->printPIs();
   else if (myStrNCmp("-PO", token, 3) == 0)
      cirMgr->printPOs();
   else if (myStrNCmp("-FLoating", token, 3) == 0)
      cirMgr->printFloatGates();
/*
   else if (myStrNCmp("-FECpairs", token, 4) == 0)
      cirMgr->printFECPairs();
*/
   else
      return CmdExec::errorOption(CMD_OPT_ILLEGAL, token);

   return CMD_EXEC_DONE;
}

void
CirPrintCmd::usage(ostream& os) const
{  
   os << "Usage: CIRPrint [-Summary | -Netlist | -PI | -PO | -FLoating]"
      << endl;
//   os << "Usage: CIRPrint [-Summary | -Netlist | -PI | -PO | -FLoating "
//      << "| -FECpairs]" << endl;
}

void
CirPrintCmd::help() const
{  
   cout << setw(15) << left << "CIRPrint: " << "print circuit\n";
}

//----------------------------------------------------------------------
//    CIRGate <<(int gateId)> [<-FANIn | -FANOut><(int level)>]>
//----------------------------------------------------------------------
CmdExecStatus
CirGateCmd::exec(const string& option)
{
   if (!cirMgr) {
      cerr << "Error: circuit has not been read!!" << endl;
      return CMD_EXEC_ERROR;
   }

   // check option
   vector<string> options;
   if (!CmdExec::lexOptions(option, options))
      return CMD_EXEC_ERROR;

   if (options.empty())
      return CmdExec::errorOption(CMD_OPT_MISSING, "");

   int gateId = -1, level = 0;
   bool doFanin = false, doFanout = false;
   CirGate* thisGate = 0;
   for (size_t i = 0, n = options.size(); i < n; ++i) {
      bool checkLevel = false;
      if (myStrNCmp("-FANIn", options[i], 5) == 0) {
         if (doFanin || doFanout)
            return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[i]);
         doFanin = true;
         checkLevel = true;
      }
      else if (myStrNCmp("-FANOut", options[i], 5) == 0) {
         if (doFanin || doFanout)
            return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[i]);
         doFanout = true;
         checkLevel = true;
      }
      else if (!thisGate) {
         if (!myStr2Int(options[i], gateId) || gateId < 0)
            return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[i]);
         thisGate = cirMgr->getGate(gateId);
         if (!thisGate) {
            cerr << "Error: Gate(" << gateId << ") not found!!" << endl;
            return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[0]);
         }
      }
      else if (thisGate)
         return CmdExec::errorOption(CMD_OPT_EXTRA, options[i]);
      else
         return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[i]);
      if (checkLevel) {
         if (++i == n)
            return CmdExec::errorOption(CMD_OPT_MISSING, options[i-1]);
         if (!myStr2Int(options[i], level) || level < 0)
            return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[i]);
         checkLevel = true;
      }
   }

   if (!thisGate) {
      cerr << "Error: Gate id is not specified!!" << endl;
      return CmdExec::errorOption(CMD_OPT_MISSING, options.back());
   }

   if (doFanin)
      thisGate->reportFanin(level);
   else if (doFanout)
      thisGate->reportFanout(level);
   else
      thisGate->reportGate();

   return CMD_EXEC_DONE;
}

void
CirGateCmd::usage(ostream& os) const
{
   os << "Usage: CIRGate <<(int gateId)> [<-FANIn | -FANOut><(int level)>]>"
      << endl;
}

void
CirGateCmd::help() const
{
   cout << setw(15) << left << "CIRGate: " << "report a gate\n";
}


//----------------------------------------------------------------------
//    CIRWrite [-Output (string aagFile)]
//----------------------------------------------------------------------
CmdExecStatus
CirWriteCmd::exec(const string& option)
{
   if (!cirMgr) {
      cerr << "Error: circuit is not yet constructed!!" << endl;
      return CMD_EXEC_ERROR;
   }
   // check option
   vector<string> options;
   CmdExec::lexOptions(option, options);

   if (options.empty())
      cirMgr->writeAag(cout);
   else if (myStrNCmp("-Output", options[0], 2) == 0) {
      if (options.size() == 1)
         return CmdExec::errorOption(CMD_OPT_MISSING, options[0]);
      if (options.size() > 2)
         return CmdExec::errorOption(CMD_OPT_EXTRA, options[2]);
      ofstream outfile(options[1].c_str(), ios::out);
      if (!outfile)
         return CmdExec::errorOption(CMD_OPT_FOPEN_FAIL, options[1]);
      cirMgr->writeAag(outfile);
   }
   else return CmdExec::errorOption(CMD_OPT_ILLEGAL, options[0]);

   return CMD_EXEC_DONE;
}

void
CirWriteCmd::usage(ostream& os) const
{
   os << "Usage: CIRWrite [-Output (string aagFile)]" << endl;
}

void
CirWriteCmd::help() const
{
   cout << setw(15) << left << "CIRWrite: "
        << "write the netlist to an ASCII AIG file (.aag)\n";
}

