# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# tests_src at CMakeLists.txt:19 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/CS 225/CS225_Matchmaking/tests/*.cpp")
set(OLD_GLOB
  "/workspaces/CS 225/CS225_Matchmaking/tests/compatible_tests.cpp"
  "/workspaces/CS 225/CS225_Matchmaking/tests/populate_tests.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/CS 225/CS225_Matchmaking/build/CMakeFiles/cmake.verify_globs")
endif()
