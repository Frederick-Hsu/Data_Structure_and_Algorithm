# File name		: Makefile
# Description	: This script describe how to build the source code files of runtime_type project.
# Creator		: Frederique Hsu
# Creation date	: Tue.	07 April 2020
# Copyright(C)	2020	All rights reserved.
#

OPTIONS = -std=c++17 -Wall -p
FLAGS = -g

OBJS = main.o testing.o types.o

runtime_type : $(OBJS)
	g++ $(OPTIONS) $(FLAGS) $(OBJS) -o runtime_type

main.o : main.cpp testing.h
	g++ $(OPTIONS) $(FLAGS) -c main.cpp

testing.o : testing.cpp  testing.h types.h
	g++ $(OPTIONS) $(FLAGS) -c testing.cpp

types.o : types.cpp types.h
	g++ $(OPTIONS) $(FLAGS) -c types.cpp

.PHONY : clean
clean :
	-rm -frv $(OBJS) runtime_type