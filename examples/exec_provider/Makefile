INCLUDE:=-I../../kubernetes/include -I../../kubernetes/model -I../../kubernetes/api -I../../kubernetes/config
LIBS:=-L../../kubernetes/build -lkubernetes -lyaml -lwebsockets -L/usr/local/lib
CFLAGS:=-g

all: my_exec_provider_bin list_pod_by_exec_provider_bin

list_pod_by_exec_provider_bin:
	gcc list_pod_by_exec_provider.c $(CFLAGS) $(INCLUDE) $(LIBS) -o list_pod_by_exec_provider_bin

my_exec_provider_bin:
	gcc my_exec_provider.c $(CFLAGS) -o my_exec_provider_bin

clean:
	rm ./my_exec_provider_bin ./list_pod_by_exec_provider_bin
