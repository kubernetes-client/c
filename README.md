# Kubernetes Client Library for C

This is the official Kubernetes client library for the C programming language.
It is a work in progress and should be considered _alpha_ quality software at this
time.

## Building the library
```bash
# Clone the repo
git clone https://github.com/kubernetes-client/c
CLIENT_REPO_ROOT=${PWD}/c

# Install pre-requisites
sudo apt-get install libcurl4-openssl-dev uncrustify

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
```


## Community, discussion, contribution, and support

Learn how to engage with the Kubernetes community on the [community page](http://kubernetes.io/community/).

You can reach the maintainers of this project at:

- [Slack](http://slack.k8s.io/)
- [Mailing List](https://groups.google.com/forum/#!forum/kubernetes-dev)

### Code of conduct

Participation in the Kubernetes community is governed by the [Kubernetes Code of Conduct](code-of-conduct.md).

[owners]: https://git.k8s.io/community/contributors/guide/owners.md
[Creative Commons 4.0]: https://git.k8s.io/website/LICENSE
