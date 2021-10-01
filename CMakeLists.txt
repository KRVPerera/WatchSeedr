project(WatchSeedr)
cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(WatchSeedr cMain.cpp cMain.h cApp.cpp cApp.h)

target_link_libraries(WatchSeedr ${wxWidgets_LIBRARIES})