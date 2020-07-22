#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../List.cpp"
#include<memory>


TEST_CASE("Node Constructor", "[Node]"){
    SECTION("Default Constructor"){
        Node<int> n{};
        CHECK(n.getNext() == nullptr);
        REQUIRE(n.getValue() == 0);
    }

    SECTION("Value Constructor"){
        Node<int> n(5);
        CHECK(n.getNext() == nullptr);
        REQUIRE(n.getValue() == 5);
    }

    SECTION("Passing node constructor"){
        Node<int> n1(5);
        Node<int> n2(6, &n1);
        CHECK(n2.getNext() == &n1);
        REQUIRE(n2.getValue() == 6);
    }

    // Just to train how to work with smart pointers
    SECTION("Passing node constructor with smart pointer"){
        std::unique_ptr<Node<int>> n1 = std::make_unique<Node<int>>(5);
        Node<int> n2(6, n1.get());
        CHECK(n2.getNext() == n1.get());
        REQUIRE(n2.getValue() == 6);
    }
}

TEST_CASE("List Constructors", "[List]"){
    SECTION("Default Constructor"){
        List<int> l{};
        CHECK(l.getHead() == nullptr);
        REQUIRE(l.getSize() == 0);

    }
    SECTION("Value insertion"){
        List<int> l(15);
        CHECK(l.getHead() != nullptr);
        REQUIRE(l[0] == 15);
    }
    SECTION("Head insertion"){
        Node<int>* node = new Node<int>(12);
        List<int> l(node);
        CHECK(l.getHead() == node);
        REQUIRE(l[0] == 12);
    }
}

TEST_CASE("Find data in list", "[List]"){
    SECTION("Data exists head/middle/tail"){
        List<int> l(10);
        CHECK(l.exists(10));
        CHECK_FALSE(l.exists(11));
        l.insertHead(11);
        l.insertHead(12);
        CHECK(l.exists(10));
        CHECK(l.exists(11));
        CHECK(l.exists(12));
        REQUIRE_FALSE(l.exists(13));

    }
    SECTION("Find data by index"){
        List<int> l(10);
        l.insertHead(9);
        l.insertHead(8);
        REQUIRE(l.findIndex(10) == 2);
        REQUIRE(l.findIndex(9) == 1);
        REQUIRE(l.findIndex(8) == 0);
        REQUIRE(l.findIndex(42) == -1);
    }
    SECTION("Find node by value"){
        List<int> l(10);
        l.insertHead(9);
        l.insertHead(8);
        auto node = l.findNode(9);
        auto finalNode = l.findNode(10);
        REQUIRE(node->getNext() == finalNode);
        REQUIRE(finalNode->getNext() == nullptr);

    }
}

TEST_CASE("Insert data in list", "[List]"){
    SECTION("Insert Head on empty and existing list"){
        List<float> l1{};

        l1.insertHead(10);
        
        CHECK(l1[0] == 10);
        CHECK(l1.getSize() == 1);

        l1.insertHead(20);
        CHECK(l1[0] == 20);
        CHECK(l1[1] == 10);
        REQUIRE(l1.getSize() == 2);
    }
    SECTION("Insert Tail on empty and existing list"){
        List<float> l1{};

        l1.insertTail(10);
        
        CHECK(l1[0] == 10);
        CHECK(l1.getSize() == 1);

        l1.insertTail(20);
        CHECK(l1[1] == 20);
        CHECK(l1[0] == 10);
        CHECK(l1.getSize() == 2);

        l1.insertTail(30);
        CHECK(l1[2] == 30);
        CHECK(l1[1] == 20);
        CHECK(l1[0] == 10);
        REQUIRE(l1.getSize() == 3);
    }
}

TEST_CASE("Pop and remove data", "[List]"){
    
    List<int> l(10);
    l.insertHead(11);
    l.insertHead(12);
    l.insertHead(13);

    // l1 = [13, 12, 11, 10]
    List<int> l2{};
    List<int> l3(1);

    SECTION("Pop head"){
        CHECK(l.getSize() == 4);
        CHECK(l.popHead() == 13);
        REQUIRE(l.getSize() == 3);
        
        REQUIRE_THROWS(l2.popHead());

        REQUIRE(l3.popHead() == 1);
        REQUIRE(l3.getSize() == 0);
    }
    SECTION("Pop tail"){
        CHECK(l.popTail() == 10);
        REQUIRE(l.getSize() == 3);

        REQUIRE_THROWS(l2.popTail());

        REQUIRE(l3.popTail() == 1);
        REQUIRE(l3.getSize() == 0);
    }

}

TEST_CASE("Clear", "[List]"){
    List<int> l(1);
    for(int i = 1; i < 12; i++){
        l.insertHead(i);
    }
    l.clear();
    REQUIRE(l.getSize() == 0);
}

