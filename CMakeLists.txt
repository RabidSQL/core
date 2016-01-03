cmake_minimum_required(VERSION 3.2.2)
project(RabidSQL)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -std=c++0x")
find_package(Qt5 REQUIRED COMPONENTS core gui widgets PATHS /Users/Chelsea/Qt/5.5/clang_64/lib/cmake REQUIRED)
LINK_DIRECTORIES(
    /usr/local/mysql/lib
)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(BUILD_TESTS, true)
add_subdirectory(backend build/backend)
add_subdirectory(ui/qt build/ui)

add_executable(${PROJECT_NAME} main.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
    Backend
    UI
    MySQL
    pthread
    Qt5::Core
    Qt5::Widgets
)
