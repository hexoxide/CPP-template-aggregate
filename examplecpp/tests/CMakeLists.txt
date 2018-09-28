PROJECT(Example_tests)

SET(
    EXAMPLE_TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/TestLib.cxx
)
include_directories(${CMAKE_SOURCE_DIR}/examplelib/include )

FIND_PACKAGE(
    Boost 1.54 COMPONENTS 
    unit_test_framework 
    REQUIRED
)

ADD_EXECUTABLE(Tests ${EXAMPLE_TEST_SOURCES})

TARGET_LINK_LIBRARIES(
    Tests
    ExampleLib
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

ADD_TEST(ExampleTest Tests)