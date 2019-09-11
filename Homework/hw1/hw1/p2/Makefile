CFLAGS = -O3 -Wall -std=c++11
CFLAGS = -g -Wall -std=c++11

p2Run: p2Main.o p2Json.o
	g++ -o $@ p2Main.o p2Json.o $(CFLAGS)
#	strip $@

p2Main.o: p2Main.cpp p2Json.h
	g++ -c p2Main.cpp $(CFLAGS)

p2Json.o: p2Json.cpp p2Json.h
	g++ -c p2Json.cpp $(CFLAGS)

json:
	cd jsonGen; g++ -o jgen jsonGen.cpp $(CFLAGS)
	ln -sf jsonGen/jgen .

clean:
	rm -f p2Run *.o
	cd jsonGen; rm -f jgen *.o
