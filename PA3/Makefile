assignment3 : ShelterBST.o assignment3.o
	g++ assignment3.o ShelterBST.o -o assignment3

assignment3.o : assignment3.cpp ShelterBST.h
	g++ -c -Wall -Werror -pedantic -std=c++11 assignment3.cpp

ShelterBST.o : ShelterBST.h ShelterBST.cpp
	g++ ShelterBST.cpp -c -Wall -Werror -pedantic -std=c++11 ShelterBST.cpp
