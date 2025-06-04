# Install script for directory: C:/Users/User/Documents/NewFolder/MyuPrototype/MyuPrototype/vst3sdk

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/MyuPrototype")
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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/User/Documents/NewFolder/MyuPrototype/MyuPrototype/build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debug/vst3sdk/VSTGUI.build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/User/Documents/NewFolder/MyuPrototype/MyuPrototype/build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debug/vst3sdk/pluginterfaces/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/User/Documents/NewFolder/MyuPrototype/MyuPrototype/build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debug/vst3sdk/base/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/User/Documents/NewFolder/MyuPrototype/MyuPrototype/build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debug/vst3sdk/public.sdk/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/User/Documents/NewFolder/MyuPrototype/MyuPrototype/build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debug/vst3sdk/public.sdk/source/vst/interappaudio/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/User/Documents/NewFolder/MyuPrototype/MyuPrototype/build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debug/vst3sdk/public.sdk/samples/vst-hosting/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/User/Documents/NewFolder/MyuPrototype/MyuPrototype/build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debug/vst3sdk/public.sdk/samples/vst-utilities/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/User/Documents/NewFolder/MyuPrototype/MyuPrototype/build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debug/vst3sdk/public.sdk/samples/vst/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/User/Documents/NewFolder/MyuPrototype/MyuPrototype/build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debug/vst3sdk/public.sdk/source/vst/auv3wrapper/cmake_install.cmake")
endif()

