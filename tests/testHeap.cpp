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

TEST_CASE("Out of bounds", "[Heap]"){
    Heap<int> a1(4);
    CHECK_THROWS(a1[-1] = 0);
    REQUIRE_THROWS(a1[4] = 0);
}

TEST_CASE("Copy Array", "[Heap]"){
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

TEST_CASE("Equality Operator", "[Heap]"){
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

TEST_CASE("Equality with char", "[Heap]"){
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

TEST_CASE("Equality with pointers", "[Heap]"){
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

TEST_CASE("Parent, Lef and Right", "[Heap]"){
    Heap<int> heap{10};
    heap[0] = 16;
    heap[1] = 14;
    heap[2] = 10;
    heap[3] = 8;
    heap[4] = 7;
    heap[5] = 9;
    heap[6] = 3;
    heap[7] = 2;
    heap[8] = 4;
    heap[9] = 1;

    SECTION("Parent"){
        CHECK(16 == heap[heap.parent(1)]);
        CHECK(16 == heap[heap.parent(2)]);
        CHECK(14 == heap[heap.parent(3)]);
        REQUIRE(14 == heap[heap.parent(4)]);
    }

    SECTION("Left"){
        CHECK(14 == heap[heap.left(0)]);
        CHECK(8 == heap[heap.left(1)]);
        CHECK(9 == heap[heap.left(2)]);
        REQUIRE(2 == heap[heap.left(3)]);
    }

    SECTION("Right"){
        CHECK(10 == heap[heap.right(0)]);
        CHECK(7 == heap[heap.right(1)]);
        CHECK(3 == heap[heap.right(2)]);
        REQUIRE(4 == heap[heap.right(3)]);
    }
}

TEST_CASE("maxHeapify", "[Heap]"){
    Heap<int> heap{10};
    heap[0] = 16;
    heap[1] = 4;
    heap[2] = 10;
    heap[3] = 14;
    heap[4] = 7;
    heap[5] = 9;
    heap[6] = 3;
    heap[7] = 2;
    heap[8] = 8;
    heap[9] = 1;

    SECTION("Do nothing when heap is already max"){
        heap.maxHeapify(2);
        CHECK(16 == heap[0]);
        CHECK(4 == heap[1]);
        CHECK(10 == heap[2]);
        CHECK(14 == heap[3]);
        CHECK(7 == heap[4]);
        CHECK(9 == heap[5]);
        CHECK(3 == heap[6]);
        CHECK(2 == heap[7]);
        CHECK(8 == heap[8]);
        REQUIRE(1 == heap[9]);
    }

     SECTION("Do nothing when children are not bigger"){
        heap.maxHeapify(0);
        CHECK(16 == heap[0]);
        CHECK(4 == heap[1]);
        CHECK(10 == heap[2]);
        CHECK(14 == heap[3]);
        CHECK(7 == heap[4]);
        CHECK(9 == heap[5]);
        CHECK(3 == heap[6]);
        CHECK(2 == heap[7]);
        CHECK(8 == heap[8]);
        REQUIRE(1 == heap[9]);
    }

    SECTION("maxHeapify the heap to the left"){
        heap.maxHeapify(1);
        CHECK(16 == heap[0]);
        CHECK(14 == heap[1]);
        CHECK(10 == heap[2]);
        CHECK(8 == heap[3]);
        CHECK(7 == heap[4]);
        CHECK(9 == heap[5]);
        CHECK(3 == heap[6]);
        CHECK(2 == heap[7]);
        CHECK(4 == heap[8]);
        CHECK(1 == heap[9]);
    }

    SECTION("maxHeapify the heap to the right"){
        heap[3] = 7;
        heap[4] = 14;

        heap.maxHeapify(1);
        CHECK(16 == heap[0]);
        CHECK(14 == heap[1]);
        CHECK(10 == heap[2]);
        CHECK(7 == heap[3]);
        CHECK(4 == heap[4]);
        CHECK(9 == heap[5]);
        CHECK(3 == heap[6]);
        CHECK(2 == heap[7]);
        CHECK(8 == heap[8]);
        REQUIRE(1 == heap[9]);
    }
}

TEST_CASE("buildMaxHeap", "[Heap]"){
    Heap<int> heap{10};
    heap[0] = 16;
    heap[1] = 4;
    heap[2] = 10;
    heap[3] = 14;
    heap[4] = 7;
    heap[5] = 11;
    heap[6] = 3;
    heap[7] = 2;
    heap[8] = 8;
    heap[9] = 1;

    SECTION("Build maxHeap"){
        heap.buildMaxHeap();
        CHECK(16 == heap[0]);
        CHECK(14 == heap[1]);
        CHECK(11 == heap[2]);
        CHECK(8 == heap[3]);
        CHECK(7 == heap[4]);
        CHECK(10 == heap[5]);
        CHECK(3 == heap[6]);
        CHECK(2 == heap[7]);
        CHECK(4 == heap[8]);
        CHECK(1 == heap[9]);
    }

    SECTION("Do nothing when heap is already max"){
        heap[5] = 9;

        heap.maxHeapify(2);
        CHECK(16 == heap[0]);
        CHECK(4 == heap[1]);
        CHECK(10 == heap[2]);
        CHECK(14 == heap[3]);
        CHECK(7 == heap[4]);
        CHECK(9 == heap[5]);
        CHECK(3 == heap[6]);
        CHECK(2 == heap[7]);
        CHECK(8 == heap[8]);
        REQUIRE(1 == heap[9]);
    }
}

TEST_CASE("HeapSort", "[Sort]"){
    SECTION("Sorted Array"){
        Heap<int> heap{6};
        heap[0] = 1;
        heap[1] = 2;
        heap[2] = 3;
        heap[3] = 4;
        heap[4] = 5;
        heap[5] = 6;
        heap.heapSort();
        CHECK(1 == heap[0]);
        CHECK(2 == heap[1]);
        CHECK(3 == heap[2]);
        CHECK(4 == heap[3]);
        CHECK(5 == heap[4]);
        REQUIRE(6 == heap[5]);
    }

    SECTION("Reversed Array"){
        Heap<int> heap{6};
        heap[0] = 6;
        heap[1] = 5;
        heap[2] = 4;
        heap[3] = 3;
        heap[4] = 2;
        heap[5] = 1;
        heap.heapSort();
        CHECK(1 == heap[0]);
        CHECK(2 == heap[1]);
        CHECK(3 == heap[2]);
        CHECK(4 == heap[3]);
        CHECK(5 == heap[4]);
        REQUIRE(6 == heap[5]);
    }

    SECTION("First smaller"){        
        Heap<int> heap{6};
        heap[0] = 1;
        heap[1] = 2;
        heap[2] = 4;
        heap[3] = 3;
        heap[4] = 6;
        heap[5] = 5;
        heap.heapSort();
        CHECK(1 == heap[0]);
        CHECK(2 == heap[1]);
        CHECK(3 == heap[2]);
        CHECK(4 == heap[3]);
        CHECK(5 == heap[4]);
        REQUIRE(6 == heap[5]);
    }

    SECTION("Last bigger"){        
        Heap<int> heap{6};
        heap[0] = 2;
        heap[1] = 5;
        heap[2] = 4;
        heap[3] = 3;
        heap[4] = 1;
        heap[5] = 6;
        heap.heapSort();
        CHECK(1 == heap[0]);
        CHECK(2 == heap[1]);
        CHECK(3 == heap[2]);
        CHECK(4 == heap[3]);
        CHECK(5 == heap[4]);
        REQUIRE(6 == heap[5]);
    }
    
    SECTION("Last bigger and first smaller"){        
        Heap<int> heap{6};
        heap[0] = 1;
        heap[1] = 5;
        heap[2] = 4;
        heap[3] = 3;
        heap[4] = 2;
        heap[5] = 6;
        heap.heapSort();
        CHECK(1 == heap[0]);
        CHECK(2 == heap[1]);
        CHECK(3 == heap[2]);
        CHECK(4 == heap[3]);
        CHECK(5 == heap[4]);
        REQUIRE(6 == heap[5]);
    }
}

TEST_CASE("Priority Queue", "[PriorityQueue]"){
    Heap<int> heap{10};
    heap[0] = 16;
    heap[1] = 14;
    heap[2] = 10;
    heap[3] = 8;
    heap[4] = 7;
    heap[5] = 9;
    heap[6] = 3;
    heap[7] = 2;
    heap[8] = 4;
    heap[9] = 1;

    SECTION("heapMaximum"){
        REQUIRE(16 == heap.heapMaximum());
    }

    SECTION("heapExtractMax"){        
        auto max = heap.heapExtractMax();
        CHECK(max == 16);
        CHECK(heap.getHeapSize() == 9);
        CHECK(heap[0] == 14);
        CHECK(heap[1] == 8);
        CHECK(heap[2] == 10);
        CHECK(heap[3] == 4);
        CHECK(heap[4] == 7);
        CHECK(heap[5] == 9);
        CHECK(heap[6] == 3);
        CHECK(heap[7] == 2);
        REQUIRE(heap[8] == 1);
    }
    
    SECTION("heapIncreaseKey"){       
        heap.heapIncreaseKey(9, 18);
        CHECK(heap[0] == 18);
        CHECK(heap[1] == 16);
        CHECK(heap[2] == 10);
        CHECK(heap[3] == 8);
        CHECK(heap[4] == 14);
        CHECK(heap[5] == 9);
        CHECK(heap[6] == 3);
        CHECK(heap[7] == 2);
        CHECK(heap[8] == 4);
        REQUIRE(heap[9] == 7);
    }

    SECTION("maxHeapInsert"){      
        heap.maxHeapInsert(18);
        CHECK(heap[0] == 18);
        CHECK(heap[1] == 16);
        CHECK(heap[2] == 10);
        CHECK(heap[3] == 8);
        CHECK(heap[4] == 14);
        CHECK(heap[5] == 9);
        CHECK(heap[6] == 3);
        CHECK(heap[7] == 2);
        CHECK(heap[8] == 4);
        REQUIRE(heap[9] == 1);
        REQUIRE(heap[10] == 7);
    }
}