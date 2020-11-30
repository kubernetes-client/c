INCLUDE:=-I../../kubernetes/include -I../../kubernetes/model -I../../kubernetes/api -I../../kubernetes/config
LIBS:=-L../../kubernetes/build -lkubernetes -lyaml
CFLAGS:=-g

all:
	gcc main.c $(CFLAGS) $(INCLUDE) $(LIBS) -o generic_bin 
clean:
	rm ./generic_bin
