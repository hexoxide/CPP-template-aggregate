project(mallocnew)

file(GLOB MALLOC_NEW_SRC
    "*.h"
    "*.cpp"
)

add_executable(mallocnew ${MALLOC_NEW_SRC})

target_link_libraries(mallocnew)