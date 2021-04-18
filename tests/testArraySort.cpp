#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../ArraySort.cpp"
#include<vector>

TEST_CASE("Swap", "[Swap]"){
  SECTION("Swap vector"){
    std::vector<int> a{1, 2};
    swap(&a[0], &a[1]);
    REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 2, 1}));

  }

  SECTION("Swap array"){
    int a[2];
    a[0] = 1;
    a[1] = 2;

    swap(&a[0], &a[1]);
    REQUIRE(a[0] == 2);
    REQUIRE(a[1] == 1);
  }
}

TEST_CASE("InsertionSort", "[Sort]"){
    SECTION("Sorted Array"){
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        insertionSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Reversed Array"){
        std::vector<int> a{6, 5, 4, 3, 2, 1};
        insertionSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("First smaller"){        
        std::vector<int> a{1, 2, 4, 3, 6, 5};
        insertionSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Last bigger"){        
        std::vector<int> a{2, 5, 4, 3, 1, 6};
        insertionSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<int> a{1, 5, 4, 3, 2, 6};
        insertionSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
}

TEST_CASE("SelectionSort", "[Sort]"){
    SECTION("Sorted Array"){
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        selectionSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Reversed Array"){
        std::vector<int> a{6, 5, 4, 3, 2, 1};
        selectionSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("First smaller"){        
        std::vector<int> a{1, 2, 4, 3, 6, 5};
        selectionSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Last bigger"){        
        std::vector<int> a{2, 5, 4, 3, 1, 6};
        selectionSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<int> a{1, 5, 4, 3, 2, 6};
        selectionSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
}

TEST_CASE("Bubble", "[Sort]"){
    SECTION("Sorted Array"){
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        bubbleSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Reversed Array"){
        std::vector<int> a{6, 5, 4, 3, 2, 1};
        bubbleSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("First smaller"){        
        std::vector<int> a{1, 2, 4, 3, 6, 5};
        bubbleSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Last bigger"){        
        std::vector<int> a{2, 5, 4, 3, 1, 6};
        bubbleSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<int> a{1, 5, 4, 3, 2, 6};
        bubbleSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
}

TEST_CASE("RecursiveBubble", "[Sort]"){
    SECTION("Sorted Array"){
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        recursiveBubbleSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Reversed Array"){
        std::vector<int> a{6, 5, 4, 3, 2, 1};
        recursiveBubbleSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("First smaller"){        
        std::vector<int> a{1, 2, 4, 3, 6, 5};
        recursiveBubbleSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Last bigger"){        
        std::vector<int> a{2, 5, 4, 3, 1, 6};
        recursiveBubbleSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<int> a{1, 5, 4, 3, 2, 6};
        recursiveBubbleSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
}