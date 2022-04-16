cmake_minimum_required(VERSION 3.0.0)

project(infinity_attempt)

set(SOURCES
        main.cpp
        heapSort.cpp
        findMax.cpp
)

set(HEADERS
        heapSort.h
        findMax.h
)

add_executable(max_element ${SOURCES} ${HEADERS})
set_target_properties(
        max_element PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)
