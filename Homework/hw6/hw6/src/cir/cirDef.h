/****************************************************************************
  FileName     [ cirDef.h ]
  PackageName  [ cir ]
  Synopsis     [ Define basic data or var for cir package ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2010-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#ifndef CIR_DEF_H
#define CIR_DEF_H

#include <vector>

using namespace std;

class CirGate;
class CirMgr;

typedef vector<CirGate*>           GateList;
typedef vector<unsigned>           IdList;

enum GateType
{
   UNDEF_GATE = 0,
   PI_GATE    = 1,
   PO_GATE    = 2,
   AIG_GATE   = 3,
   CONST_GATE = 4,

   TOT_GATE
};

#endif // CIR_DEF_H
