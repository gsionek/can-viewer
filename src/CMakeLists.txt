set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES
    main.cpp
    candevice.cpp
)

set(HEADERS
    candevice.hpp
)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES} ${HEADERS})
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
