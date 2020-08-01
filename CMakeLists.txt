CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
project(text_editor LANGUAGES CXX)
find_package(Qt5Widgets)

add_executable(text_editor main.cpp mainwindow.h mainwindow.cpp)
target_link_libraries(text_editor PUBLIC Qt5::Widgets)