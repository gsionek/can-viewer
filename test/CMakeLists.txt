enable_testing()

set(SOURCES 
tst_candevice.cpp
)

set(BINARY ${CMAKE_PROJECT_NAME}_tst)
add_executable(${BINARY} ${SOURCES})

target_link_libraries(${BINARY}
 gtest_main     # provides entry point for executing tests
 ${CMAKE_PROJECT_NAME}_lib
)

include(GoogleTest)
gtest_discover_tests(${BINARY})
