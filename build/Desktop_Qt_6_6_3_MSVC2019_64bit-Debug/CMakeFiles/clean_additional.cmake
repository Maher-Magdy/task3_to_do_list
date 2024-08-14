# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\apptask3_to_do_list_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\apptask3_to_do_list_autogen.dir\\ParseCache.txt"
  "apptask3_to_do_list_autogen"
  )
endif()
