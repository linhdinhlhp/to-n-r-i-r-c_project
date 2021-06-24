# Install script for directory: /Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/bkc" TYPE FILE FILES
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_basic_types.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_constants.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_constructors.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_datatype.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_error.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_interface.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_iqueue.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_istack.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_ivec.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_queue.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_topology.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_visitor.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_paths.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_rvec.h"
    "/Users/linhdinhiutat/Documents/linhcute/project_trr/cgraph/cgraph_types_internal.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/linhdinhiutat/Documents/linhcute/project_trr/b/cgraph/libcgraph.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcgraph.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcgraph.a")
    execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcgraph.a")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/linhdinhiutat/Documents/linhcute/project_trr/b/cgraph/examples/cmake_install.cmake")
  include("/Users/linhdinhiutat/Documents/linhcute/project_trr/b/cgraph/ctc/cmake_install.cmake")

endif()

