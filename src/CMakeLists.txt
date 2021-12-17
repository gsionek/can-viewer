set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES
    candevice.cpp
    canframe.cpp
)

set(HEADERS
    candevice.hpp
    canframe.hpp
)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES} ${HEADERS})
add_executable(${CMAKE_PROJECT_NAME} main.cpp ${SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} pthread)
