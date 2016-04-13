cmake_minimum_required(VERSION 2.8)
project(status_value CXX)

function(add_compile_flag value)
  message(status "Building with ${value}")
  foreach(variable CMAKE_C_FLAGS CMAKE_CXX_FLAGS)
    set(${variable} "${${variable}} ${value}" PARENT_SCOPE)
  endforeach(variable)
endfunction()

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND
    CMAKE_GENERATOR STREQUAL "Ninja")
  add_compile_flag("-fcolor-diagnostics")
endif()

add_compile_flag("-std=c++14")

add_executable(test test.cc)
