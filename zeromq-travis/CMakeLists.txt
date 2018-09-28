cmake_minimum_required(VERSION 2.8)

# Check if you're in the root directory of the project, and give an error.
IF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "Please create a dedicated build directory for this load balancer. (You may need remove the CmakeCache.txt and the cache)")
ENDIF()

# GCC-4.8 supports 2011 as newest C++ standard
set(CMAKE_CXX_STANDARD 11)

# set(CMAKE_SKIP_RPATH false)
# set(CMAKE_USE_RELATIVE_PATHS true)
# set(CMAKE_INSTALL_RPATH "$ORIGIN/")

project(examplebin)

# Required headers
include_directories(${CMAKE_SOURCE_DIR}/cppzmq/include)
include_directories(${CMAKE_SOURCE_DIR}/libzmq/include)

# Required libraries
# file (GLOB ZEROMQ_LIBRARIES "libzmq/build/lib/*.so")
find_library(ZEROMQ_LIBRARIES NAMES zmq HINTS "${CMAKE_BINARY_DIR}/lib" DOC "ZeroMQ library")

# link_directories($CMAKE_SOURCE_DIR/libzmq/build/lib)
# add_library(ZEROMQ_LIBRARIES SHARED IMPORTED)
# set_target_properties(ZEROMQ_LIBRARIES PROPERTIES IMPORTED_LOCATION "$CMAKE_SOURCE_DIR/libzmq/build/lib/libzmq.so")

# Source files
set(EXAMPLE_BIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_executable(examplebin ${EXAMPLE_BIN_SRC})
#target_link_libraries(examplebin ${CMAKE_SOURCE_DIR}/libzmq/build/lib/libzmq.a)
target_link_libraries(examplebin ${ZEROMQ_LIBRARIES})