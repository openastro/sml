SML
===

[![MIT license](http://img.shields.io/badge/license-MIT-brightgreen.svg)](http://opensource.org/licenses/MIT) [![Build Status](https://travis-ci.org/kartikkumar/sml.svg?branch=master)](https://travis-ci.org/kartikkumar/sml) [![Coverity Scan Build Status](https://scan.coverity.com/projects/3666/badge.svg)](https://scan.coverity.com/projects/3666") [![Coverage Status](https://coveralls.io/repos/kartikkumar/sml/badge.png)](https://coveralls.io/r/kartikkumar/sml)

`Simple Maths Library (SML)` is a C++ template library that provides some basic mathematics functionality.

Features
------

  - Header-only
  - Generic linear algebra functions
  - Basic constants
  - Full suite of tests

Requirements
------

To install this project, please ensure that you have installed the following (install guides are provided on the respective websites):

  - [Git](http://git-scm.com)
  - A C++ compiler, e.g., [GCC](https://gcc.gnu.org/), [clang](http://clang.llvm.org/), [MinGW](http://www.mingw.org/)
  - [CMake](http://www.cmake.org)
  - [Doxygen](http://www.doxygen.org "Doxygen homepage") (optional)

In addition, `SML` depends on the following libraries:

  - [CATCH](https://www.github.com/philsquared/Catch)
  - [Eigen](http://eigen.tuxfamily.org/) (optional)

These dependencies will be downloaded and configured automatically if they are not already present locally (requires an internet connection).

Installation
------

Run the following commands to download, build, and install this project.

    git clone https://www.github.com/kartikkumar/sml
    cd sml
    git submodule init && git submodule update
    mkdir build && cd build
    cmake ..
    cmake --build .

To install the header files and libraries, run the following from within the `build` directory:

    make install

Note that dependencies are installed by fetching them online, in case they cannot be detected on your local system. If the build process fails, check the error log given. Typically, building fails due to timeout. Simply run the `cmake --build .` command once more.

Build options
-------------

You can pass the follow command-line options when running `CMake`:

  - `-DBUILD_DOCS=[on|off (default)]`: build the [Doxygen](http://www.doxygen.org "Doxygen homepage") documentation ([LaTeX](http://www.latex-project.org/) must be installed with `amsmath` package)
  - `-DBUILD_TESTS`=[on|off (default)]: build tests (execute tests from build-directory using `ctest -V`)
  - `-DBUILD_WITH_EIGEN=[on|off (default)]`: build tests using [Eigen](http://eigen.tuxfamily.org/) (execute tests from build-directory using `ctest -V`)
  - `-DRUN_TEST_COVERAGE=[on|off (default)]`: run test coverage analysis using [Gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html) and [LCOV](http://ltp.sourceforge.net/coverage/lcov.php) (execute test coverage analysis from build-directory using `make ${MYPROJ_TEST_COVERAGE}`, where the variable `MYPROJ_TEST_COVERAGE` should be passed to CMake)
  - `-DBUILD_SHARED_LIBS=[on|off (default)]`: build shared libraries instead of static
  - `-DCMAKE_INSTALL_PREFIX`: set path prefix for install script (`make install`); if not set, defaults to usual locations
  - `-DFORCE_DEPENDENCIES_BUILD=[on|off (default)]`: force local build of dependencies, instead of first searching system-wide using `find_package()`
  - `-DMYLIB_PATH[=build_dir/lib (default]`: set library path
  - `-DMYBIN_PATH[=build_dir/bin (default]`: set binary path
  - `-DMYTEST_PATH[=build_dir/tests (default]`: set tests path

Contributing
------------

Once you've made your great commits:

  1. [Fork](https://github.com/kartikkumar/sml/fork) `SML`
  2. Create a topic branch - `git checkout -b my_branch`
  3. Push to your branch - `git push origin my_branch`
  4. Create a [Pull Request](http://help.github.com/pull-requests/) from your branch
  5. That's it!

Disclaimer
------

The copyright holders are not liable for any damage(s) incurred due to improper use of `SML`.

TODO
------

  - Extend test suite
  - Figure out better way (avoiding code duplication) to build `STL`-based and `Eigen`-based tests in the same build tree
  - Add version detection in `CMake` module so that find_package respects minimum version required.
  - Find a way to provide an option to clean installation.
