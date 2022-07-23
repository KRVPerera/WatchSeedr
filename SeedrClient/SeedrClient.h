//
// Created by Rukshan Perera on 2022-07-15.
//

#ifndef SEEDRDOWNLOADMANAGER_SEEDRCLIENT_H
#define SEEDRDOWNLOADMANAGER_SEEDRCLIENT_H

#include<string>

#include <curl/curl.h>

class SeedrClient {
private:
    const std::string _restLink = "https://www.seedr.cc/rest";
    std::string _userName;
    std::string _password;
    CURL *_curl;

public:
    SeedrClient(std::string userName, std::string password);
    ~SeedrClient();
    int test();
};


#endif //SEEDRDOWNLOADMANAGER_SEEDRCLIENT_H
