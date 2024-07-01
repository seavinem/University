# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\mvc_hospital_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\mvc_hospital_autogen.dir\\ParseCache.txt"
  "mvc_hospital_autogen"
  )
endif()
