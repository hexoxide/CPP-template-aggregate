project(Pointers)

file(GLOB POINTER_SRC
    "*.h"
    "*.cpp"
)

add_executable(Pointers ${POINTER_SRC})

target_link_libraries(Pointers)