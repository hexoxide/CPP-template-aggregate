cmake_minimum_required(VERSION 3.11)
IF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    # Check if you're in the root directory of the project, and give an error.
    MESSAGE(FATAL_ERROR "Please create a dedicated build directory for this load balancer. (You may need remove the CmakeCache.txt and the cache)")
ENDIF()

SET(CMAKE_CXX_STANDARD 17)

add_subdirectory(pointers)
add_subdirectory(stdlist)
add_subdirectory(malloc)
add_subdirectory(mallocnew)