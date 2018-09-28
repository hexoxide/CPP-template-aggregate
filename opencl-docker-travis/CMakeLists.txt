cmake_minimum_required(VERSION 2.8)

# Check if you're in the root directory of the project, and give an error.
IF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	MESSAGE(FATAL_ERROR "Please create a dedicated build directory for this load balancer. (You may need remove the CmakeCache.txt and the cache)")
ENDIF()

SET(CMAKE_CXX_STANDARD 11)

OPTION(ENABLE_TESTS "Enable unit tests" ON)

# determine if host operating system is  mac osx
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(MACOSX TRUE)
endif()

add_subdirectory(lib)

add_subdirectory(bin)

IF(ENABLE_TESTS)
	ENABLE_TESTING()

	add_subdirectory(tests)
ENDIF()
