cmake_minimum_required(VERSION 3.5.0)

project(gui_db-cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/test)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
find_package(SOCI REQUIRED COMPONENTS core mysql)

include_directories(
    ${wxWidgets_INCLUDE_DIRS} 
    gui/include 
    data/include
)

set(SOURCES
    gui/source/user-dialog.h
)

add_executable(
    gui_db 
    main.cpp 
    
    data/source/Person.cpp 
    data/source/DAO.cpp    
    data/source/DAL.cpp

    gui/source/data-view.cpp
    gui/source/menubar.cpp 
    gui/source/main-frame.cpp
    gui/source/user-dialog.cpp
    gui/source/unique-dialog.cpp
)


include(${wxWidgets_USE_FILE})

target_link_libraries(gui_db 
    ${wxWidgets_LIBRARIES} 
    SOCI::soci_core 
    SOCI::soci_mysql
)