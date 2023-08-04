cmake_minimum_required(VERSION 3.16)

project(freertos-addons)

add_library(${PROJECT_NAME} STATIC
    c++/Source/cmutex.cpp
    c++/Source/cqueue.cpp
    c++/Source/csemaphore.cpp
    c++/Source/cthread.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    c++/Source/include
)

target_compile_options(${PROJECT_NAME} 
    PUBLIC
    $<$<COMPILE_LANGUAGE:CXX>:-Wno-overloaded-virtual>
#     -Wall
#     -Wextra
#     -Wpedantic
#     -Werror
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    freertos_kernel
)

target_compile_definitions(${PROJECT_NAME} PUBLIC
    -DCPP_FREERTOS_NO_EXCEPTIONS
    -DCPP_FREERTOS_NO_CPP_STRINGS
)
