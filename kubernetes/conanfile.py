from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
from conan.tools.files import copy
from os.path import join

class kubernetes_client_cRecipe(ConanFile):
    name = "kubernetes_client_c"
    version = "0.9.0"
    package_type = "library"

    # Optional metadata
    license = "Apache-2.0"
    url = "https://github.com/kubernetes-client/c"
    description = "Official C client library for Kubernetes"
    topics = ("kubernetes", "k8s", "kubernetes-client", "k8s-client")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "config.h.in", "ConfigureChecks.cmake", "PreTarget.cmake", "PostTarget.cmake", "CMakeLists.txt", "src/*", "external/*", "api/*", "model/*", "include/*", "config/*", "watch/*", "websocket/*"

    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        copy(self, "*.h", src=join(self.source_folder, "api"), dst=join(self.package_folder, "include/kubernetes/api"), keep_path=False)
        copy(self, "*.h", src=join(self.source_folder, "model"), dst=join(self.package_folder, "include/kubernetes/model"), keep_path=False)
        copy(self, "*.h", src=join(self.source_folder, "config"), dst=join(self.package_folder, "include/kubernetes/config"), keep_path=False)
        copy(self, "*.h", src=join(self.source_folder, "include"), dst=join(self.package_folder, "include/kubernetes/include"), keep_path=False)
        copy(self, "*.h", src=join(self.source_folder, "websocket"), dst=join(self.package_folder, "include/kubernetes/websocket"), keep_path=False)
        copy(self, "*.h", src=join(self.source_folder, "external"), dst=join(self.package_folder, "include/kubernetes/external"), keep_path=False)
        copy(self, "*.h", src=join(self.source_folder, "watch"), dst=join(self.package_folder, "include/kubernetes/watch"), keep_path=False)
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["kubernetes"]

    def requirements(self):
        self.requires("libcurl/[^8]", transitive_headers=True)
        self.requires("openssl/[~1.1]")
        self.requires("libwebsockets/4.2.0", transitive_headers=True)
        self.requires("libyaml/0.2.5")
