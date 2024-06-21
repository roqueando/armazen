set(ARMAZEN_BIN_OUTPUT_NAME armazen)

# Armazen will only have one executable for most of things so we will add the executable here
add_executable(${ARMAZEN_BINARY_NAME} main.cpp)

# linking core library to binary
target_link_libraries(${ARMAZEN_BINARY_NAME} PUBLIC ${ARMAZEN_LIBRARY_NAME})

# adding features from C++ 23
target_compile_features(${ARMAZEN_BINARY_NAME} PRIVATE cxx_std_23) 

# when compiling set the binary to project name

# adding own library and dependencies
file(GLOB HEADER_LIST
  CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/**/*.hpp")
file(GLOB SOURCE_LIST "${PROJECT_SOURCE_DIR}/src/**/*.cpp")

message(ARMAZEN_LIBRARY_NAME="${SOURCE_LIST}")
add_library(${ARMAZEN_LIBRARY_NAME} ${SOURCE_LIST} ${HEADER_LIST})
target_include_directories(${ARMAZEN_LIBRARY_NAME} PUBLIC ../include)
target_compile_features(${ARMAZEN_LIBRARY_NAME} PRIVATE cxx_std_23)

# Use fetch content here to add dependencies

# Argparse for parsing automagically options for CLI
FetchContent_Declare(
  argparse
  GIT_REPOSITORY https://github.com/p-ranav/argparse.git
  GIT_TAG v3.0
)

FetchContent_MakeAvailable(argparse)

# linking the dependencies to libarmazen
target_link_libraries(${ARMAZEN_LIBRARY_NAME} argparse::argparse)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST}
  )
