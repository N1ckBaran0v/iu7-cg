cmake_minimum_required(VERSION 3.16)

project(app.exe VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(app.exe
    Circle.cpp
    Dot.cpp 
    MainWindow.cpp
    Surface.cpp
    main.cpp
)

target_link_libraries(app.exe PRIVATE Qt6::Core)
target_link_libraries(app.exe PRIVATE Qt6::Widgets)