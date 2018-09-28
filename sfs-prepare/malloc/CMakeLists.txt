project(malloc)

file(GLOB MALLOC_SRC
    "*.h"
    "*.cpp"
)

add_executable(malloc ${MALLOC_SRC})

target_link_libraries(malloc)