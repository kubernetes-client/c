INCLUDE:=-I../../kubernetes/include -I../../kubernetes/model -I../../kubernetes/api -I../../kubernetes/config -I../../kubernetes/watch
LIBS:=-L../../kubernetes/build -lkubernetes -lyaml -lpthread -lwebsockets -L/usr/local/lib
CFLAGS:=-g

BIN:= multi_thread_bin
OBJECTS:=main.o watch_pod.o create_pod.o

.PHONY : all clean test memcheck
all: $(OBJECTS)
	$(CC) -o $(BIN) $(OBJECTS) $(LIBS)

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

test:
	./$(BIN)

memcheck:
	valgrind --tool=memcheck --leak-check=full ./$(BIN)

clean:
	rm $(BIN) $(OBJECTS)