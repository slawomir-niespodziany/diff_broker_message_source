include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/releases/download/v1.17.0/googletest-1.17.0.tar.gz
        DOWNLOAD_EXTRACT_TIMESTAMP ON)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

# test_message_source
add_executable(test_message_source TestMessageSource.cpp)

set_property(TARGET test_message_source PROPERTY CXX_STANDARD 17)
set_property(TARGET test_message_source PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(test_message_source diff::diff GTest::gtest_main message_source)

gtest_discover_tests(test_message_source)
