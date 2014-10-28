# Copyright (c) 2014, K. Kumar (me@kartikkumar.com)
# All rights reserved.

cmake_minimum_required(VERSION 2.6)
project(SML)

enable_testing()

set(PROJECT_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(SOURCE_PATH "${PROJECT_PATH}/${CMAKE_PROJECT_NAME}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_PATH}/cmake/Modules/")

OPTION(INSTALL_HEADERS          "Install header files" OFF)
OPTION(BUILD_DOCS               "Build docs" OFF)
OPTION(BUILD_TESTS              "Build tests" OFF)
OPTION(BUILD_WITH_EIGEN         "Build tests with Eigen" OFF)

# Set platform-specific compiler flags.
if (WIN32)
  if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /Ox /W3 /FC -D_SCL_SECURE_NO_WARNINGS")
    # We need to force MSVC to use static runtime: 
    # (from http://www.cmake.org/Wiki/CMake_FAQ#Dynamic_Replace).
    foreach(flag_var
          CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
          CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
      # Find all dynamic runtime (MD) references and replace with static (MT)
      if(${flag_var} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
      endif(${flag_var} MATCHES "/MD")
    endforeach(flag_var)
  else()
    set(CMAKE_CXX_FLAGS 
        "${CMAKE_CXX_FLAGS} -Wall -g -Woverloaded-virtual -Wold-style-cast -Wnon-virtual-dtor")
  endif()
else()
  set(CMAKE_CXX_FLAGS 
      "${CMAKE_CXX_FLAGS} -Wall -g -Woverloaded-virtual -Wold-style-cast -Wnon-virtual-dtor")
endif()

# Set CMake build-type. If it not supplied by the user, the default built type is "Release". 
if((NOT CMAKE_BUILD_TYPE) OR (CMAKE_BUILD_TYPE STREQUAL "Release"))
    message(STATUS "WARNING: building release version!")
    set(CMAKE_BUILD_TYPE Release)
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "WARNING: building debug version!")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
endif()

include_directories(AFTER "${PROJECT_PATH}")

# Install header files. Destination is set by CMAKE_INSTALL_PREFIX and defaults to usual locations,
# unless overridden by user.
install(DIRECTORY ${SOURCE_PATH} 
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        FILES_MATCHING PATTERN "*.hpp"
                       PATTERN "Tests" EXCLUDE)

if(BUILD_DOCS)
  find_package(Doxygen)

  if(NOT DOXYGEN_FOUND)
    message(FATAL_ERROR 
            "Doxygen is needed to build the documentation. Please make sure it is installed.")
  endif(NOT DOXYGEN_FOUND)

  configure_file(${PROJECT_PATH}/Doxyfile.in 
                 ${PROJECT_BINARY_DIR}/Doxyfile @ONLY IMMEDIATE)

  # Add a custom target to run Doxygen whenever the project is built.
  # If you do NOT want the documentation to be generated EVERY time you build the project
  # then leave out the 'ALL' keyword from the command below.
  add_custom_target(docs ALL COMMAND ${DOXYGEN_EXECUTABLE} 
                    ${PROJECT_BINARY_DIR}/Doxyfile 
                    SOURCES ${PROJECT_BINARY_DIR}/Doxyfile)
endif(BUILD_DOCS)

if(BUILD_TESTS)
  if(NOT TESTS_PATH)
    set(TESTS_PATH "${PROJECT_BINARY_DIR}/tests")
  endif()

  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TESTS_PATH})

  find_package(CATCH REQUIRED)
  if(NOT APPLE)
    include_directories(SYSTEM AFTER "${CATCH_INCLUDE_DIR}")
  else(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -isystem \"${CATCH_INCLUDE_DIR}\"")
  endif(NOT APPLE)

  set(SML_TESTS
  "${SOURCE_PATH}/Tests/testBasicFunctions.cpp"
  "${SOURCE_PATH}/Tests/testConstants.cpp"
  "${SOURCE_PATH}/Tests/testLinearAlgebra.cpp"
  "${SOURCE_PATH}/Tests/testSml.cpp"
)

  add_executable(sml_tests ${SML_TESTS})
  target_link_libraries(sml_tests)
  add_test(NAME sml_tests COMMAND "${TESTS_PATH}/sml_tests")

  # Build tests using the Eigen library if requested.
  if(BUILD_WITH_EIGEN)
    find_package(Eigen3 REQUIRED)
    if(NOT APPLE)
      include_directories(SYSTEM AFTER "${EIGEN3_INCLUDE_DIR}")
    else(APPLE)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -isystem \"${EIGEN3_INCLUDE_DIR}\"")
    endif(NOT APPLE)

    add_executable(sml_tests_eigen ${SML_TESTS})
    target_link_libraries(sml_tests_eigen)
    add_test(NAME sml_tests_eigen COMMAND "${TESTS_PATH}/sml_tests_eigen")

    string(REPLACE "Algebra" "AlgebraEigenFixedVector" SML_TESTS_EIGEN_FIXED "${SML_TESTS}")
    add_executable(sml_tests_eigen_fixed ${SML_TESTS_EIGEN_FIXED})
    target_link_libraries(sml_tests_eigen_fixed)
    add_test(NAME sml_tests_eigen_fixed COMMAND "${TESTS_PATH}/sml_tests_eigen_fixed")
  endif(BUILD_WITH_EIGEN)  
endif(BUILD_TESTS)
