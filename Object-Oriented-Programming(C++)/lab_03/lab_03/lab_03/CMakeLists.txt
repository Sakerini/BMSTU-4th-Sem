cmake_minimum_required(VERSION 3.14)
project(lab_03)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/home/sakerini/Qt/5.14.1/gcc_64/lib/cmake")
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)

add_executable(lab_03 main.cpp
        mainwindow.cpp
        mainwindow.ui

        geometry/model/model3d.cpp
        geometry/model/model3d.h

        geometry/point.cpp
        geometry/point.h

        geometry/edge.cpp
        geometry/edge.h

        exception/error.h

        io/readerimplementator_stdio.cpp
        io/readerimplementator_stdio.h

        ui/drawer.cpp
        ui/drawer.h

        command/command.h

        geometry/model/imodel.h
        geometry/ipoint.h
        geometry/iedge.h
        io/ireaderimplementator.h

        factory/iabstractfactory.h

        io/reader.cpp io/reader.h

        io/ireader.h

        controller/maincontroller.cpp
        controller/maincontroller.h

        patterns/observer/observer.h

        patterns/observer/subject.h
        patterns/observer/subject.cpp command/iappcommand.cpp command/iappcommand.h factory/model3dfactory.cpp factory/model3dfactory.h command/scalecommand.cpp command/scalecommand.h command/rotatecommand.cpp command/rotatecommand.h command/transfercommand.cpp command/transfercommand.h ui/imediator.h ui/iparticipant.h ui/scene/sceneobjectcomposite.cpp ui/scene/sceneobjectcomposite.h ui/scene/sceneobject.cpp ui/scene/sceneobject.h ui/camera/camera.cpp ui/camera/camera.h datamanager/viewerdatamanager.cpp datamanager/viewerdatamanager.h controller/icommandexecuteimplementer.h controller/loadimplementater.cpp controller/loadimplementater.h controller/groupimplementater.cpp controller/groupimplementater.h controller/drawimplementater.cpp controller/drawimplementater.h controller/icommandexecute.h controller/executor.cpp controller/executor.h controller/motionimplementer.cpp controller/motionimplementer.h ui/drawermediator.cpp ui/drawermediator.h geometry/model/builder/director.h geometry/model/builder/imodelbuilder.h geometry/model/builder/3dmodelBuilder.h geometry/model/builder/3dmodelBuilder.cpp)
target_link_libraries(lab_03 Qt5::Core)
target_link_libraries(lab_03 Qt5::Widgets)
target_link_libraries(lab_03 Qt5::Quick)
