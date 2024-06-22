# adding own library and dependencies
file(GLOB HEADER_LIST
  CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/**/*.hpp")
file(GLOB SOURCE_LIST "${PROJECT_SOURCE_DIR}/src/**/*.cpp")

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

