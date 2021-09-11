#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Stack.cpp"

TEST_CASE("Push", "[Stack]"){
    Stack<int> a1(4);
    a1.push(40);
    CHECK(a1[0] == 0);
    CHECK(a1[1] == 0);
    CHECK(a1[2] == 0);
    CHECK(a1[3] == 0);
    REQUIRE(a1[4] == 40);
}

TEST_CASE("Pop", "[Stack]"){
    Stack<int> a1(4);
    Stack<int> a2;
    CHECK_THROWS(a2.pop());

    a1[0] = 1;
    a1[1] = 2;
    a1[2] = 4;
    a1[3] = 8;

    auto popedValue = a1.pop();
    CHECK(a1[0] == 1);
    CHECK(a1[1] == 2);
    CHECK(a1[2] == 4);
    CHECK(a1.empty() == false);
    REQUIRE(popedValue == 8);
}

TEST_CASE("Empty", "[Stack]"){
    Stack<int> a1;
    CHECK(a1.empty());

    a1.push(1);
    a1.push(2);
    a1.push(4);
    a1.push(8);

    CHECK(a1[0] == 1);
    CHECK(a1[1] == 2);
    CHECK(a1[2] == 4);
    CHECK(a1[3] == 8);
    REQUIRE(a1.empty() == false);
}