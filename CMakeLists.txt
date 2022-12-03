cmake_minimum_required(VERSION 3.22)
project(spectrum)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/pkg/qt/5.12.8/gcc_64/lib/cmake")

include_directories(${PROJECT_SOURCE_DIR}/inc)

link_directories(${PROJECT_SOURCE_DIR}/lib)
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        PrintSupport
        REQUIRED)

add_executable(spectrum main.cpp src/qt/main_widget.cpp
        src/qt/qcustomplot.cpp  src/fix/fftw.cpp
        inc/qt/main_widget.h inc/qt/main_widget.ui
        inc/fix/my_math.h inc/qt/qcustomplot.h
        inc/draw/draw.h inc/fix/dataBuffer.h
        inc/fix/fftw_common.h src/draw/draw.cpp
        inc/fix/source_creator.h src/fix/source_creator.cpp
        inc/device/sdrDevice.h inc/fix/log.h src/device/sdrDevice.cpp
        src/fix/log.cpp src/fix/my_math.cpp)

target_link_libraries(spectrum
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::PrintSupport
        fftw3f
        pthread
        iio
        ad9361
        )

