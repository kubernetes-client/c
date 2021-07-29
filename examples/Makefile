all:
	cd create_pod; make
	cd list_pod; make
	cd list_pod_incluster; make
	cd delete_pod; make
	cd exec_provider; make
	cd generic; make
	cd auth_provider; make
	cd watch_list_pod; make
	cd multi_thread; make
	cd exec_pod; make
	cd list_secret; make
	cd configmap; make

clean:
	cd create_pod; make clean
	cd list_pod; make clean
	cd list_pod_incluster; make clean
	cd delete_pod; make clean
	cd exec_provider; make clean
	cd generic; make clean
	cd auth_provider; make clean
	cd watch_list_pod; make clean
	cd multi_thread; make clean
	cd exec_pod; make clean
	cd list_secret; make clean
	cd configmap; make clean

test:
	cd create_pod; make test; sleep 10
	cd list_pod; make test
	cd delete_pod; make test
	cd list_secret; make test
	cd configmap; make test
	cd generic; make test
	cd multi_thread; make test; sleep 10
	kubectl describe po test-pod-8
	cd exec_pod; make test