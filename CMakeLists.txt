cmake_minimum_required(VERSION 3.16)

project(freertos-addons)

add_library(
  ${PROJECT_NAME} STATIC
  c++/Source/ccondition_variable.cpp
  c++/Source/cqueue.cpp
  c++/Source/cthread.cpp
  c++/Source/cworkqueue.cpp
  c++/Source/cevent_groups.cpp
  c++/Source/cread_write_lock.cpp
  c++/Source/ctickhook.cpp
  c++/Source/cmem_pool.cpp
  c++/Source/csemaphore.cpp
  c++/Source/ctimeout.cpp
  c++/Source/cmutex.cpp
  c++/Source/ctasklet.cpp
  c++/Source/ctimer.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC c++/Source/include)

target_compile_options(
  ${PROJECT_NAME} PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-Wno-overloaded-virtual>
  # -Wall -Wextra -Wpedantic -Werror
)

target_link_libraries(${PROJECT_NAME} PUBLIC freertos_kernel)

target_compile_definitions(
  ${PROJECT_NAME} PUBLIC -DCPP_FREERTOS_NO_EXCEPTIONS
                         -DCPP_FREERTOS_NO_CPP_STRINGS
)
