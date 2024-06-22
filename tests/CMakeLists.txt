set(TEST_NAME armazen-test)
file(GLOB TEST_LIST "${PROJECT_SOURCE_DIR}/tests/*.cpp")

message(test_list=${TEST_LIST})
# add googletest for test framework
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)


add_executable(${TEST_NAME} ${TEST_LIST})
target_compile_features(${TEST_NAME} PRIVATE cxx_std_23)
target_link_libraries(${TEST_NAME} PRIVATE ${ARMAZEN_LIBRARY_NAME} GTest::gtest_main)
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

include(GoogleTest)

# this will add a POST BUILD command
# when the build succeeded, the tests will run
add_custom_command(
    TARGET ${TEST_NAME}
    POST_BUILD
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure --gtest_catch_exceptions=1
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running tests..."
)
