add_library(SeedrClient SeedrClient.cpp SeedrClient.h)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

include_directories(${CURL_INCLUDE_DIR})

#target_link_libraries(SeedrClientTest ${CURL_LIBRARIES})
