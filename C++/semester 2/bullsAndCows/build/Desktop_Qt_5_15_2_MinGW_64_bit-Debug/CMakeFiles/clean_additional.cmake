# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\bullsAndCows_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\bullsAndCows_autogen.dir\\ParseCache.txt"
  "bullsAndCows_autogen"
  )
endif()
