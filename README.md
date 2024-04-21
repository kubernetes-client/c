# Kubernetes Client Library for C

[![Client Capabilities](https://img.shields.io/badge/Kubernetes%20client-Silver-blue.svg?style=flat&colorB=C0C0C0&colorA=306CE8)](https://github.com/kubernetes/design-proposals-archive/blob/main/api-machinery/csi-new-client-library-procedure.md#client-capabilities)
[![Client Support Level](https://img.shields.io/badge/kubernetes%20client-beta-green.svg?style=flat&colorA=306CE8)](https://github.com/kubernetes/design-proposals-archive/blob/main/api-machinery/csi-new-client-library-procedure.md#client-support-level)
[![Code Check](https://github.com/kubernetes-client/c/workflows/Code%20Check/badge.svg)](https://github.com/kubernetes-client/c/actions?query=workflow%3A%22Code+Check%22)
[![Build](https://github.com/kubernetes-client/c/workflows/Build/badge.svg)](https://github.com/kubernetes-client/c/actions?query=workflow%3ABuild)

This is the official Kubernetes client library for the C programming language.

## Building the library
```bash
# Clone the repo
git clone https://github.com/kubernetes-client/c
CLIENT_REPO_ROOT=${PWD}/c

# Install pre-requisites
sudo apt-get install libssl-dev libcurl4-openssl-dev uncrustify

# Build pre-requisite: libwebsockets
git clone https://github.com/warmcat/libwebsockets --depth 1 --branch v4.2-stable
cd libwebsockets
mkdir build
cd build
cmake -DLWS_WITHOUT_TESTAPPS=ON -DLWS_WITHOUT_TEST_SERVER=ON -DLWS_WITHOUT_TEST_SERVER_EXTPOLL=ON \
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
# If you don't need to debug the C client library:
cmake -DCMAKE_INSTALL_PREFIX=/usr/local ..
# If you want to use `gdb` to debug the C client library, add `-DCMAKE_BUILD_TYPE=Debug` to the cmake command line, e.g.
# cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=/usr/local ..
make
sudo make install
```

## (Optional) Installing using vcpkg on Windows
If you want to install the C client using vcpkg, please refer to [vcpkg.md](https://github.com/kubernetes-client/c/blob/master/docs/vcpkg.md)

## (Optional) Installing using conan on Windows, Linux, Mac
If you want to install the C client using conan, please refer to [conan.md](https://github.com/kubernetes-client/c/blob/master/docs/conan.md)

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
                                           NULL,    /* allowWatchBookmarks */
                                           NULL,    /* continue */
                                           NULL,    /* fieldSelector */
                                           NULL,    /* labelSelector */
                                           NULL,    /* limit */
                                           NULL,    /* resourceVersion */
                                           NULL,    /* resourceVersionMatch */
                                           NULL,    /* sendInitialEvents */
                                           NULL,    /* timeoutSeconds */
                                           NULL     /* watch */
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
                                           NULL,    /* allowWatchBookmarks */
                                           NULL,    /* continue */
                                           NULL,    /* fieldSelector */
                                           NULL,    /* labelSelector */
                                           NULL,    /* limit */
                                           NULL,    /* resourceVersion */
                                           NULL,    /* resourceVersionMatch */
                                           NULL,    /* sendInitialEvents */
                                           NULL,    /* timeoutSeconds */
                                           NULL     /* watch */
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

## How to send integer or boolean parameters to API Server

If you want to send an integer or boolean parameter to the API server, you will see that the data type in API function is `int *`, e.g.

```c
// list or watch objects of kind Pod
//
v1_pod_list_t* CoreV1API_listNamespacedPod(apiClient_t *apiClient, 
                                           char *_namespace, 
                                           char *pretty, 
                                           int *allowWatchBookmarks, /* <-- here */
                                           char *_continue, 
                                           char *fieldSelector, 
                                           char *labelSelector, 
                                           int *limit,               /* <-- here */
                                           char *resourceVersion, 
                                           char *resourceVersionMatch, 
                                           int *sendInitialEvents,   /* <-- here */
                                           int *timeoutSeconds,      /* <-- here */
                                           int *watch);              /* <-- here */
```

For example we can send `timeoutSeconds` and `watch` using the following usage:

```c
int timeoutSeconds = 30;
int watch = 1;
pod_list = CoreV1API_listNamespacedPod(apiClient, "default",    /*namespace */
                                       NULL,    /* pretty */
                                       NULL,    /* allowWatchBookmarks */
                                       NULL,    /* continue */
                                       NULL,    /* fieldSelector */
                                       NULL,    /* labelSelector */
                                       NULL,    /* limit */
                                       NULL,    /* resourceVersion */
                                       NULL,    /* resourceVersionMatch */
                                       NULL,    /* sendInitialEvents */
                                       &timeoutSeconds,    /* timeoutSeconds */
                                       &watch   /* watch */
);
```

Setting the parameter to `NULL` means not to send the parameter to the API Server, and the API Server will use the default value for this parameter.

## Aggregated APIs and CRD-based APIs

If you want to implement a client for aggregated APIs (such as the metrics server API `apis/metrics.k8s.io` ) or CRD-based APIs, use the [generic client](./kubernetes/src/generic.c). See [example](./examples/generic/main.c).

## Multi-threaded Usage

If the C client library is used in multi-threaded program, the following 2 actions are required:

1. After the program starts up, main thread must call the function ```apiClient_setupGlobalEnv()``` before any worker thread is created.

2. If the C client is no longer used, main thread must call the function ```apiClient_unsetupGlobalEnv()``` after all worker threads end.

Refer to the [example](https://github.com/kubernetes-client/c/tree/master/examples/multi_thread/) for detail. 

## Documentation

All APIs and Models' documentation can be found at the [Generated client's README file](https://github.com/kubernetes-client/c/blob/master/kubernetes/README.md#documentation-for-api-endpoints)

## Versions and Compatibility

See [versioning-and-compatibility.md](./docs/versioning-and-compatibility.md)

## Community, discussion, contribution, and support

Learn how to engage with the Kubernetes community on the [community page](http://kubernetes.io/community/).

You can reach the maintainers of this project at:

- [Slack](http://slack.k8s.io/)
- [Mailing List](https://groups.google.com/a/kubernetes.io/g/dev)

### Code of conduct

Participation in the Kubernetes community is governed by the [Kubernetes Code of Conduct](code-of-conduct.md).

[owners]: https://git.k8s.io/community/contributors/guide/owners.md
[Creative Commons 4.0]: https://git.k8s.io/website/LICENSE
