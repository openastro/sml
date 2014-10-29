# Copyright (c) 2014, K. Kumar (me@kartikkumar.com)
# Distributed under the MIT License.
# See accompanying file LICENSE or copy at http://opensource.org/licenses/MIT

if (SML_INCLUDE_DIRS)
  # in cache already
  set(SML_FOUND TRUE)
else (SML_INCLUDE_DIRS)

  find_path(SML_INCLUDE_DIR
    NAMES
      signature_of_sml_library
    PATHS
      /usr/include
      /usr/local/include
      /opt/local/include
      /sw/include
      /usr/local
      ${PROJECT_ROOT}
      ${PROJECT_ROOT}/..      
      PATH_SUFFIXES sml
  )

  set(SML_INCLUDE_DIRS
    ${SML_INCLUDE_DIR}
  )

  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(SML DEFAULT_MSG SML_INCLUDE_DIRS)

  # show the SML_INCLUDE_DIRS variables only in the advanced view
  mark_as_advanced(SML_INCLUDE_DIRS)

endif (SML_INCLUDE_DIRS)