# Versioning and Compatibility

## Client versioning

The C client uses Semantic Versioning. We increment the major version number whenever we regenerate the client for a new Kubernetes release version (see table below). Whenever we do this there are new APIs added and possibly breaking changes in the generated Kubernetes API Stubs. Whenever you upgrade a major version, be prepared for potential breaking changes.

## Compatibility

|  client version  |  1.17     |  1.18    |  1.19    |  1.20    |  1.21    |  1.22    |  1.23    |  1.24    |  1.25    |  1.26    |
|------------------|-----------|----------|----------|----------|----------|----------|----------|----------|----------|----------|
|  0.1.0           |  ✓        |  -       |  -       |  x       |  x       |  x       |  x       |  x       |  x       |  x       |
|  0.2.0           |  +        |  +       |  +       |  +       |  +       |  ✓       |  -       |  -       |  x       |  x       |
|  0.3.0           |  +        |  +       |  +       |  +       |  +       |  +       |  ✓       |  -       |  -       |  x       |
|  0.4.0           |  +        |  +       |  +       |  +       |  +       |  +       |  +       |  ✓       |  -       |  -       |
|  0.5.0           |  +        |  +       |  +       |  +       |  +       |  +       |  +       |  +       |  ✓       |  -       |
|  0.6.0           |  +        |  +       |  +       |  +       |  +       |  +       |  +       |  +       |  +       |  ✓       |
|  HEAD            |  +        |  +       |  +       |  +       |  +       |  +       |  +       |  +       |  +       |  ✓       |


Key: 

* `✓` Exactly the same features / API objects in both the C client and the Kubernetes
  version.
* `+` The C client has features or api objects that may not be present in the
  Kubernetes cluster, but everything they have in common will work.
* `-` The Kubernetes cluster has features the C client library can't use
  (additional API objects, etc).
* `x` The Kubernetes cluster has no guarantees to support the API client of
  this version, as it only promises _n_-2 version support. It is not tested,
  and operations using API versions that have been deprecated and removed in
  later server versions won't function correctly.