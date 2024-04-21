# Installing using conan
### Prerequisites
1- Python 3
https://www.python.org/downloads/

2- Conan package manager
https://docs.conan.io/2/installation.html

## Build and Install the repo to local system by using conan
1- Navigate to `kubernetes` directory, then use `conan create .` command. This will build the repo from source as static library.
```
cd  kubernetes
conan create . --build=missing
```

Validate `kubernetes_client_c` package exists by using following command to list all installed packages in local conan cache:
```
conan list "*"
```

## Using kubernetes_client_c library in  your project
1- Create `conanfile.py` or `conanfile.txt` file in the root of your project.

**conanfile.txt**
```
[requires]
kubernetes_client_c/0.9.0

[generators]
CMakeDeps
CMakeToolchain

[layout]
cmake_layout
```

**conanfile.py**
```python
from conan import ConanFile
from conan.tools.cmake import cmake_layout

class ExampleRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("kubernetes_client_c/0.9.0")

    def layout(self):
        cmake_layout(self)
```

2- Use following command (in the root directory of project) to install all dependencies that are specified in the `conanfile`:
```
conan install . --build=missing
```

3- Finally, edit your `CMakeLists.txt` of your project to link against libraries. In this case, we link to `kubernetes_client_c` library.

Add these lines after declaring the target in CMakeLists.

**CMakeLists.txt**
```
find_package(kubernetes_client_c)
target_link_libraries(<your_target> kubernetes_client_c::kubernetes_client_c)
```

Make sure to edit `<your_target>` with the actual target name.

4- Example `#include` headers:
```c
#include <kubernetes/api/CoreV1API.h>
#include <kubernetes/model/v1_pod.h>
#include <kubernetes/config/kube_config.h>
```
