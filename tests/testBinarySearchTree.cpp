#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../BinarySearchTree.cpp"

TEST_CASE("Node Constructor", "[Node]"){
    SECTION("Default Constructor"){
        Node<int> n{};
        CHECK(n.getLeft() == nullptr);
        CHECK(n.getRight() == nullptr);
        CHECK(n.getParent() == nullptr);
        REQUIRE(n.getValue() == 0);
    }

    SECTION("Value Constructor"){
        Node<int> n(5);
        CHECK(n.getLeft() == nullptr);
        CHECK(n.getRight() == nullptr);
        CHECK(n.getParent() == nullptr);
        REQUIRE(n.getValue() == 5);
    }

    SECTION("Passing node constructor"){
        Node<int> n1(5);
        Node<int> n2(5);
        Node<int> n3(6, &n1, &n2, nullptr);
        CHECK(n3.getParent() == nullptr);
        CHECK(n3.getRight() == &n2);
        CHECK(n3.getLeft() == &n1);
        REQUIRE(n3.getValue() == 6);
    }

    // Just to train how to work with smart pointers
    SECTION("Passing node constructor with smart pointer"){
        std::unique_ptr<Node<int>> n1 = std::make_unique<Node<int>>(5);
        std::unique_ptr<Node<int>> n2 = std::make_unique<Node<int>>(5);
        Node<int> n3(6, n1.get(), n2.get(), nullptr);
        CHECK(n3.getParent() == nullptr);
        CHECK(n3.getRight() == n2.get());
        CHECK(n3.getLeft() == n1.get());
        REQUIRE(n3.getValue() == 6);
    }
}

TEST_CASE("Test Binary Search Tree Constructors", "[BinarySearchTree]"){
    SECTION("Default Constructor"){
        BinarySearchTree<int> tree{};
        CHECK(tree.getRoot()==nullptr);
        REQUIRE(tree.getSize()==0);
    }
    
    SECTION("Root constructor"){
        Node<int>* node = new(Node<int>);
        node->setValue(5);
        BinarySearchTree<int> tree(node);
    
        REQUIRE(tree.getSize() == 1);
        CHECK(tree.getRoot() == node);
    }

    // SECTION("Copy constructor does not copy pointer"){
    //     BinarySearchTree<int> a1(4);
    //     BinarySearchTree<int> a2(a1);
    //     a1[1] = 2;
    //     a2[1] = 3;
    //     CHECK(a1[1] == 2);
    //     REQUIRE(a2[1] == 3);
    // }
}