cirCmd.o: cirCmd.cpp cirMgr.h cirDef.h cirGate.h cirCmd.h \
 ../../include/cmdParser.h ../../include/cmdCharDef.h \
 ../../include/util.h ../../include/rnGen.h ../../include/myUsage.h
cirGate.o: cirGate.cpp cirGate.h cirDef.h cirMgr.h ../../include/util.h \
 ../../include/rnGen.h ../../include/myUsage.h
cirMgr.o: cirMgr.cpp cirMgr.h cirDef.h cirGate.h ../../include/util.h \
 ../../include/rnGen.h ../../include/myUsage.h
