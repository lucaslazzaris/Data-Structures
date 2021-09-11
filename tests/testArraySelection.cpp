#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../ArraySelection.cpp"
#include<vector>

TEST_CASE("Min", "[Min]"){
    SECTION("Sorted Array"){
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        int minimum = min(a);
        REQUIRE(1 == minimum);
    }

    SECTION("Reversed Array"){
        std::vector<int> a{6, 5, 4, 3, 2, 1};
        int minimum = min(a);
        REQUIRE(1 == minimum);
    }

    SECTION("First smaller"){        
        std::vector<int> a{1, 2, 4, 3, 6, 5};
        int minimum = min(a);
        REQUIRE(1 == minimum);
    }

    SECTION("Last bigger"){        
        std::vector<int> a{2, 5, 4, 3, 1, 6};
        int minimum = min(a);
        REQUIRE(1 == minimum);
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<int> a{1, 5, 4, 3, 2, 6};
        int minimum = min(a);
        REQUIRE(1 == minimum);
    }
}

TEST_CASE("Max", "[Max]"){
    SECTION("Sorted Array"){
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        int maximum = max(a);
        REQUIRE(6 == maximum);
    }

    SECTION("Reversed Array"){
        std::vector<int> a{6, 5, 4, 3, 2, 1};
        int maximum = max(a);
        REQUIRE(6 == maximum);
    }

    SECTION("First smaller"){        
        std::vector<int> a{1, 2, 4, 3, 6, 5};
        int maximum = max(a);
        REQUIRE(6 == maximum);
    }

    SECTION("Last bigger"){        
        std::vector<int> a{2, 5, 4, 3, 1, 6};
        int maximum = max(a);
        REQUIRE(6 == maximum);
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<int> a{1, 5, 4, 3, 2, 6};
        int maximum = max(a);
        REQUIRE(6 == maximum);
    }
}

TEST_CASE("MinMax", "[MinMax]"){
    SECTION("Sorted Array"){
        int minimum, maximum;
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        minMax(a, minimum, maximum);
        CHECK(1 == minimum);
        REQUIRE(6 == maximum);
    }

    SECTION("Reversed Array"){
        int minimum, maximum;
        std::vector<int> a{6, 5, 4, 3, 2, 1};
        minMax(a, minimum, maximum);
        CHECK(1 == minimum);
        REQUIRE(6 == maximum);
    }

    SECTION("First smaller"){        
        int minimum, maximum;
        std::vector<int> a{1, 2, 4, 3, 6, 5};
        minMax(a, minimum, maximum);
        CHECK(1 == minimum);
        REQUIRE(6 == maximum);
    }

    SECTION("Last bigger"){        
        int minimum, maximum;
        std::vector<int> a{2, 5, 4, 3, 1, 6};
        minMax(a, minimum, maximum);
        CHECK(1 == minimum);
        REQUIRE(6 == maximum);
    }
    
    SECTION("Last bigger and first smaller"){        
        int minimum, maximum;
        std::vector<int> a{1, 5, 4, 3, 2, 6};
        minMax(a, minimum, maximum);
        CHECK(1 == minimum);
        REQUIRE(6 == maximum);
    }
}

TEST_CASE("randomizedSelect", "[Select]"){
    SECTION("Sorted Array"){
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        CHECK(1 == randomizedSelect(a, 0, 5, 1));
        CHECK(2 == randomizedSelect(a, 0, 5, 2));
        CHECK(3 == randomizedSelect(a, 0, 5, 3));
        CHECK(4 == randomizedSelect(a, 0, 5, 4));
        CHECK(5 == randomizedSelect(a, 0, 5, 5));
        REQUIRE(6 == randomizedSelect(a, 0, 5, 6));
    }

    SECTION("Reversed Array"){
        std::vector<int> a{6, 5, 4, 3, 2, 1};
        CHECK(1 == randomizedSelect(a, 0, 5, 1));
        CHECK(2 == randomizedSelect(a, 0, 5, 2));
        CHECK(3 == randomizedSelect(a, 0, 5, 3));
        CHECK(4 == randomizedSelect(a, 0, 5, 4));
        CHECK(5 == randomizedSelect(a, 0, 5, 5));
        REQUIRE(6 == randomizedSelect(a, 0, 5, 6));
    }

    SECTION("First smaller"){        
        std::vector<int> a{1, 2, 4, 3, 6, 5};
        CHECK(1 == randomizedSelect(a, 0, 5, 1));
        CHECK(2 == randomizedSelect(a, 0, 5, 2));
        CHECK(3 == randomizedSelect(a, 0, 5, 3));
        CHECK(4 == randomizedSelect(a, 0, 5, 4));
        CHECK(5 == randomizedSelect(a, 0, 5, 5));
        REQUIRE(6 == randomizedSelect(a, 0, 5, 6));
    }

    SECTION("Last bigger"){        
        std::vector<int> a{2, 5, 4, 3, 1, 6};
        CHECK(1 == randomizedSelect(a, 0, 5, 1));
        CHECK(2 == randomizedSelect(a, 0, 5, 2));
        CHECK(3 == randomizedSelect(a, 0, 5, 3));
        CHECK(4 == randomizedSelect(a, 0, 5, 4));
        CHECK(5 == randomizedSelect(a, 0, 5, 5));
        REQUIRE(6 == randomizedSelect(a, 0, 5, 6));
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<int> a{1, 5, 4, 3, 2, 6};
        CHECK(1 == randomizedSelect(a, 0, 5, 1));
        CHECK(2 == randomizedSelect(a, 0, 5, 2));
        CHECK(3 == randomizedSelect(a, 0, 5, 3));
        CHECK(4 == randomizedSelect(a, 0, 5, 4));
        CHECK(5 == randomizedSelect(a, 0, 5, 5));
        REQUIRE(6 == randomizedSelect(a, 0, 5, 6));
    }
}

