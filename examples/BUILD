# Example of using bazel rules on the existing examples.

load("@rules_cc//cc:defs.bzl", "cc_binary")

# create and run executable file.
# Run: bazel run //examples:list_pod
cc_binary(
    name = "list_pod",
    srcs = [
        "list_pod/main.c",
    ],
    deps = ["//:kube_c_library"],  #imported from BUILD file of root directory
)

# Run: bazel run //examples:list_event
cc_binary(
    name = "list_event",
    srcs = ["list_event/main.c"],
    deps = ["//:kube_c_library"],  #imported from BUILD file of root directory
)
