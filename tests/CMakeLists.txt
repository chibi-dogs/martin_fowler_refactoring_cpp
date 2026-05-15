find_package(GTest REQUIRED)
enable_testing()

add_executable(
        tests
        plays_parse_test.cpp
)
target_link_libraries(
        tests
        GTest::gtest_main
        json_parser
)
  include(GoogleTest)
  gtest_discover_tests(tests)