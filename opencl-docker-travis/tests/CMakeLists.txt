PROJECT(tests)

file(GLOB_RECURSE EXAMPLE_TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
include_directories(${CMAKE_SOURCE_DIR}/lib/include)

find_package(
    Boost 1.53 COMPONENTS
    unit_test_framework
    REQUIRED
)

add_executable(tests ${EXAMPLE_TEST_SOURCES})

target_link_libraries(
    tests
    lib
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    ${ZeroMQ_LIBRARY}
)


add_test(Test tests)