TEST_CASE("FindTail", "[List]"){
    List<char> l('c');
    List<int*> l2{};
    List<double> l3(5.2);
    l3.insertHead(4.2);
    l3.insertHead(3.2);

    CHECK(l.getTail()->getValue() == 'c');
    CHECK(l2.getTail() == nullptr);
    REQUIRE(l3.getTail()->getValue() == 5.2);

}

TEST_CASE("Insert at location", "[List]"){
    
    List<char> l('c');
    List<int> l2{};
    List<double> l3(5.2);
    l3.insertHead(4.2);
    l3.insertHead(3.2);


    SECTION("Insert empty"){
        l2.insert(3, 0);
        List<double> l4{};
        l4.insert(4.2, 0);
        CHECK(l4[0] == 4.2);
        CHECK(l4.getSize() == 1);

        CHECK_THROWS(l4.insert(3.2, 4));
        CHECK_THROWS(l4.insert(3.2, -1));

        CHECK(l2.getSize() == 1);
        REQUIRE(l2[0] == 3);

    }
    SECTION("Insert Head"){
        l3.insert(1.1, 0);
        List<char*> l4("char1");
        l4.insert("char0", 0);

        CHECK(l3.getSize() == 4);
        CHECK(l3[0] == 1.1);
        CHECK(l3[1] == 3.2);
        CHECK(l4[0] == "char0");
        CHECK(l4[1] == "char1");
        CHECK(l4.getSize() == 2);
    }
    SECTION("Insert Middle"){
        l3.insert(1.1, 2);
        List<char*> l4("char2");
        l4.insertHead("char0");
        l4.insert("char1", 1);

        CHECK(l3.getSize() == 4);
        CHECK(l3[1] == 4.2);
        CHECK(l3[2] == 1.1);
        CHECK(l3[3] == 5.2);

        CHECK(l4[0] == "char0");
        CHECK(l4[1] == "char1");
        CHECK(l4[2] == "char2");
        REQUIRE(l4.getSize() == 3);

    }
    SECTION("Insert Tail"){
        l3.insert(1.1, 3);
        List<char*> l4("char1");
        l4.insertHead("char0");
        l4.insert("char2", 2);

        CHECK(l3.getSize() == 4);
        CHECK(l3[1] == 4.2);
        CHECK(l3[2] == 5.2);
        CHECK(l3[3] == 1.1);

        CHECK(l4[0] == "char0");
        CHECK(l4[1] == "char1");
        CHECK(l4[2] == "char2");
        REQUIRE(l4.getSize() == 3);
    }
}


TEST_CASE("Remove from location", "[List]"){
    
    List<char> l('c');
    List<int> l2{};
    List<double> l3(5.2);
    l3.insertHead(4.2);
    l3.insertHead(3.2);


    SECTION("Remove empty"){
        CHECK_THROWS(l2.remove(4));
        CHECK_THROWS(l2.remove(-1));
        REQUIRE_THROWS(l2.remove(0));
    }

    SECTION("Remove Head"){
        l3.remove(0);

        List<char*> l4("char0");
        l4.insertHead("charx");
        l4.remove(0);
        List<int> l5(1);

        l5.remove(0);
        CHECK(l5.getSize() == 0);
        CHECK(l5.getHead() == nullptr);     

        CHECK(l3.getSize() == 2);
        CHECK(l3[0] == 4.2);
        CHECK(l3[1] == 5.2);
        CHECK(l4[0] == "char0");
        CHECK(l4.getSize() == 1);
        REQUIRE_THROWS(l4.remove(1));
    }
    SECTION("Remove Middle"){
        l3.remove(1);

        List<char*> l4("char1");
        l4.insertHead("charx");
        l4.insertHead("char0");
        l4.remove(1);

        CHECK(l3.getSize() == 2);
        CHECK(l3[0] == 3.2);
        CHECK(l3[1] == 5.2);

        CHECK(l4[0] == "char0");
        CHECK(l4[1] == "char1");
        REQUIRE(l4.getSize() == 2);
        REQUIRE_THROWS(l4.remove(2));
    }
    SECTION("Remove Tail"){
        l3.remove(2);

        List<char*> l4("charx");
        l4.insertHead("char1");
        l4.insertHead("char0");
        l4.remove(2);

        CHECK(l3.getSize() == 2);
        CHECK(l3[0] == 3.2);
        CHECK(l3[1] == 4.2);

        CHECK(l4[0] == "char0");
        CHECK(l4[1] == "char1");
        REQUIRE(l4.getSize() == 2);
        REQUIRE_THROWS(l4.remove(2));
    }
}
// int* a = new int[10];
// int* b = new int[10];
// a = b;
// delete b;