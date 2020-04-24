# File name		: Makefile
# Description	: This script describe how to compile the source code files.
#

OPTIONS = -g -Wall -p -std=c++17
FLAGS = -NDEBUG

OBJS = main.o permutation_and_combination.o testing.o

algos : $(OBJS)
	g++ $(OPTIONS) $(FLAGS) $(OBJS) -o algos

main.o : main.cpp testing.h
	g++ $(OPTIONS) $(FLAGS) -c main.cpp

testing.o : testing.cpp testing.h permutation_and_combination.h
	g++ $(OPTIONS) $(FLAGS) -c testing.cpp

permutation_and_combination.o : permutation_and_combination.cpp permutation_and_combination.h
	g++ $(OPTIONS) $(FLAGS) -c permutation_and_combination.cpp

.PHONY : clean
clean :
	-rm -frv $(OBJS) algos