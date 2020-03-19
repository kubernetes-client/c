INCLUDE:=-I../../kubernetes/include -I../../kubernetes/model -I../../kubernetes/api
LIBS:=-L../../kubernetes/build -lkubernetes -lcurl -lpthread -lssl -lz
CFLAGS:=-g

all:
	gcc main.c $(CFLAGS) $(INCLUDE) $(LIBS) -o create_pod_bin
clean:
	rm ./create_pod_bin
