# OCCUtils
OpenCASCADE utility library - algorithms and convenience functions.

### Prerequisites

First install OpenCASCADE 7.x. My preferred method on Ubuntu is to use the [FreeCAD daily PPA](https://launchpad.net/~freecad-maintainers/+archive/ubuntu/freecad-daily):

```sh
sudo add-apt-repository ppa:freecad-maintainers/freecad-daily
sudo apt-get update
sudo apt install libocct\*
```

Also you need to install a recent version of CMake & GCC. Since we use C++17 features, a recent version of both G++ and CMake is required:
```sh
sudo apt install cmake build-essential
```

On Ubuntu 18.04+ you don't need to do anything special to compile.

### How to build

There are two preferred methods of building and installing OCCUtils

##### System-wide install

```sh
git clone https://github.com/ulikoehler/OCCUtils.git
cmake .
make
sudo make install
```

Then you can use e.g.
```cpp
#include <occutils/SurfaceUtils.hxx>

using namespace OCCUtils;

// ...
auto surfOpt = SurfaceUtils::SurfaceFromFace(face);
// ...
```

and link with `-loccutils`.

##### git-submodule based installation

This method involves adding the repository and building it as a subproject of your CMake-based main project. I recommend doing this especially for more complex projects. However you need some knowledge of CMake to get it working and debug related issues.

In your project root directory:
```sh
git submodule init
git submodule add https://github.com/ulikoehler/OCCUtils.git OCCUtils
```

Then add this CMake code to your `CMakeLists.txt`:
```cmake
add_subdirectory(OCCUtils)
```

and

```cmake
add_dependencies( my_target occutils )
target_link_libraries( my_target occutils )
```
replacing `my_target` with the name of your build target (i.e. the first argument you give to `add_executable()`). The `occutils` CMake script will take care of the rest.

## How to use

TODO