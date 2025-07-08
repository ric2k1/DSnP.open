#
# This is for your executable
#
CFLAGS = -O3 -std=c++17
CFLAGS = -g -Wall -std=c++17
#
# This is the setting for TA
#
# CFLAGS = -g -Wall -DTA_KB_SETTING -std=c++17
# CFLAGS = -O3 -DTA_KB_SETTING -std=c++17
# CFLAGS = -O3 -m32 -DTA_KB_SETTING -std=c++17

###############
# PHONY rules #
###############
.PHONY : hw2 test ref

hw2 : MAKEFLAGS = $(CFLAGS)
test: MAKEFLAGS = -DTEST_ASC $(CFLAGS)

hw2 : .cmdCharDef cmdReader
test: .cmdCharDef testAsc

##############
# Executable #
##############
cmdReader: main.o cmdReader.o cmdCharDef.o
	g++ -o $@ $(MAKEFLAGS) main.o cmdReader.o cmdCharDef.o
#	strip $@

testAsc: testAsc.o cmdCharDef.o
	g++ -o $@ $(MAKEFLAGS) testAsc.o cmdCharDef.o
	strip $@

################
# Object files #
################
main.o: main.cpp cmdParser.h
	g++ -c $(MAKEFLAGS) main.cpp

cmdReader.o: cmdReader.cpp cmdParser.h
	g++ -c $(MAKEFLAGS) cmdReader.cpp

testAsc.o: testAsc.cpp cmdCharDef.h
	g++ -c $(MAKEFLAGS) testAsc.cpp

cmdParser.h: cmdCharDef.h
	touch cmdParser.h

#######################
# No dependency rules #
#######################
clean:
	rm -f *.o cmdReader testAsc

ctags:
	ctags *.cpp *.h
