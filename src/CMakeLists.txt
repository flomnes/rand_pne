project(rand_pne)
cmake_minimum_required(VERSION 3.15)

add_library(rand
  rand.cpp
  rand.hpp)

add_executable(main main.cpp)
target_link_libraries(main rand)


if (MSVC)
  include(InstallRequiredSystemLibraries)

  set_target_properties(main
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endif()

install(TARGETS main RUNTIME DESTINATION bin)
