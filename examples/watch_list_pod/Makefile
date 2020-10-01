INCLUDE:=-I../../kubernetes/include -I../../kubernetes/model -I../../kubernetes/api -I../../kubernetes/config -I../../kubernetes/watch
LIBS:=-L../../kubernetes/build -lkubernetes -lcurl -lyaml -lpthread -lssl -lz
CFLAGS:=-g

all:
	gcc main.c $(CFLAGS) $(INCLUDE) $(LIBS) -o watch_list_pod_bin
clean:
	rm ./watch_list_pod_bin
