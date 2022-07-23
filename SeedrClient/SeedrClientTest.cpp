//
// Created by Rukshan Perera on 2022-07-15.
//

#include <catch2/catch_test_macros.hpp>
#include "SeedrClient.h"

TEST_CASE("bubbleSort", "[Sort Array]") {
    std::vector<int> sortedVec({-1, 1});
    std::vector<int> unsortedVec({-1, 1});
    REQUIRE(sortedVec == unsortedVec);
}

TEST_CASE("Seedr client", "connection") {
    std::string userName = "";
    std::string passWord = "";
    SeedrClient sc(userName, passWord);
    sc.test();
    std::vector<int> sortedVec({-1, 1});
    std::vector<int> unsortedVec({-1, 1});
    REQUIRE(sortedVec == unsortedVec);
}