# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appRun_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appRun_autogen.dir/ParseCache.txt"
  "appRun_autogen"
  )
endif()
