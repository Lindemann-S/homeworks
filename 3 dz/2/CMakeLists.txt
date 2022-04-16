cmake_minimum_required(VERSION 3.0.0)

project(infinity_attempt)

set(SOURCES
        main.cpp
        myStack2.cpp
        postfix.cpp
)

set(HEADERS
        myStack2.h
        postfix.h
)

add_executable(postfix ${SOURCES} ${HEADERS})
set_target_properties(
        postfix PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)
