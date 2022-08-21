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
	cd create_pod; make test;
	kubectl wait --for=condition=ready --all pod -n default --timeout=60s
	cd list_pod; make test
	cd delete_pod; make test
	kubectl wait --for=delete pod/test-pod-6 -n default --timeout=120s
	cd list_secret; make test
	cd configmap; make test
	cd generic; make test
	cd multi_thread; make test;
	kubectl wait --for=condition=ready pod/test-pod-8 -n default --timeout=60s
	kubectl describe po test-pod-8
	cd exec_pod; make test

memcheck:
	cd create_pod; make memcheck;
	kubectl wait --for=condition=ready --all pod -n default --timeout=60s
	cd list_pod; make memcheck
	cd delete_pod; make memcheck
	kubectl wait --for=delete pod/test-pod-6 -n default --timeout=120s
	cd list_secret; make memcheck
	cd configmap; make memcheck
	cd generic; make memcheck
	cd multi_thread; make memcheck;
	kubectl wait --for=condition=ready pod/test-pod-8 -n default --timeout=60s
	kubectl describe po test-pod-8
	cd exec_pod; make memcheck