TEST_CASE("QuickSelect", "[Select]"){
    SECTION("Sorted Array"){
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        CHECK(1 == quickSelect(a, 0, 5, 1));
        CHECK(2 == quickSelect(a, 0, 5, 2));
        CHECK(3 == quickSelect(a, 0, 5, 3));
        CHECK(4 == quickSelect(a, 0, 5, 4));
        CHECK(5 == quickSelect(a, 0, 5, 5));
        REQUIRE(6 == quickSelect(a, 0, 5, 6));
    }

    SECTION("Reversed Array"){
        std::vector<int> a{6, 5, 4, 3, 2, 1};
        CHECK(1 == quickSelect(a, 0, 5, 1));
        CHECK(2 == quickSelect(a, 0, 5, 2));
        CHECK(3 == quickSelect(a, 0, 5, 3));
        CHECK(4 == quickSelect(a, 0, 5, 4));
        CHECK(5 == quickSelect(a, 0, 5, 5));
        REQUIRE(6 == quickSelect(a, 0, 5, 6));
    }

    SECTION("First smaller"){        
        std::vector<int> a{1, 2, 4, 3, 6, 5};
        CHECK(1 == quickSelect(a, 0, 5, 1));
        CHECK(2 == quickSelect(a, 0, 5, 2));
        CHECK(3 == quickSelect(a, 0, 5, 3));
        CHECK(4 == quickSelect(a, 0, 5, 4));
        CHECK(5 == quickSelect(a, 0, 5, 5));
        REQUIRE(6 == quickSelect(a, 0, 5, 6));
    }

    SECTION("Last bigger"){        
        std::vector<int> a{2, 5, 4, 3, 1, 6};
        CHECK(1 == quickSelect(a, 0, 5, 1));
        CHECK(2 == quickSelect(a, 0, 5, 2));
        CHECK(3 == quickSelect(a, 0, 5, 3));
        CHECK(4 == quickSelect(a, 0, 5, 4));
        CHECK(5 == quickSelect(a, 0, 5, 5));
        REQUIRE(6 == quickSelect(a, 0, 5, 6));
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<int> a{1, 5, 4, 3, 2, 6};
        CHECK(1 == quickSelect(a, 0, 5, 1));
        CHECK(2 == quickSelect(a, 0, 5, 2));
        CHECK(3 == quickSelect(a, 0, 5, 3));
        CHECK(4 == quickSelect(a, 0, 5, 4));
        CHECK(5 == quickSelect(a, 0, 5, 5));
        REQUIRE(6 == quickSelect(a, 0, 5, 6));
    }
    SECTION("Random input"){        
        std::vector<int> a{13, 51, 24, 153, 198, 83, 2, 6, 112, 90};
        CHECK(2 == quickSelect(a, 0, 9, 1));
        CHECK(6 == quickSelect(a, 0, 9, 2));
        CHECK(13 == quickSelect(a, 0, 9, 3));
        CHECK(24 == quickSelect(a, 0, 9, 4));
        CHECK(51 == quickSelect(a, 0, 9, 5));
        CHECK(83 == quickSelect(a, 0, 9, 6));
        CHECK(90 == quickSelect(a, 0, 9, 7));
        CHECK(112 == quickSelect(a, 0, 9, 8));
        CHECK(153 == quickSelect(a, 0, 9, 9));
        REQUIRE(198 == quickSelect(a, 0, 9, 10));
    }
}