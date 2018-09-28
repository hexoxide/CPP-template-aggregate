project(bin)

file(GLOB_RECURSE EXAMPLE_BIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/lib/include)

add_executable(bin ${EXAMPLE_BIN_SRC})

target_link_libraries(bin lib ${ZeroMQ_LIBRARY})
