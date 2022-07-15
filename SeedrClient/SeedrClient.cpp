//
// Created by Rukshan Perera on 2022-07-15.
//

#include "SeedrClient.h"

#include <string>
#include <iostream>

#include <curl/curl.h>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int SeedrClient::test()
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.seedr.cc/rest/folder");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_USERPWD, "rukshan.viduranga@gmail.com:0432-3527");
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        std::cout << readBuffer << std::endl;
    }
    return 0;
}
