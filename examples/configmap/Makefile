INCLUDE:=-I../../kubernetes/include -I../../kubernetes/model -I../../kubernetes/api -I../../kubernetes/config
LIBS:=-L../../kubernetes/build -lkubernetes -lyaml -lwebsockets -L/usr/local/lib
CFLAGS:=-g
BIN:=configmap_bin

all:
	gcc main.c $(CFLAGS) $(INCLUDE) $(LIBS) -o $(BIN)
clean:
	rm ./$(BIN)
test:
	./$(BIN)
