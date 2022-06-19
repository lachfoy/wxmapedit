cmake_minimum_required(VERSION 3.23.2)

project(wxmapedit)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})
include_directories(${PROJECT_NAME} include)

add_executable(${PROJECT_NAME}
    src/Main.cpp
    src/App.cpp
    src/map.c
    src/MapCanvas.cpp
    src/MapWrapper.cpp
    src/TileCanvas.cpp
    src/ObjectList.cpp
    src/ImageLoader.cpp
)

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})