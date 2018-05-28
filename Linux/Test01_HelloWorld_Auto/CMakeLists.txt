cmake_minimum_required(VERSION 3.5)

project(ceres-hello-world)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Ceres REQUIRED)
message("CERES_LIBRARIES = ${CERES_LIBRARIES}")
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CERES_INCLUDE_DIRS})

set(SOURCES
    helloworld.cpp)

add_executable(ceres-helloworld-auto ${SOURCES})
target_link_libraries(ceres-helloworld-auto ${CERES_LIBRARIES})
