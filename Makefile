CacheSimulation: main.o OpenHashTable.o
	g++ -g -std=c++11 -Wall main.o OpenHashTable.o -o CacheSimulation

main.o: main.cpp Node.hpp Node.h DoubleLinkedList.h DoubleLinkedList.hpp OpenHashTable.h OpenHashTable.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

OpenHashTable.o: OpenHashTable.h OpenHashTable.cpp DoubleLinkedList.h DoubleLinkedList.hpp
	g++ -g -std=c++11 -Wall -c OpenHashTable.cpp

clean:
	rm *.o CacheSimulation
	echo clean done
