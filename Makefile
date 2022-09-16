#############################################################################
#
# makefile
#
#############################################################################

HOME = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include


#Flags
ENGINEFLAGS = -lEngine -lObject -lObjectComponent -lMovementComponent
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

ALLLIBS = $(LIB)/libEngine.a $(LIB)/libObject.a $(LIB)/libObjectComponent.a $(LIB)/libMovementComponent.a
ALLINCLUDES = $(INCLUDE)/Engine.h $(INCLUDE)/Object.h $(INCLUDE)/ObjectComponent.h $(INCLUDE)/MovementComponent.h

#................................................

all: presentacion \
	 $(BIN)/REngine \
	 fin

#................................................

presentacion:
	@echo
	@echo ------------------------------------------------------------
	@echo Compiling REngine...
	@echo ------------------------------------------------------------
	@echo

#................................................

fin:
	@echo

#................................................

#REngine
#####################################################################

$(BIN)/REngine: $(ALLLIBS) $(OBJ)/REngine.o
	g++ -o $(BIN)/REngine $(OBJ)/REngine.o $(ENGINEFLAGS) $(SFMLFLAGS) -L$(LIB)

$(OBJ)/REngine.o: $(SRC)/main.cpp $(ALLINCLUDES)
	g++ -c -o $(OBJ)/REngine.o $(SRC)/main.cpp -I$(INCLUDE)

#................................................
#Class Engine.h

$(LIB)/libEngine.a: $(OBJ)/Engine.o
	ar rvs $(LIB)/libEngine.a $(OBJ)/Engine.o

$(OBJ)/Engine.o: $(SRC)/Engine.cpp $(INCLUDE)/Engine.h
	g++ -c -o $(OBJ)/Engine.o $(SRC)/Engine.cpp -I$(INCLUDE) -std=c++11

#................................................
#Class Object.h

$(LIB)/libObject.a: $(OBJ)/Object.o
	ar rvs $(LIB)/libObject.a $(OBJ)/Object.o

$(OBJ)/Object.o: $(SRC)/Object.cpp $(INCLUDE)/Object.h
	g++ -c -o $(OBJ)/Object.o $(SRC)/Object.cpp -I$(INCLUDE) -std=c++11


#Class ObjectComponent.h

$(LIB)/libObjectComponent.a: $(OBJ)/ObjectComponent.o
	ar rvs $(LIB)/libObjectComponent.a $(OBJ)/ObjectComponent.o

$(OBJ)/ObjectComponent.o: $(SRC)/ObjectComponent.cpp $(INCLUDE)/ObjectComponent.h
	g++ -c -o $(OBJ)/ObjectComponent.o $(SRC)/ObjectComponent.cpp -I$(INCLUDE) -std=c++11

#Class MovementComponent.h

$(LIB)/libMovementComponent.a: $(OBJ)/MovementComponent.o
	ar rvs $(LIB)/libMovementComponent.a $(OBJ)/MovementComponent.o

$(OBJ)/MovementComponent.o: $(SRC)/MovementComponent.cpp $(INCLUDE)/MovementComponent.h
	g++ -c -o $(OBJ)/MovementComponent.o $(SRC)/MovementComponent.cpp -I$(INCLUDE) -std=c++11

#................................................
#CLEANING

clean: clean-objs clean-libs

clean-objs: 
	@echo Deleting objects ...

	-rm $(OBJ)/*

	@echo ... Objects deleted
	@echo 


clean-libs: 
	@echo Deleting libs ...

	-rm $(LIB)/*

	@echo ... Libs deleted
	@echo 

clean-bins : 
	@echo Deleting execs ...
	-rm $(BIN)/*
	@echo ... Execs deleted

mr.proper:  clean-objs clean-libs clean-bins