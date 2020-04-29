cmake_minimum_required(VERSION 3.13)
project(lab_01)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/home/sakerini/Qt/5.14.1/gcc_64/lib/cmake")
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)

add_executable(lab_01_deb main.cpp
        mainwindow.cpp
        mainwindow.ui
        exceptionhandling/Error.cpp
        io/StreamReader.cpp
        geometry/Point.cpp
        geometry/Edge.cpp
        geometry/models/Model3d.cpp
        controller/MainController.cpp
        ui/Drawer.cpp
        controller/actions/actions.cpp controller/actions/actions.h)
#[[
mainwindow.h
exceptionhandling/Error.h
io/StreamReader.h
geometry/Point.h
geometry/Edge.h
geometry/models/Model3d.h
controller/MainController.h
ui/Drawer.h

]]

target_link_libraries(lab_01_deb Qt5::Core)
target_link_libraries(lab_01_deb Qt5::Widgets)
target_link_libraries(lab_01_deb Qt5::Quick)
