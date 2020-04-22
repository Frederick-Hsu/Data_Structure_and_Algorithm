# File name		: Makefile
# Description	: This script tells how to build this MultiThreading project.
#

OPTIONS = -g -Wall -std=c++17
FLAGS = -p

OBJS = program.o \
thread_creation.o join_detach_thread.o ThreadRAII.o \
pass_args_to_threads.o Dummy.o Wallet.o race_conditions.o \
event_handling.o Application.o returning_value_from_threads.o \
async_thread_handling.o create_async_packaged_task.o

MultiThreading : $(OBJS)
	g++ $(OPTIONS) $(FLAGS) $(OBJS) -o MultiThreading -lpthread

# main.o : main.cpp thread_creation.h
#	g++ $(OPTIONS) $(FLAGS) -c main.cpp

program.o : program.cpp join_detach_thread.h ThreadRAII.h pass_args_to_threads.h race_conditions.h \
event_handling.h
	g++ $(OPTIONS) $(FLAGS) -c program.cpp

thread_creation.o : thread_creation.cpp thread_creation.h
	g++ $(OPTIONS) $(FLAGS) -c thread_creation.cpp

join_detach_thread.o : join_detach_thread.cpp join_detach_thread.h
	g++ $(OPTIONS) $(FLAGS) -c join_detach_thread.cpp

ThreadRAII.o : ThreadRAII.cpp ThreadRAII.h
	g++ $(OPTIONS) $(FLAGS) -c ThreadRAII.cpp

pass_args_to_threads.o : pass_args_to_threads.cpp pass_args_to_threads.h Dummy.h
	g++ $(OPTIONS) $(FLAGS) -c pass_args_to_threads.cpp

Dummy.o : Dummy.cpp Dummy.h
	g++ $(OPTIONS) $(FLAGS) -c Dummy.cpp

race_conditions.o : race_conditions.cpp race_conditions.h Wallet.h
	g++ $(OPTIONS) $(FLAGS) -c race_conditions.cpp

Wallet.o : Wallet.cpp Wallet.h
	g++ $(OPTIONS) $(FLAGS) -c Wallet.cpp

event_handling.o : event_handling.cpp event_handling.h Application.h
	g++ $(OPTIONS) $(FLAGS) -c event_handling.cpp

Application.o : Application.cpp Application.h
	g++ $(OPTIONS) $(FLAGS) -c Application.cpp

returning_value_from_threads.o : returning_value_from_threads.cpp returning_value_from_threads.h
	g++ $(OPTIONS) $(FLAGS) -c returning_value_from_threads.cpp

async_thread_handling.o : async_thread_handling.cpp async_thread_handling.h
	g++ $(OPTIONS) $(FLAGS) -c async_thread_handling.cpp

create_async_packaged_task.o : create_async_packaged_task.cpp create_async_packaged_task.h
	g++ $(OPTIONS) $(FLAGS) -c create_async_packaged_task.cpp

.PHONY : clean
clean :
	-rm -frv $(OBJS) MultiThreading *.out *.o