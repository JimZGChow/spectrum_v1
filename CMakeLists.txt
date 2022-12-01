cmake_minimum_required(VERSION 3.22)
project(spectrum)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/pkg/qt/5.12.8/gcc_64/lib/cmake")

include_directories(${PROJECT_SOURCE_DIR}/inc)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        PrintSupport
        REQUIRED)

add_executable(spectrum main.cpp src/qt/main_widget.cpp
        src/qt/qcustomplot.cpp
        inc/qt/main_widget.h inc/qt/main_widget.ui
        inc/fix/my_math.h inc/qt/qcustomplot.h
        )

target_link_libraries(spectrum
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::PrintSupport
        )

