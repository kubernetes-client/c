INCLUDE:=-I../../kubernetes/
LIBS:=-L../../kubernetes/build -lyaml -lwebsockets -lkubernetes -L/usr/local/lib
CFLAGS:=-g
BIN:=list_event_bin

.PHONY : all clean test memcheck
all:
	gcc main.c $(CFLAGS) $(INCLUDE) $(LIBS) -o $(BIN)

test:
	./$(BIN)

memcheck:
	valgrind --tool=memcheck --leak-check=full ./$(BIN)

clean:
	rm ./$(BIN)
