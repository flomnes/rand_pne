project(rand_pne)
cmake_minimum_required(VERSION 3.15)

add_library(rand
  rand.cpp
  rand.hpp)

add_executable(main main.cpp)
target_link_libraries(main rand)
