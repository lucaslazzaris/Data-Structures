#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../SafeArray.cpp"
#include<numeric>

TEST_CASE("Test SafeArray Constructors", "[SafeArray]"){

    SECTION("Default Constructor"){
        Array<int> array{};
        CHECK(array.getData()==nullptr);
        REQUIRE(array.getSize()==0);
    }
    SECTION("Size constructor positive number"){
        int Ntests = 3;
        Array<int> a1(Ntests);
    
        for(int i=0; i < Ntests; i++){
            a1[i] = i;
            CHECK(a1[i] == i);
        }

        REQUIRE(a1.getSize() == Ntests);
    }
    SECTION("Size constructor 0 or negative number"){
        CHECK_THROWS(Array<int>(0));
        REQUIRE_THROWS(Array<int>(-3));
    }
    SECTION("Copy constructor does not copy pointer"){
        Array<int> a1(4);
        Array<int> a2(a1);
        a1[1] = 2;
        a2[1] = 3;
        CHECK(a1[1] == 2);
        REQUIRE(a2[1] == 3);
    }
    SECTION("Out of bounds"){
        Array<int> a1(4);
        CHECK_THROWS(a1[-1] = 0);
        REQUIRE_THROWS(a1[4] = 0);
    }


}