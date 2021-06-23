# Install script for directory: /Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/bkc/ctc" TYPE FILE FILES
    "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/array.h"
    "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/common.h"
    "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/deque.h"
    "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/hashset.h"
    "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/hashtable.h"
    "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/list.h"
    "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/pqueue.h"
    "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/queue.h"
    "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/ring_buffer.h"
    "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/slist.h"
    "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/stack.h"
    "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/treeset.h"
    "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/treetable.h"
    "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/tsttable.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/bkc/ctc/my" TYPE FILE FILES "/Users/linhdinhiutat/Documents/linhcute/Project_trr/cgraph/ctc/my/hsi.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/linhdinhiutat/Documents/linhcute/Project_trr/b/cgraph/ctc/libcollectc.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcollectc.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcollectc.a")
    execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcollectc.a")
  endif()
endif()

