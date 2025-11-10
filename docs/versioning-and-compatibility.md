# Versioning and Compatibility

## Client versioning

The C client uses Semantic Versioning. We increment the major version number whenever we regenerate the client for a new Kubernetes release version (see table below). Whenever we do this there are new APIs added and possibly breaking changes in the generated Kubernetes API Stubs. Whenever you upgrade a major version, be prepared for potential breaking changes.

## Compatibility

|  client version  |  1.28    |  1.29    |  1.30     |  1.31     |  1.32     |  1.33     |  1.34     |
|------------------|----------|----------|-----------|-----------|-----------|-----------|-----------|
|  0.10.0          |  +       |  +       |  ✓        |  -        |  -        |  x        |  x        |
|  0.11.0          |  +       |  +       |  +        |  ✓        |  -        |  -        |  x        |
|  0.12.0          |  +       |  +       |  +        |  +        |  ✓        |  -        |  -        |
|  0.13.0          |  +       |  +       |  +        |  +        |  +        |  ✓        |  -        |
|  0.14.0          |  +       |  +       |  +        |  +        |  +        |  +        |  ✓        |
|  HEAD            |  +       |  +       |  +        |  +        |  +        |  +        |  ✓        |

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
