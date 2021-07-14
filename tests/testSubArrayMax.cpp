#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../SubArrayMax.cpp"
#include<vector>
#include<tuple>

TEST_CASE("findMaxCrossingSubarray", "[SubArray]"){
    SECTION("Two to left and one to right"){
        std::vector<int> a{-1, 2, 3, 4, 5, -6, -7};
        auto [low, high, sum] = findMaxCrossingSubArray(a, 0, 3, 6);
        CHECK(low == 1);
        CHECK(high == 4);
        REQUIRE(sum == 14);
    }

    SECTION("Only one element"){
        std::vector<float> a{4.0};
        auto [low, high, sum] = findMaxCrossingSubArray(a, 0, 0, 0);
        CHECK(low == 0);
        CHECK(high == 0);
        REQUIRE(sum == 4.0);
    }

    SECTION("Middle is negative"){
        std::vector<int> a{-1, 2, 3, -4, 5, -6, -7};
        auto [low, high, sum] = findMaxCrossingSubArray(a, 0, 3, 6);
        CHECK(low == 1);
        CHECK(high == 4);
        REQUIRE(sum == 6);
    }

    SECTION("Left is negative"){
        std::vector<int> a{-1, -2, -3, 4, 5, -6, -7};
        auto [low, high, sum] = findMaxCrossingSubArray(a, 0, 3, 6);
        CHECK(low == 3);
        CHECK(high == 4);
        REQUIRE(sum == 9);
    }

    SECTION("Right is negative"){
        std::vector<int> a{-1, 2, 3, 4, -5, -6, -7};
        auto [low, high, sum] = findMaxCrossingSubArray(a, 0, 3, 6);
        CHECK(low == 1);
        CHECK(high == 4);
        REQUIRE(sum == 4);
    }

        SECTION("Left and middle is negative"){
        std::vector<int> a{-1, -2, -3, -4, 5, -6, -7};
        auto [low, high, sum] = findMaxCrossingSubArray(a, 0, 3, 6);
        CHECK(low == 3);
        CHECK(high == 4);
        REQUIRE(sum == 1);
    }

    SECTION("Right and middle is negative"){
        std::vector<int> a{-1, 2, 3, -4, -5, -6, -7};
        auto [low, high, sum] = findMaxCrossingSubArray(a, 0, 3, 6);
        CHECK(low == 1);
        CHECK(high == 4);
        REQUIRE(sum == -4);
    }
}

TEST_CASE("subArrayMaxDivideAndConquer", "[SubArray]"){
    SECTION("Two to left and one to right"){
        std::vector<int> a{-1, 2, 3, 4, 5, -6, -7};
        auto [low, high, sum] = subArrayMaxDivideAndConquer(a, 0, 6);
        CHECK(low == 1);
        CHECK(high == 4);
        REQUIRE(sum == 14);
    }

    SECTION("Only one element"){
        std::vector<float> a{4.0};
        auto [low, high, sum] = subArrayMaxDivideAndConquer(a, 0, 0);
        CHECK(low == 0);
        CHECK(high == 0);
        REQUIRE(sum == 4.0);
    }

    SECTION("Middle is negative and response is to left"){
        std::vector<int> a{-1, 2, 3, -4, -5, -6, -7};
        auto [low, high, sum] = subArrayMaxDivideAndConquer(a, 0, 6);
        CHECK(low == 1);
        CHECK(high == 2);
        REQUIRE(sum == 5);
    }

    SECTION("Middle is positive and response is to left"){
        std::vector<int> a{-1, 2, 3, 4, -5, -6, -7};
        auto [low, high, sum] = subArrayMaxDivideAndConquer(a, 0, 6);
        CHECK(low == 1);
        CHECK(high == 3);
        REQUIRE(sum == 9);
    }

    SECTION("Middle is negative and response is to right"){
        std::vector<int> a{-1, -2, 3, -4, 5, 6, -7};
        auto [low, high, sum] = subArrayMaxDivideAndConquer(a, 0, 6);
        CHECK(low == 4);
        CHECK(high == 5);
        REQUIRE(sum == 11);
    }

    SECTION("Middle is positive and response is to right"){
        std::vector<int> a{-1, -2, -3, 4, 5, 6, -7};
        auto [low, high, sum] = subArrayMaxDivideAndConquer(a, 0, 6);
        CHECK(low == 3);
        CHECK(high == 5);
        REQUIRE(sum == 15);
    }

    SECTION("Sum is entire vector"){
        std::vector<int> a{10, -2, -3, 4, 5, 6, 17};
        auto [low, high, sum] = subArrayMaxDivideAndConquer(a, 0, 6);
        CHECK(low == 0);
        CHECK(high == 6);
        REQUIRE(sum == 37);
    }

    SECTION("one negative between largest and middle-left"){
        std::vector<int> a{-1, 20, -3, 3, 5, -6, -7};
        auto [low, high, sum] = subArrayMaxDivideAndConquer(a, 0, 6);
        CHECK(low == 1);
        CHECK(high == 4);
        REQUIRE(sum == 25);
    }
    
    SECTION("one negative between largest and middle-right"){
        std::vector<int> a{-1, -2, -3, 6, -5, 6, -7};
        auto [low, high, sum] = subArrayMaxDivideAndConquer(a, 0, 6);
        CHECK(low == 3);
        CHECK(high == 5);
        REQUIRE(sum == 7);
    }
}

