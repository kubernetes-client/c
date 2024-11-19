load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")
load("@rules_foreign_cc//foreign_cc:defs.bzl", "make")
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
