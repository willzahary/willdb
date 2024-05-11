include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(
    schema-test
    schema-test.cpp
)
target_link_libraries(
    schema-test
    GTest::gtest_main
    willdb
)

include(GoogleTest)
gtest_discover_tests(schema-test)