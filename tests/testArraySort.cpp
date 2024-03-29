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

TEST_CASE("Merge", "[Merge]"){
    SECTION("Merge continuos sorted array"){
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        merge(a, 0, 2, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Merge sorted array"){
        std::vector<int> a{1, 4, 7, 2, 5, 6};
        merge(a, 0, 2, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 4, 5, 6, 7 }));
    }

    SECTION("Merge continuos sorted array"){
        std::vector<int> a{1, 2, 3, 4, 5, 6, 7};
        merge(a, 0, 3, 6);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6, 7 }));
    }

    SECTION("Merge sorted array"){
        std::vector<int> a{1, 4, 7, 9, 5, 6, 8};
        merge(a, 0, 3, 6);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 4, 5, 6, 7, 8, 9 }));
    }
}

TEST_CASE("MergeSort", "[Sort]"){
    SECTION("Sorted Array"){
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        mergeSort(a, 0, a.size() - 1);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Reversed Array"){
        std::vector<int> a{6, 5, 4, 3, 2, 1};
        mergeSort(a, 0, a.size() - 1);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("First smaller"){        
        std::vector<int> a{1, 2, 4, 3, 6, 5};
        mergeSort(a, 0, a.size() - 1);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Last bigger"){        
        std::vector<int> a{2, 5, 4, 3, 1, 6};
        mergeSort(a, 0, a.size() - 1);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<int> a{1, 5, 4, 3, 2, 6};
        mergeSort(a, 0, a.size() - 1);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
}

TEST_CASE("InsertionSort", "[Sort]"){
    SECTION("Sorted Array"){
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        insertionSort(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Reversed Array"){
        std::vector<int> a{6, 5, 4, 3, 2, 1};
        insertionSort(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("First smaller"){        
        std::vector<int> a{1, 2, 4, 3, 6, 5};
        insertionSort(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Last bigger"){        
        std::vector<int> a{2, 5, 4, 3, 1, 6};
        insertionSort(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<int> a{1, 5, 4, 3, 2, 6};
        insertionSort(a, 0, 5);
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

TEST_CASE("Partition", "[Partition]"){
    SECTION("Continuos sorted array 6 elements"){
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        partition(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Unsorted array 6 elements"){
        std::vector<int> a{1, 4, 7, 2, 5, 6};
        partition(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 4, 2, 5, 6, 7 }));
    }

    SECTION("Continuos sorted array 7 elements"){
        std::vector<int> a{1, 2, 3, 4, 5, 6, 7};
        partition(a, 0, 6);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6, 7 }));
    }

    SECTION("Unsorted array 7 elements"){
        std::vector<int> a{1, 4, 7, 9, 5, 6, 8};
        partition(a, 0, 6);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 4, 7, 5, 6, 8, 9 }));
    }
}

TEST_CASE("QuickSort", "[Sort]"){
    SECTION("Sorted Array"){
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        quickSort(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Reversed Array"){
        std::vector<int> a{6, 5, 4, 3, 2, 1};
        quickSort(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("First smaller"){        
        std::vector<int> a{1, 2, 4, 3, 6, 5};
        quickSort(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Last bigger"){        
        std::vector<int> a{2, 5, 4, 3, 1, 6};
        quickSort(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<int> a{1, 5, 4, 3, 2, 6};
        quickSort(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
}

TEST_CASE("RandomizedQuickSort", "[Sort]"){
    SECTION("Sorted Array"){
        std::vector<int> a{1, 2, 3, 4, 5, 6};
        randomizedQuickSort(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Reversed Array"){
        std::vector<int> a{6, 5, 4, 3, 2, 1};
        randomizedQuickSort(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("First smaller"){        
        std::vector<int> a{1, 2, 4, 3, 6, 5};
        randomizedQuickSort(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Last bigger"){        
        std::vector<int> a{2, 5, 4, 3, 1, 6};
        randomizedQuickSort(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<int> a{1, 5, 4, 3, 2, 6};
        randomizedQuickSort(a, 0, 5);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 1, 2, 3, 4, 5, 6 }));
    }
}

TEST_CASE("CountingSort", "[Sort]"){
    SECTION("Sorted Array"){
        std::vector<int> a{0, 1, 2, 3, 4, 5, 6};
        auto sortedArray = countingSort(a, 6);
        REQUIRE_THAT(sortedArray, Catch::Matchers::Equals(std::vector<int>{ 0, 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Reversed Array"){
        std::vector<int> a{6, 5, 4, 3, 2, 1, 0};
        auto sortedArray = countingSort(a, 6);
        REQUIRE_THAT(sortedArray, Catch::Matchers::Equals(std::vector<int>{ 0, 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("First smaller"){        
        std::vector<int> a{0, 1, 2, 4, 3, 6, 5};
        auto sortedArray = countingSort(a, 6);
        REQUIRE_THAT(sortedArray, Catch::Matchers::Equals(std::vector<int>{ 0, 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Last bigger"){        
        std::vector<int> a{0, 2, 5, 4, 3, 1, 6};
        auto sortedArray = countingSort(a, 6);
        REQUIRE_THAT(sortedArray, Catch::Matchers::Equals(std::vector<int>{ 0, 1, 2, 3, 4, 5, 6 }));
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<int> a{0, 1, 5, 4, 3, 2, 6};
        auto sortedArray = countingSort(a, 6);
        REQUIRE_THAT(sortedArray, Catch::Matchers::Equals(std::vector<int>{ 0, 1, 2, 3, 4, 5, 6 }));
    }
}



TEST_CASE("RadixSort", "[Sort]"){
    SECTION("Sorted Array"){
        std::vector<int> a{0, 1, 2, 3, 4, 5, 6};
        radixSort(a, 6);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 0, 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Reversed Array"){
        std::vector<int> a{6, 5, 4, 3, 2, 1, 0};
        radixSort(a, 6);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 0, 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("First smaller"){        
        std::vector<int> a{0, 1, 2, 4, 3, 6, 5};
        radixSort(a, 6);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 0, 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Last bigger"){        
        std::vector<int> a{0, 2, 5, 4, 3, 1, 6};
        radixSort(a, 6);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 0, 1, 2, 3, 4, 5, 6 }));
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<int> a{0, 1, 5, 4, 3, 2, 6};
        radixSort(a, 6);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 0, 1, 2, 3, 4, 5, 6 }));
    }

    SECTION("Sorted Array with more digits"){
        std::vector<int> a{0, 10, 200, 301, 421, 543, 667};
        radixSort(a, 667);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 0, 10, 200, 301, 421, 543, 667 }));
    }

    SECTION("Reversed Array with more digits"){
        std::vector<int> a{667, 543, 421, 301, 200, 10, 0};
        radixSort(a, 667);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 0, 10, 200, 301, 421, 543, 667 }));
    }

    SECTION("First smaller with more digits"){        
        std::vector<int> a{0, 10, 200, 421, 301, 667, 543};
        radixSort(a, 667);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 0, 10, 200, 301, 421, 543, 667 }));
    }

    SECTION("Last bigger with more digits"){        
        std::vector<int> a{0, 200, 543, 421, 301, 10, 667};
        radixSort(a, 667);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 0, 10, 200, 301, 421, 543, 667 }));
    }
    
    SECTION("Last bigger and first smaller with more digits"){        
        std::vector<int> a{0, 10, 543, 421, 301, 200, 667};
        radixSort(a, 667);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<int>{ 0, 10, 200, 301, 421, 543, 667 }));
    }
}


TEST_CASE("BucketSort", "[Sort]"){
    SECTION("Sorted Array"){
        std::vector<float> a{0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.61};
        bucketSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<float>{ 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.61 }));
    }

    SECTION("Reversed Array"){
        std::vector<float> a{0.61, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0.0};
        bucketSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<float>{ 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.61 }));
    }

    SECTION("First smaller"){        
        std::vector<float> a{0.0, 0.1, 0.2, 0.4, 0.3, 0.61, 0.6, 0.5};
        bucketSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<float>{ 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.61 }));
    }

    SECTION("Last bigger"){        
        std::vector<float> a{0.0, 0.2, 0.5, 0.4, 0.3, 0.1, 0.6, 0.61};
        bucketSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<float>{ 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.61 }));
    }
    
    SECTION("Last bigger and first smaller"){        
        std::vector<float> a{0.0, 0.1, 0.5, 0.4, 0.3, 0.2, 0.6, 0.61};
        bucketSort(a);
        REQUIRE_THAT(a, Catch::Matchers::Equals(std::vector<float>{ 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.61 }));
    }
}