CC=c99
TEST_SOURCE=test.c
HEADER=logic.h
OBJECTS=logic.o
LIB_SOURCE=logic.c
EXE=test
logic=logic.c logic.h

logic.o: $(logic)
	$(CC) -c $(logic)

test: $(OBJECTS) $(TEST_SOURCE)
	$(CC) $(OBJECTS) $(TEST_SOURCE) -o $(EXE)

clean: 
	rm $(EXE) $(OBJECTS)
