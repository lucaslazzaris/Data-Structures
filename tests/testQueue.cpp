#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Queue.cpp"

TEST_CASE("Enqueue", "[Queue]"){
    Queue<int> a1(4);
    a1.dequeue();
    a1.enqueue(40);
    REQUIRE(a1[0] == 40);
}

TEST_CASE("Dequeue", "[Queue]"){
    Queue<int> a1(4);
    Queue<int> a2;
    CHECK_THROWS(a2.dequeue());

    a1[0] = 1;
    a1[1] = 2;
    a1[2] = 4;
    a1[3] = 8;

    auto popedValue = a1.dequeue();
    CHECK(a1.isEmpty() == false);
    REQUIRE(popedValue == 1);
}

TEST_CASE("isEmpty", "[Queue]"){
    Queue<int> a1;
    a1.setSize(4);
    CHECK(a1.isEmpty());

    a1.enqueue(1);
    a1.enqueue(2);
    a1.enqueue(4);
    a1.enqueue(8);

    CHECK(a1[0] == 1);
    CHECK(a1[1] == 2);
    CHECK(a1[2] == 4);
    CHECK(a1[3] == 8);
    REQUIRE(a1.isEmpty() == false);
}