cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(jeMoeder)

find_package(Boost 1.53.0 COMPONENTS system timer REQUIRED)
#include_directories(${Boost_INCLUDE_DIR})
include_directories(include)

if(WIN32) 
	set(PLATFORM_SRC src/windowsstuff.cpp)
else()
	set(PLATFORM_SRC src/linuxstuff.cpp)
endif()

set(TUTORIAL_SRC
	src/main.cpp
	${PLATFORM_SRC}
)

if(WIN32) 
	set(PLATFORM_HEADERS include/windowsstuff.hpp)
else()
	set(PLATFORM_HEADERS include/linuxstuff.hpp)
endif()

set(TUTORIAL_HEADERS
	include/main.hpp
	${PLATFORM_HEADERS}
)

add_executable(tutorial ${TUTORIAL_SRC} ${TUTORIAL_HEADERS})
target_link_libraries(tutorial ${Boost_LIBRARIES})