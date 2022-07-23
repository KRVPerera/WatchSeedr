//
// Created by Rukshan Perera on 2022-07-15.
//

#include "SeedrClient.h"

#include <string>
#include <iostream>
#include <stdexcept>

#include <curl/curl.h>
#include <nlohmann/json.hpp>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string *) userp)->append((char *) contents, size * nmemb);
    return size * nmemb;
}

SeedrClient::SeedrClient(std::string userName, std::string password) : _userName(userName), _password(password) {
    _curl = curl_easy_init();
    if (!_curl) {
        throw std::runtime_error("Seedr client initialization failed");
    }
}

SeedrClient::~SeedrClient() {
    curl_easy_cleanup(_curl);
}

int SeedrClient::test() {
    using json = nlohmann::json;
    CURLcode res;
    std::string readBuffer;


    if (_curl) {
        curl_easy_setopt(_curl, CURLOPT_URL, "https://www.seedr.cc/rest/folder");
        curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &readBuffer);
        std::string userPassword = _userName + ":" + _password;
        curl_easy_setopt(_curl, CURLOPT_USERPWD, userPassword.c_str());

        json r = readBuffer;

        std::cout << r << std::endl;
    }
    return 0;
}
