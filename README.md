# OCCUtils
[OpenCASCADE](https://opencascade.com) utility library - algorithms and convenience functions.

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

On my [blog](https://techoverflow.net) I provide examples of specific usecases for OpenCASCADE, including how to use the relevant OCCUtils functions:

* [How to compute surface area of TopoDS_Face in OpenCASCADE](https://techoverflow.net/2019/06/13/how-to-compute-surface-area-of-topods_face-in-opencascade/)
* [How to create a Cylinder TopoDS_Solid in OpenCASCADE](https://techoverflow.net/2019/06/13/how-to-create-a-cylinder-topods_solid-in-opencascade/)
* [How to create a Box TopoDS_Solid in OpenCASCADE](https://techoverflow.net/2019/06/13/how-to-create-a-box-topods_solid-in-opencascade/)
* [How to create a Cube TopoDS_Solid in OpenCASCADE](https://techoverflow.net/2019/06/13/how-to-create-a-cube-topods_solid-in-opencascade/)
* [How to create TopTools_ListOfShape of two or more shapes in OpenCASCADE](https://techoverflow.net/2019/06/13/how-to-create-toptools_listofshape-of-two-or-more-shapes-in-opencascade/)
* [How to iterate all edges in TopoDS_Face using OpenCASCADE](https://techoverflow.net/2019/06/13/how-to-iterate-all-edges-in-topods_face-using-opencascade/)
* [How to export STEP file in OpenCASCADE](https://techoverflow.net/2019/06/13/how-to-export-step-file-in-opencascade/)
* [How to fuse TopoDS_Shapes in OpenCASCADE (boolean AND)](https://techoverflow.net/2019/06/14/how-to-fuse-topods_shapes-in-opencascade-boolean-and/)
* [How to export colored STEP files in OpenCASCADE](https://techoverflow.net/2019/06/14/how-to-export-colored-step-files-in-opencascade/)
* [Overview of all standard colors available in OpenCASCADE](https://techoverflow.net/2019/06/14/overview-of-all-standard-colors-available-in-opencascade/)