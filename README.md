# Kubernetes Client Library for C

[![Code Check](https://github.com/kubernetes-client/c/workflows/Code%20Check/badge.svg)](https://github.com/kubernetes-client/c/actions?query=workflow%3A%22Code+Check%22)
[![Build](https://github.com/kubernetes-client/c/workflows/Build/badge.svg)](https://github.com/kubernetes-client/c/actions?query=workflow%3ABuild)

This is the official Kubernetes client library for the C programming language.
It is a work in progress and should be considered _alpha_ quality software at this
time.

## Building the library
```bash
# Clone the repo
git clone https://github.com/kubernetes-client/c
CLIENT_REPO_ROOT=${PWD}/c

# Install pre-requisites
sudo apt-get install libssl-dev libcurl4-openssl-dev uncrustify

# Build pre-requisite: libwebsockets
git clone https://libwebsockets.org/repo/libwebsockets --depth 1 --branch v4.2-stable
cd libwebsockets
mkdir build
cd build
cmake -DLWS_WITHOUT_TESTAPPS=ON -DLWS_WITHOUT_TEST_SERVER=ON-DLWS_WITHOUT_TEST_SERVER_EXTPOLL=ON \
      -DLWS_WITHOUT_TEST_PING=ON -DLWS_WITHOUT_TEST_CLIENT=ON -DCMAKE_C_FLAGS="-fpic" -DCMAKE_INSTALL_PREFIX=/usr/local ..
make
sudo make install

# Build pre-requisite: libyaml
git clone https://github.com/yaml/libyaml --depth 1 --branch release/0.2.5
cd libyaml
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DBUILD_TESTING=OFF  -DBUILD_SHARED_LIBS=ON ..
make
sudo make install

# Move into the Kubernetes directory
cd ${CLIENT_REPO_ROOT}/kubernetes

# Build
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr/local/lib ..
make
sudo make install
```

## Building an example
```bash
cd ${CLIENT_REPO_ROOT}/examples/list_pod
make
```

## Running the example
```bash
./list_pod_bin
```

## Usage example

list all pods:

```c
    char *basePath = NULL;
    sslConfig_t *sslConfig = NULL;
    list_t *apiKeys = NULL;
    int rc = load_kube_config(&basePath, &sslConfig, &apiKeys, NULL);/* NULL means loading configuration from $HOME/.kube/config */
    if (rc != 0) {
        printf("Cannot load kubernetes configuration.\n");
        return -1;
    }
    apiClient_t *apiClient = apiClient_create_with_base_path(basePath, sslConfig, apiKeys);
    if (!apiClient) {
        printf("Cannot create a kubernetes client.\n");
        return -1;
    }

    v1_pod_list_t *pod_list = NULL;
    pod_list = CoreV1API_listNamespacedPod(apiClient,
                                          "default",    /*namespace */
                                           NULL,    /* pretty */
                                           0,       /* allowWatchBookmarks */
                                           NULL,    /* continue */
                                           NULL,    /* fieldSelector */
                                           NULL,    /* labelSelector */
                                           0,       /* limit */
                                           NULL,    /* resourceVersion */
                                           0,       /* timeoutSeconds */
                                           0        /* watch */
        );
    printf("return code=%ld\n", apiClient->response_code);
    if (pod_list) {
      ...
    }

    apiClient_free(apiClient);
    apiClient = NULL;
    free_client_config(basePath, sslConfig, apiKeys);
    basePath = NULL;
    sslConfig = NULL;
    apiKeys = NULL;
    apiClient_unsetupGlobalEnv();
```

list all pods in cluster:

```c
    char *basePath = NULL;
    sslConfig_t *sslConfig = NULL;
    list_t *apiKeys = NULL;
    int rc = load_incluster_config(&basePath, &sslConfig, &apiKeys);
    if (rc != 0) {
        printf("Cannot load kubernetes configuration in cluster.\n");
        return -1;
    }
    apiClient_t *apiClient = apiClient_create_with_base_path(basePath, sslConfig, apiKeys);
    if (!apiClient) {
        printf("Cannot create a kubernetes client.\n");
        return -1;
    }

    v1_pod_list_t *pod_list = NULL;
    pod_list = CoreV1API_listNamespacedPod(apiClient,
                                          "default",    /*namespace */
                                           NULL,    /* pretty */
                                           0,       /* allowWatchBookmarks */
                                           NULL,    /* continue */
                                           NULL,    /* fieldSelector */
                                           NULL,    /* labelSelector */
                                           0,       /* limit */
                                           NULL,    /* resourceVersion */
                                           0,       /* timeoutSeconds */
                                           0        /* watch */
        );
    printf("return code=%ld\n", apiClient->response_code);
    if (pod_list) {
      ...
    }

    apiClient_free(apiClient);
    apiClient = NULL;
    free_client_config(basePath, sslConfig, apiKeys);
    basePath = NULL;
    sslConfig = NULL;
    apiKeys = NULL;
    apiClient_unsetupGlobalEnv();
```

## Multi-threaded Usage

If the C client library is used in multi-threaded program, the following 2 actions are required:

1. After the program starts up, main thread must call the function ```apiClient_setupGlobalEnv()``` before any worker thread is created.

2. If the C client is no longer used, main thread must call the function ```apiClient_unsetupGlobalEnv()``` after all worker threads end.

Refer to the [example](https://github.com/kubernetes-client/c/tree/master/examples/multi_thread/) for detail. 

## Documentation

All APIs and Models' documentation can be found at the [Generated client's README file](https://github.com/kubernetes-client/c/blob/master/kubernetes/README.md#documentation-for-api-endpoints)

## Community, discussion, contribution, and support

Learn how to engage with the Kubernetes community on the [community page](http://kubernetes.io/community/).

You can reach the maintainers of this project at:

- [Slack](http://slack.k8s.io/)
- [Mailing List](https://groups.google.com/forum/#!forum/kubernetes-dev)

### Code of conduct

Participation in the Kubernetes community is governed by the [Kubernetes Code of Conduct](code-of-conduct.md).

[owners]: https://git.k8s.io/community/contributors/guide/owners.md
[Creative Commons 4.0]: https://git.k8s.io/website/LICENSE
