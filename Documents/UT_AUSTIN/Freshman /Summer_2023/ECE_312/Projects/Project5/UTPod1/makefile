final: driver.o UTPod.o song.o
	g++ -o UTPod UTPodDriver.o UTPod.o Song.o
driver.o:
	g++ -std=c++1y -O0 -g -Wall -Werror -o UTPodDriver.o -c UTPodDriver.cpp
UTPod.o:
	g++ -std=c++1y -O0 -g -Wall -Werror -o UTPod.o -c UTPod.cpp
song.o: Song.cpp Song.h
	g++ -std=c++1y -O0 -g -Wall -Werror -o Song.o -c Song.cpp
