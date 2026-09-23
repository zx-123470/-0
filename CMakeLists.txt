cmake_minimum_required(VERSION 3.21)
project(chapter0 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(chapter0
	src/main.cpp
	src/QtWidgetsApplication1.cpp
	src/adddialog.cpp
	header/adddialog.h
	header/QtWidgetsApplication1.h
	ui/adddialog.ui
	ui/QtWidgetsApplication1.ui
)

target_include_directories(chapter0 PRIVATE header)

target_link_libraries(chapter0 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(WIN32)
	set_target_properties(chapter0 PROPERTIES WIN32_EXECUTABLE TRUE)
endif()