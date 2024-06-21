cmake_minimum_required(VERSION 3.14)

set(ARMAZEN_PROJECT_NAME Armazen)
set(ARMAZEN_SOURCE_DIR src)
set(ARMAZEN_SOURCE ${ARMAZEN_SOURCE_DIR}/main.cpp)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(ARMAZEN_PROJECT_VERSION 0.1)
set(ARMAZEN_LIBRARY_NAME armazen)
set(ARMAZEN_BINARY_NAME armazen-bin)

# Setting up project name, version, languages and description
project(
  ${ARMAZEN_PROJECT_NAME}
  VERSION ${ARMAZEN_PROJECT_VERSION}
  DESCRIPTION "A database for structured logs"
  LANGUAGES CXX)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_CXX_EXTENSIONS OFF)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
  include(CTest) 
endif()

include(FetchContent) # this things save lives, but it has more options like CPM

# library directory
add_subdirectory(src)


if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()
