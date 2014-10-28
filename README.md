SML
===

`Simple Maths Library (SML)` is a C++ template library that provides some basic mathematics functionality.

[![Build Status](https://travis-ci.org/kartikkumar/sml.svg?branch=master)](https://travis-ci.org/kartikkumar/sml)

Requirements
------

This project requires the following:

 - A C++ compiler, e.g., [GCC](https://gcc.gnu.org/), [clang](http://clang.llvm.org/), [MinGW](http://www.mingw.org/)
 - [`CMake`](http://www.cmake.org)

Installation
------

Run the following commands to download, build, and install this project.

`git clone https://www.github.com/kartikkumar/cpp-template`
`cd cpp-template`
`git submodule init`
`git submodule update`
`mkdir build`
`cd build`
`cmake ..`
`make`
`make install`

Build options
-------------

You can pass the follow command-line options when running `CMake`:

 - `-DBUILD_DOCS=on`: build the [Doxygen](http://www.doxygen.org "Doxygen homepage") documentation
 - `-DBUILD_TESTS=on`: build tests (execute tests from build-directory using `make test`)
 - `-DBUILD_WITH_EIGEN=on`: build tests with Eigen library as well (http://eigen.tuxfamily.org/; requires Eigen to be installed)
 - `-DBUILD_SHARED_LIBS=on`: build shared libraries instead of static
 - `-DCMAKE_INSTALL_PREFIX`: set path prefix for install script (`make install`)
 
Contributing
------------

Once you've made your great commits:

1. [Fork](https://github.com/kartikkumar/sml/fork) SML
2. Create a topic branch - `git checkout -b my_branch`
3. Push to your branch - `git push origin my_branch`
4. Create a [Pull Request](http://help.github.com/pull-requests/) from your branch
5. That's it!

License
------

See `LICENSE`.

Disclaimer
------

The copyright holders are not liable for any damage(s) incurred due to improper use of `SML`.

Contact
------

Shoot an [email](mailto:me@kartikkumar.com?subject=SML) if you have any questions.
