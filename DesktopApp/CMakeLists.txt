cmake_minimum_required(VERSION 3.1.0)

project(AlchemyControlDesktop)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS
    "gui"
 )

set(HEADERS
    include/mainwindow.h

    include/ListItem.h
    include/ListWidget.h
    include/ImageWidget.h
)

set(SOURCES
    source/main.cc
    source/mainwindow.cc

    source/ListItem.cc
    source/ListWidget.cc
    source/ImageWidget.cc
)

set(FORMS
    gui/mainwindow.ui
    gui/listitem.ui
)

set(RESOURCES
    resources/fonts/fonts.qrc
    resources/icons/icons.qrc
    resources/styles/styles.qrc
)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(AlchemyControlDesktop
    ${HEADERS}
    ${SOURCES}
    ${FORMS}
    ${RESOURCES}
)

target_include_directories(AlchemyControlDesktop
    PUBLIC
        "include"
)

target_link_libraries(AlchemyControlDesktop
    Qt5::Widgets
)

