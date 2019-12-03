/****************************************************************************
  FileName     [ taskCmd.h ]
  PackageName  [ task ]
  Synopsis     [ Define task package commands ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2014-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#ifndef TASK_CMD_H
#define TASK_CMD_H

#include "cmdParser.h"

CmdClass(TaskInitCmd);
CmdClass(TaskNewCmd);
CmdClass(TaskRemoveCmd);
CmdClass(TaskQueryCmd);
CmdClass(TaskAssignCmd);

#endif // TASK_CMD_H

