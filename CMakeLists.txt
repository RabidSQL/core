cmake_minimum_required(VERSION 3.2.2)
project(RabidSQL)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -std=c++0x")
LINK_DIRECTORIES(
    /usr/local/mysql/lib
)

set(BUILD_TESTS, true)
add_subdirectory(backend build/backend)
add_subdirectory(ui/qt build/ui)

add_executable(${PROJECT_NAME} main.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
    Backend
    UI
    MySQL
    pthread
)
