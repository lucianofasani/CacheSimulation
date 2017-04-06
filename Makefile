CacheSimulation: main.o Cache.o
	g++ -g -std=c++11 -Wall main.o Cache.o -o CacheSimulation

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

Cache.o: Cache.h Cache.cpp
	g++ -g -std=c++11 -Wall -c Cache.cpp

clean:
	rm *.o CacheSimulation
	echo clean done
