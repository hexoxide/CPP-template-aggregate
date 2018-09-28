project(stdList)

file(GLOB STDLIST_SRC
    "*.h"
    "*.cpp"
)

add_executable(stdList ${STDLIST_SRC})

target_link_libraries(stdList)