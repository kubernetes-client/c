INCLUDE:=-I../../kubernetes/include -I../../kubernetes/model -I../../kubernetes/api -I../../kubernetes/config -I../../kubernetes/websocket
LIBS:=-L../../kubernetes/build -lkubernetes -lyaml -lwebsockets -L/usr/local/lib
CFLAGS:=-g
BIN:=exec_pod_bin

.PHONY : all clean test memcheck
all:
	gcc main.c $(CFLAGS) $(INCLUDE) $(LIBS) -o $(BIN)

test:
	./$(BIN) only-run-case-1

memcheck:
	valgrind --tool=memcheck --leak-check=full ./$(BIN) only-run-case-1

clean:
	rm ./$(BIN)
