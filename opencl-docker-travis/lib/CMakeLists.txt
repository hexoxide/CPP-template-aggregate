project(lib)

#Configure zeroMQ for older version of cmake (<4.2)
find_package(PkgConfig)
pkg_check_modules(PC_ZeroMQ QUIET zmq)
if(MACOSX)
	message("Detected MacOSX")
	set(CMAKE_MACOSX_RPATH TRUE)
	# Manually set linker flags for compiling with ZeroMQ
	set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -L/usr/local/lib -lzmq")
else()
	message("System is Linux or Windows")
	find_path(ZeroMQ_INCLUDE_DIR
		NAMES zmq.h
		PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
	)
	find_library(ZeroMQ_LIBRARY
		NAMES zmq
		PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
	)
endif()

file(GLOB_RECURSE EXAMPLE_LIB_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

file(GLOB_RECURSE EXAMPLE_LIB_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include ${ZeroMQ_INCLUDE_DIR})
add_library(lib SHARED ${EXAMPLE_LIB_SRC} ${EXAMPLE_LIB_HEADERS} ${ZeroMQ_LIBRARY})