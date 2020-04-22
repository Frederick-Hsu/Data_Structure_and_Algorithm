# File name		: Makefile
# Description	: This script defines how to build the souce code.
# Creator		: Frederique Hsu
# Creation date	: Sun.	29 March 2020
# Copyright(C)	2020	All rights reserved.
#

OPTIONS = -Wall -std=c++14
DEBUG = -g

BOOKSTORE_APP = bookstore_app/Sales_item.o bookstore_app/Item_base.o bookstore_app/Disc_item.o bookstore_app/Bulk_item.o \
bookstore_app/Basket.o

OBJS = main.o testing.o class_template/misc.o function_template/verify.o generic_handle/utilizing_handle.o \
$(BOOKSTORE_APP)

templates : $(OBJS)
	g++ $(DEBUG) $(OPTIONS) $(OBJS) -o templates

main.o : main.cpp testing.h generic_handle/utilizing_handle.h
	g++ $(DEBUG) $(OPTIONS) -c main.cpp

testing.o : testing.cpp testing.h class_template/Queue.h class_template/List.h class_template/Screen.h \
function_template/function_template.h
	g++ $(DEBUG) $(OPTIONS) -c testing.cpp

misc.o : misc.cpp misc.h
	g++ $(DEBUG) $(OPTIONS) -c misc.cpp

utilizing_handle.o : utilizing_handle.cpp utilizing_handle.h Handle.h
	g++ $(DEBUG) $(OPTIONS) -c utilizing_handle.cpp

Sales_item.o : Sales_item.cpp Sales_item.h Item_base.h ../generic_handle/Handle.h
	g++ -DDEBUG $(DEBUG) $(OPTIONS) -c Sales_item.cpp

Item_base.o : Item_base.cpp Item_base.h
	g++ -DDEBUG $(DEBUG) $(OPTIONS) -c Item_base.cpp

Disc_item.o : Disc_item.cpp Disc_item.h Item_base.h
	g++ -DDEBUG $(DEBUG) $(OPTIONS) -c Disc_item.cpp

Bulk_item.o : Bulk_item.cpp Bulk_item.h Disc_item.h
	g++ -DDEBUG $(DEBUG) $(OPTIONS) -c Bulk_item.cpp

Basket.o : Basket.cpp Basket.h Sales_item.h
	g++ -DDEBUG $(DEBUG) $(OPTIONS) -c Basket.cpp

verify.o : verify.cpp verify.h template_overload.h
	g++ $(DEBUG) $(OPTIONS) -c verify.cpp

.PHONY : clean
clean :
	-rm -frv $(OBJS) templates *.d *.o