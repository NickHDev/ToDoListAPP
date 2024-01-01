cmake_minimum_required(VERSION 3.16)

project(toDoList VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Qt6 package
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
qt_standard_project_setup()

# Create the executable
add_executable(toDoList
    mainwindow.cpp
    main.cpp
)

# Link against the Qt6 libraries
target_link_libraries(toDoList PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

set_target_properties(toDoList PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON)
    
install(TARGETS toDoList
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static)