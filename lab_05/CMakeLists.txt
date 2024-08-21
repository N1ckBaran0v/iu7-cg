cmake_minimum_required(VERSION 3.16)

project(app.exe VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

include_directories(${CMAKE_SOURCE_DIR}/interface)
include_directories(${CMAKE_SOURCE_DIR}/field)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS PrintSupport)

add_executable(app.exe
    field/dot.cpp 
    field/field.cpp 
    field/figure.cpp 
    field/mypixelmap.cpp 
    field/pixel.cpp 
    interface/mainwindow.cpp 
    interface/main.cpp
)

target_link_libraries(app.exe PRIVATE Qt6::Core)
target_link_libraries(app.exe PRIVATE Qt6::Widgets)
target_link_libraries(app.exe PRIVATE Qt6::PrintSupport)
