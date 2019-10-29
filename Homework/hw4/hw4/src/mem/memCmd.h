/****************************************************************************
  FileName     [ memCmd.h ]
  PackageName  [ mem ]
  Synopsis     [ Define memory test command classes ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2007-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/
#ifndef MEM_CMD_H
#define MEM_CMD_H

#include "cmdParser.h"

CmdClass(MTResetCmd);
CmdClass(MTNewCmd);
CmdClass(MTDeleteCmd);
CmdClass(MTPrintCmd);

#endif // MEM_CMD_H
