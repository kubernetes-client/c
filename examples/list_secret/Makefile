INCLUDE:=-I../../kubernetes/include -I../../kubernetes/model -I../../kubernetes/api -I../../kubernetes/config
LIBS:=-L../../kubernetes/build -lkubernetes -lyaml -lwebsockets -L/usr/local/lib
CFLAGS:=-g
BIN:=list_secret_bin

.PHONY : all clean test memcheck
all:
	gcc main.c $(CFLAGS) $(INCLUDE) $(LIBS) -o $(BIN)

memcheck:
	valgrind --tool=memcheck --leak-check=full ./$(BIN)

test:
	./$(BIN)

clean:
	rm ./$(BIN)
