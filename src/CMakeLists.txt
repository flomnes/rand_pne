project(rand_pne)
cmake_minimum_required(VERSION 3.15)

add_library(rand
  rand.cpp
  rand.hpp)

add_executable(main main.cpp)
target_link_libraries(main rand)

if (MSVC)
  set(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS 1)
  set(CMAKE_INSTALL_UCRT_LIBRARIES 1)
  include(InstallRequiredSystemLibraries)
endif()

install(TARGETS main DESTINATION bin)
