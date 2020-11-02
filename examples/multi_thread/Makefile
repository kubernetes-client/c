INCLUDE:=-I../../kubernetes/include -I../../kubernetes/model -I../../kubernetes/api -I../../kubernetes/config -I../../kubernetes/watch
LIBS:=-L../../kubernetes/build -lkubernetes -lyaml -lpthread
CFLAGS:=-g

BIN:= multi_thread_bin
OBJECTS:=main.o watch_pod.o create_pod.o

all: $(OBJECTS)
	$(CC) -o $(BIN) $(OBJECTS) $(LIBS)

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY : clean
clean:
	rm $(BIN) $(OBJECTS)