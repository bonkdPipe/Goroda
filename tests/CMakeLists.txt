include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(goroda_test "goroda_test.cpp")

target_link_libraries(goroda_test
 PRIVATE
  GTest::GTest
  city_game)

find_package(Catch2 CONFIG REQUIRED)
  target_link_libraries(goroda_test PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)

add_test(goroda_gtest goroda_test)

add_test(NAME script_test
  COMMAND "${CMAKE_CURRENT_LIST_DIR}/run_test.sh"
  WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")