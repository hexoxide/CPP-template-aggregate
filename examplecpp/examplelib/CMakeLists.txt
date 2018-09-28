project(ExampleLib)

set (
    EXAMPLE_LIB_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Foo.cxx
)

set (
    EXAMPLE_LIB_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Foo.h
)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(ExampleLib SHARED ${EXAMPLE_LIB_SRC} ${EXAMPLE_LIB_HEADERS})

