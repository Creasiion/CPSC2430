main : ShelterBST.o main.o
	g++ main.o ShelterBST.o -o main

main.o : main.cpp ShelterBST.h
	g++ -c -Wall -Werror -pedantic -std=c++11 main.cpp

ShelterBST.o : ShelterBST.h ShelterBST.cpp
	g++ ShelterBST.cpp -c -Wall -Werror -pedantic -std=c++11 ShelterBST.cpp
