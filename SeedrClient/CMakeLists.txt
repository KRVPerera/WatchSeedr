find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz)
FetchContent_MakeAvailable(json)

#find_package(nlohmann_json 3.10.5 REQUIRED)

target_include_directories(nlohmann_json INTERFACE ${nlohmann_json_SOURCE_DIR}/nlohmann_json/include)

add_library(SeedrClient SeedrClient.cpp SeedrClient.h)

target_link_libraries(SeedrClient PRIVATE nlohmann_json::nlohmann_json)

add_executable(SeedrClientTest SeedrClientTest.cpp)
target_link_libraries(SeedrClientTest PRIVATE ${CURL_LIBRARIES} PRIVATE nlohmann_json::nlohmann_json PRIVATE Catch2::Catch2WithMain)

#include_directories(nlohmann_json::nlohmann_json)
#include_directories(${NLOHMANN_JSON_INCLUDE_DIR})

