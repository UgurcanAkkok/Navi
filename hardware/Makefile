CC=gcc
CC_FLAGS= -ansi
TEST_SOURCE=test.c
HEADER=logic.h
OBJECTS=logic.o arithmetic.o
LIB_SOURCE=logic.c
EXE=test
logic=logic.c logic.h
arithmetic=arithmetic.c arithmetic.h

logic.o: $(logic)
	$(CC) $(CC_FLAGS) -c $(logic)

arithmetic.o: $(arithmetic)
	$(CC) $(CC_FLAGS) -c $(arithmetic)

test: $(OBJECTS) $(TEST_SOURCE)
	$(CC) $(CC_FLAGS) $(OBJECTS) $(TEST_SOURCE) -o $(EXE)

clean: 
	rm $(EXE) $(OBJECTS)
