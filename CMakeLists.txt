cmake_minimum_required(VERSION 3.18)

set(ARMAZEN_PROJECT_NAME Armazen)
set(ARMAZEN_SOURCE_DIR src)
set(ARMAZEN_SOURCE ${ARMAZEN_SOURCE_DIR}/main.cpp)
set(CMAKE_CXX_STANDARD 17)
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

set(ARMAZEN_BIN_OUTPUT_NAME armazen)

# Armazen will only have one executable for most of things so we will add the executable here
add_executable(${ARMAZEN_BINARY_NAME} src/main.cpp)

# linking core library to binary
target_link_libraries(${ARMAZEN_BINARY_NAME} PUBLIC ${ARMAZEN_LIBRARY_NAME})

# adding features from C++ 23
target_compile_features(${ARMAZEN_BINARY_NAME} PRIVATE cxx_std_23) 

# when compiling set the binary to project name
set_target_properties(${ARMAZEN_BINARY_NAME} PROPERTIES OUTPUT_NAME armazen)

add_subdirectory(src)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()
