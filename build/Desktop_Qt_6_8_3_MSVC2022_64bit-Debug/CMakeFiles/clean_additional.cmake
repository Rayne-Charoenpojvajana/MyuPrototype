# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "ASIO\\ASIO_autogen"
  "ASIO\\CMakeFiles\\ASIO_autogen.dir\\AutogenUsed.txt"
  "ASIO\\CMakeFiles\\ASIO_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\appMyuPrototype_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appMyuPrototype_autogen.dir\\ParseCache.txt"
  "appMyuPrototype_autogen"
  )
endif()
