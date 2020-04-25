# File name		: Makefile
# Description	: The script to guide how to build this project.
# Creator		: Frederique Hsu
# Creation date	: Wed.	01 April 2020
# Copyright(C)	2020	All rights reserved.
#

OPTIONS = -Wall -std=c++14
FLAGS = -g

OBJS = main.o ZooAnimal.o Bear.o Panda.o Endangered.o

multiple_inheritance : $(OBJS)
	g++ $(OPTIONS) $(FLAGS) $(OBJS) -o multiple_inheritance

main.o : main.cpp
	g++ $(OPTIONS) $(FLAGS) -c main.cpp

ZooAnimal.o : ZooAnimal.cpp ZooAnimal.h
	g++ $(OPTIONS) $(FLAGS) -c ZooAnimal.cpp

Bear.o : Bear.cpp Bear.h ZooAnimal.h
	g++ $(OPTIONS) $(FLAGS) -c Bear.cpp

Panda.o : Panda.cpp Panda.h Endangered.h
	g++ $(OPTIONS) $(FLAGS) -c Panda.cpp

Endangered.o : Endangered.cpp Endangered.h
	g++ $(OPTIONS) $(FLAGS) -c Endangered.cpp

.PHONY : clean
clean :
	-rm -frv multiple_inheritance $(OBJS)