TEST_CASE("subArrayMaxWindowing", "[SubArray]"){
    SECTION("Two to left and one to right"){
        std::vector<int> a{-1, 2, 3, 4, 5, -6, -7};
        auto [low, high, sum] = subArrayMaxWindowing(a, 0, 6);
        CHECK(low == 1);
        CHECK(high == 4);
        REQUIRE(sum == 14);
    }

    SECTION("Only one element"){
        std::vector<float> a{4.0};
        auto [low, high, sum] = subArrayMaxWindowing(a, 0, 0);
        CHECK(low == 0);
        CHECK(high == 0);
        REQUIRE(sum == 4.0);
    }

    SECTION("Middle is negative and response is to left"){
        std::vector<int> a{-1, 2, 3, -4, -5, -6, -7};
        auto [low, high, sum] = subArrayMaxWindowing(a, 0, 6);
        CHECK(low == 1);
        CHECK(high == 2);
        REQUIRE(sum == 5);
    }

    SECTION("Middle is positive and response is to left"){
        std::vector<int> a{-1, 2, 3, 4, -5, -6, -7};
        auto [low, high, sum] = subArrayMaxWindowing(a, 0, 6);
        CHECK(low == 1);
        CHECK(high == 3);
        REQUIRE(sum == 9);
    }

    SECTION("Middle is negative and response is to right"){
        std::vector<int> a{-1, -2, 3, -4, 5, 6, -7};
        auto [low, high, sum] = subArrayMaxWindowing(a, 0, 6);
        CHECK(low == 4);
        CHECK(high == 5);
        REQUIRE(sum == 11);
    }

    SECTION("Middle is positive and response is to right"){
        std::vector<int> a{-1, -2, -3, 4, 5, 6, -7};
        auto [low, high, sum] = subArrayMaxWindowing(a, 0, 6);
        CHECK(low == 3);
        CHECK(high == 5);
        REQUIRE(sum == 15);
    }

    SECTION("Sum is entire vector"){
        std::vector<int> a{10, -2, -3, 4, 5, 6, 17};
        auto [low, high, sum] = subArrayMaxWindowing(a, 0, 6);
        CHECK(low == 0);
        CHECK(high == 6);
        REQUIRE(sum == 37);
    }

    SECTION("one negative between largest and middle-left"){
        std::vector<int> a{-1, 20, -3, 3, 5, -6, -7};
        auto [low, high, sum] = subArrayMaxWindowing(a, 0, 6);
        CHECK(low == 1);
        CHECK(high == 4);
        REQUIRE(sum == 25);
    }
    
    SECTION("one negative between largest and middle-right"){
        std::vector<int> a{-1, -2, -3, 6, -5, 6, -7};
        auto [low, high, sum] = subArrayMaxWindowing(a, 0, 6);
        CHECK(low == 3);
        CHECK(high == 5);
        REQUIRE(sum == 7);
    }
}