project(ExampleBin)

set (
    EXAMPLE_BIN_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cxx
)


include_directories(${CMAKE_SOURCE_DIR}/examplelib/include )

add_executable(ExampleBin ${EXAMPLE_BIN_SRC})

target_link_libraries(ExampleBin ExampleLib)