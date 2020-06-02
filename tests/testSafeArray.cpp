#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../SafeArray.cpp"


TEST_CASE("Test SafeArray Constructors", "[SafeArray]"){

    SECTION("Default Constructor"){
        SafeArray<int> array{};
        CHECK(array.getData()==nullptr);
        REQUIRE(array.getSize()==0);
    }
    SECTION("Size constructor positive number"){
        int Ntests = 3;
        SafeArray<int> a1(Ntests);
    
        for(int i=0; i < Ntests; i++){
            a1[i] = i;
            CHECK(a1[i] == i);
        }

        REQUIRE(a1.getSize() == Ntests);
    }
    SECTION("Size constructor 0 or negative number"){
        CHECK_THROWS(SafeArray<int>(0));
        REQUIRE_THROWS(SafeArray<int>(-3));
    }
    SECTION("Copy constructor does not copy pointer"){
        SafeArray<int> a1(4);
        SafeArray<int> a2(a1);
        a1[1] = 2;
        a2[1] = 3;
        CHECK(a1[1] == 2);
        REQUIRE(a2[1] == 3);
    }
}

TEST_CASE("Out of bounds", "[SafeArray]"){
    SafeArray<int> a1(4);
    CHECK_THROWS(a1[-1] = 0);
    REQUIRE_THROWS(a1[4] = 0);

}

TEST_CASE("Copy Array", "[SafeArray]"){
    SafeArray<int> a1(4);
    SafeArray<int> a2(12);
   
    a2[0] = 1;
    a2[1] = 2;
    a2[2] = 4;
    a2[3] = 8;
    
    a1 = a2;
    a2[10] = 3;
    a1[11] = 101;

    CHECK(a1[0] == 1);
    CHECK(a1[11] == 101);
    CHECK(a1[10] == 0);
    CHECK(a2[10] == 3);
    REQUIRE(a2[11] == 0);

}

TEST_CASE("Equality Operator", "[SafeArray]"){
    SafeArray<int> a1(3);
    SafeArray<int> a2(3);
   
    a2[0] = 1;
    a2[1] = 2;
    a2[2] = 4;
    
    a1[0] = 1;
    a1[1] = 2;
    a1[2] = 4;
    
    CHECK(a1 == a2);
    CHECK_FALSE(a1 != a2);
    a1[2] = 42;

    CHECK(a1 != a2);
    REQUIRE_FALSE(a1 == a2);

}

TEST_CASE("Equality with char", "[SafeArray]"){
    SafeArray<char> a1(3);
    SafeArray<char> a2(3);
   
    a2[0] = '1';
    a2[1] = '2';
    a2[2] = '4';
    
    a1[0] = '1';
    a1[1] = '2';
    a1[2] = '4';
    
    CHECK(a1 == a2);
    CHECK_FALSE(a1 != a2);
    a1[2] = 'a';

    CHECK(a1 != a2);
    REQUIRE_FALSE(a1 == a2);

}

TEST_CASE("Equality with pointers", "[SafeArray]"){
    SafeArray<char*> a1(3);
    SafeArray<char*> a2(3);
   
    a2[0] = "cstring";
    a2[1] = "cstring2";
    a2[2] = "cstring3";
    
    a1[0] = "cstring";
    a1[1] = "cstring2";
    a1[2] = "cstring3";
    
    CHECK(a1 == a2);
    CHECK_FALSE(a1 != a2);
    a1[2] = nullptr;

    CHECK(a1 != a2);
    CHECK_FALSE(a1 == a2);
    REQUIRE(a1[2] == nullptr);

}

