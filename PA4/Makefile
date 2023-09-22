assignment4 : assignment4.o CovidDB.o DataEntry.o
	g++ -o assignment4 assignment4.o CovidDB.o DataEntry.o

assignment4.o : main.cpp CovidDB.o DataEntry.o
	g++ -o assignment4.o -c -Wall -Werror -pedantic -std=c++11 main.cpp

CovidDB.o : CovidDB.h CovidDB.cpp
	g++ CovidDB.cpp -c -Wall -Werror -pedantic -std=c++11 CovidDB.cpp

DataEntry.o : DataEntry.h DataEntry.cpp
	g++ DataEntry.cpp -c -Wall -Werror -pedantic -std=c++11 DataEntry.cpp
