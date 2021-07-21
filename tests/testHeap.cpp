#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Heap.cpp"


TEST_CASE("Test Heap Constructors", "[Heap]"){

    SECTION("Default Constructor"){
        Heap<int> heap{};
        auto pointer = heap.getData();
        CHECK(pointer == nullptr);
        REQUIRE(heap.getSize()==0);
    }
    SECTION("Size constructor positive number"){
        int Ntests = 3;
        Heap<int> a1(Ntests);
    
        for(int i=0; i < Ntests; i++){
            a1[i] = i;
            CHECK(a1[i] == i);
        }

        REQUIRE(a1.getSize() == Ntests);
    }
    SECTION("Size constructor 0 or negative number"){
        CHECK_THROWS(Heap<int>(0));
        REQUIRE_THROWS(Heap<int>(-3));
    }
    SECTION("Copy constructor does not copy pointer"){
        Heap<int> a1(4);
        Heap<int> a2(a1);
        a1[1] = 2;
        a2[1] = 3;
        CHECK(a1[1] == 2);
        REQUIRE(a2[1] == 3);
    }
}

TEST_CASE("Out of bounds", "[SafeArray]"){
    Heap<int> a1(4);
    CHECK_THROWS(a1[-1] = 0);
    REQUIRE_THROWS(a1[4] = 0);
}

TEST_CASE("Copy Array", "[SafeArray]"){
    Heap<int> a1(4);
    Heap<int> a2(12);
   
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
    Heap<int> a1(3);
    Heap<int> a2(3);
   
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
    Heap<char> a1(3);
    Heap<char> a2(3);
   
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
    Heap<const char*> a1(3);
    Heap<const char*> a2(3);
   
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

