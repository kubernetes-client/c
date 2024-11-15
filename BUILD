# Added BUILD file in the kubernetes c client repository helps integrating the library to external Bazel users.
# Following are the changes required from the external Bazel users to do.

# WORKSPACE

# load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
# http_archive(
#     name = "rules_foreign_cc",
#     sha256 = "a2e6fb56e649c1ee79703e99aa0c9d13c6cc53c8d7a0cbb8797ab2888bbc99a3",
#     strip_prefix = "rules_foreign_cc-0.12.0",
#     url = "https://github.com/bazelbuild/rules_foreign_cc/releases/download/0.12.0/rules_foreign_cc-0.12.0.tar.gz",
# )

# load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

# # This sets up some common toolchains for building targets. For more details, please see
# # https://bazelbuild.github.io/rules_foreign_cc/0.12.0/flatten.html#rules_foreign_cc_dependencies
# rules_foreign_cc_dependencies()

# load("@bazel_features//:deps.bzl", "bazel_features_deps")

# bazel_features_deps()

# http_archive(
#     name = "kubernetes_c_client",
#     sha256 = "10d0c5af1a52a1d2da379e8e45b53978b9dedc90ff195bdff171ae17c1f1dd50",
#     strip_prefix = "c-0.11.0",
#     url = "https://github.com/kubernetes-client/c/archive/refs/tags/v0.11.0.zip",
# )

# BUILD file:

# load("@rules_cc//cc:defs.bzl", "cc_binary")
# load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")
# load("@rules_foreign_cc//foreign_cc:defs.bzl", "make")
# cmake(
#     name = "kube_c",
#     build_args = [
#         "--verbose",
#         "--",  # <- Pass remaining options to the native tool.
#         "-j 1",
#     ],
#     lib_source = "@kubernetes_c_client//:kubernetes",
#     out_shared_libs = ["libkubernetes.so"],
# )

# cc_binary(
#     name = "create_pod",
#     srcs = ["create_pod.c"],
#     deps = [":kube_c"],
# )

# cc_binary(
#     name = "list_pod",
#     srcs = ["list_pod.c"],
#     deps = [":kube_c"],
# )

# Make sure you install the pre-requisites (libyaml,libwebsocket etc.) beforehand. A working example can be found here https://github.com/joyanta55/kubernetes_c_bazel/tree/main

# In summary, the below filegroup allows to import kubernetes C client (i.e. lib_source = "@kubernetes_c_client//:kubernetes"), use cmake or make bazel rule provided by rules_foreign_cc (https://github.com/bazel-contrib/rules_foreign_cc) to build and use.
filegroup(
    name = "kubernetes",
    srcs = glob(["kubernetes/**"]),
    visibility = ["//visibility:public"],
)