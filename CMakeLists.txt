project(SeedrDownloadManager)
cmake_minimum_required(VERSION 3.9.2)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v3.0.0
        )

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_subdirectory(SeedrClient)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/SeedrClient)

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE src
                            ${PROJECT_SOURCE_DIR}/SeedrClient)

target_link_libraries(${PROJECT_NAME}
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component # Not needed for this example.
        ${CURL_LIBRARIES}
        SeedrClient
        )


set(CMAKE_CXX_FLAGS_INIT "-Werror -Wall -Wextra -Wpedantic")
#set(CMAKE_CXX_FLAGS_INIT "--coverage -fno-exceptions -g")

# toolchain file for use with gdb
#set(CMAKE_CXX_FLAGS_DEBUG_INIT "-fsanitize=address,undefined -fsanitize-undefined-trap-on-error")
#set(CMAKE_EXE_LINKER_FLAGS_INIT "-fsanitize=address,undefined -static-libasan")

if (EMSCRIPTEN)
    string(APPEND CMAKE_CXX_FLAGS " -s USE_PTHREADS")
    string(APPEND CMAKE_EXE_LINKER_FLAGS " -s ASYNCIFY")
    string(APPEND CMAKE_EXE_LINKER_FLAGS " -s PROXY_TO_PTHREAD")

    foreach(file "index.html" "run_webassembly.py")
        configure_file("src/${file}" ${file})
    endforeach(file)
endif()