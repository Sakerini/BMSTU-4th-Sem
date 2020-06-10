cmake_minimum_required(VERSION 3.14)
project(lab_04)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/home/sakerini/Qt/5.14.1/gcc_64/lib/cmake")
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)

add_executable(lab_04
        delay.cpp
        delay.h
        doors.cpp
        doors.h
        error.h
        lift.cpp
        lift.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui)

target_link_libraries(lab_04 Qt5::Core)
target_link_libraries(lab_04 Qt5::Widgets)
target_link_libraries(lab_04 Qt5::Quick)
