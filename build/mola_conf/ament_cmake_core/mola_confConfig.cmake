# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_mola_conf_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED mola_conf_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(mola_conf_FOUND FALSE)
  elseif(NOT mola_conf_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(mola_conf_FOUND FALSE)
  endif()
  return()
endif()
set(_mola_conf_CONFIG_INCLUDED TRUE)

# output package information
if(NOT mola_conf_FIND_QUIETLY)
  message(STATUS "Found mola_conf: 0.0.0 (${mola_conf_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'mola_conf' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT mola_conf_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(mola_conf_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${mola_conf_DIR}/${_extra}")
endforeach()
