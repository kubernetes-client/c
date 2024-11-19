load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake", "make")

cmake(
    name = "kube_c",
    build_args = [
        "--verbose",
        "--",  # <- Pass remaining options to the native tool.
        "-j 1",
    ],
    lib_source = "//:kubernetes",
    out_shared_libs = ["libkubernetes.so"],
)

# create lib files (.so or .a)
# Example: bazel build list_pod_lib
cc_library(
    name = "list_pod_lib",
    srcs = ["bazel/list_pod.c"],
    deps = [":kube_c"],
)

# create and run executable file.
# Example: bazel run list_pod
cc_binary(
    name = "list_pod",
    srcs = ["bazel/list_pod.c"],
    deps = [":kube_c"],
)

cc_binary(
    name = "create_pod",
    srcs = ["bazel/create_pod.c"],
    deps = [":kube_c"],
)
