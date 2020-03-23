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
For now, you need to use `kubectl proxy` to handle authentication.

```bash
kubectl proxy
./list_pod_bin
```

## Usage example

```c
    list_t *apiKeys;
    apiKeys = list_create();
    
    keyValuePair_t *keyPairToken = keyValuePair_create(keyToken, valueToken);
    list_addElement(apiKeys, keyPairToken);

    g_k8sAPIConnector = apiClient_create_with_base_path(K8S_APISERVER_BASEPATH, NULL, apiKeys);

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
