INCLUDE:=-I../../kubernetes/include -I../../kubernetes/model -I../../kubernetes/api -I../../kubernetes/config -I../../kubernetes/watch
LIBS:=-L../../kubernetes/build -lkubernetes -lyaml -lwebsockets -L/usr/local/lib
CFLAGS:=-g

all:
	gcc main.c $(CFLAGS) $(INCLUDE) $(LIBS) -o watch_list_pod_bin
clean:
	rm ./watch_list_pod_bin
