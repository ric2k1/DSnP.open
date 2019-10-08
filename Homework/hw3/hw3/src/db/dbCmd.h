/****************************************************************************
  FileName     [ dbCmd.h ]
  PackageName  [ db ]
  Synopsis     [ Define database command classes ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2015-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/
#ifndef DB_CMD_H
#define DB_CMD_H

#include "cmdParser.h"

CmdClass(DBAppendCmd);
CmdClass(DBAveCmd);
CmdClass(DBCountCmd);
CmdClass(DBMaxCmd);
CmdClass(DBMinCmd);
CmdClass(DBPrintCmd);
CmdClass(DBReadCmd);
CmdClass(DBSortCmd);
CmdClass(DBSumCmd);

#endif // DB_CMD_H

