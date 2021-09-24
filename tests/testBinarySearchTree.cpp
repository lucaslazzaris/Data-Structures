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
}

TEST_CASE("searchNode", "[BinarySearchTree]"){
    Node<int>* node1 = new(Node<int>);
    Node<int>* node2 = new(Node<int>);
    Node<int>* node3 = new(Node<int>);
    Node<int>* node4 = new(Node<int>);
    node1->setValue(10);
    node2->setValue(9);
    node3->setValue(11);
    node4->setValue(7);
    node1->setLeft(node2);
    node1->setRight(node3);
    node2->setLeft(node4);
    BinarySearchTree<int> tree{node1}; 

    SECTION("Minimum") {
        auto nodeFound = tree.searchNode(tree.getRoot(), 7);
        REQUIRE(nodeFound == node4);
    }
    SECTION("Maximum") {
        auto nodeFound = tree.searchNode(tree.getRoot(), 11);
        REQUIRE(nodeFound == node3);
    }
    SECTION("Middle") {
        auto nodeFound = tree.searchNode(tree.getRoot(), 9);
        REQUIRE(nodeFound == node2);
    }
    SECTION("Not Found") {
        auto nodeFound = tree.searchNode(tree.getRoot(), 19);
        REQUIRE(nodeFound == nullptr);
    }
}

TEST_CASE("iterativeSearchNode", "[BinarySearchTree]"){
    Node<int>* node1 = new(Node<int>);
    Node<int>* node2 = new(Node<int>);
    Node<int>* node3 = new(Node<int>);
    Node<int>* node4 = new(Node<int>);
    node1->setValue(10);
    node2->setValue(9);
    node3->setValue(11);
    node4->setValue(7);
    node1->setLeft(node2);
    node1->setRight(node3);
    node2->setLeft(node4);
    BinarySearchTree<int> tree{node1}; 

    SECTION("Minimum") {
        auto nodeFound = tree.iterativeSearchNode(tree.getRoot(), 7);
        REQUIRE(nodeFound == node4);
    }
    SECTION("Maximum") {
        auto nodeFound = tree.iterativeSearchNode(tree.getRoot(), 11);
        REQUIRE(nodeFound == node3);
    }
    SECTION("Middle") {
        auto nodeFound = tree.iterativeSearchNode(tree.getRoot(), 9);
        REQUIRE(nodeFound == node2);
    }
    SECTION("Not Found") {
        auto nodeFound = tree.iterativeSearchNode(tree.getRoot(), 19);
        CHECK(nodeFound == nullptr);
        CHECK(tree.getRoot() == node1);
        CHECK(node1->getLeft() == node2);
        CHECK(node1->getRight() == node3);
        REQUIRE(node2->getLeft() == node4);
    }
}


TEST_CASE("Minimum and Maximum", "[BinarySearchTree]") {
    Node<int>* node1 = new(Node<int>);
    Node<int>* node2 = new(Node<int>);
    Node<int>* node3 = new(Node<int>);
    Node<int>* node4 = new(Node<int>);
    node1->setValue(10);
    node2->setValue(9);
    node3->setValue(11);
    node4->setValue(7);
    node1->setLeft(node2);
    node1->setRight(node3);
    node2->setLeft(node4);
    BinarySearchTree<int> tree{node1}; 

    SECTION("Minimum") {
        auto nodeFound = tree.minimum(tree.getRoot());
        REQUIRE(nodeFound == node4);
    }
    SECTION("Maximum") {
        auto nodeFound = tree.maximum(tree.getRoot());
        REQUIRE(nodeFound == node3);
    }
}

TEST_CASE("Successor", "[BinarySearchTree]") {
    Node<int>* node1 = new(Node<int>);
    Node<int>* node2 = new(Node<int>);
    Node<int>* node3 = new(Node<int>);
    Node<int>* node4 = new(Node<int>);
    Node<int>* node5 = new(Node<int>);
    Node<int>* node6 = new(Node<int>);
    Node<int>* node7 = new(Node<int>);
    Node<int>* node8 = new(Node<int>);
    Node<int>* node9 = new(Node<int>);
    Node<int>* node10 = new(Node<int>);
    Node<int>* node11 = new(Node<int>);
    node1->setValue(15);
    node2->setValue(6);
    node3->setValue(18);
    node4->setValue(3);
    node5->setValue(7);
    node6->setValue(17);
    node7->setValue(20);
    node8->setValue(2);
    node9->setValue(4);
    node10->setValue(13);
    node11->setValue(9);

    node1->setLeft(node2);
    node1->setRight(node3);
    node2->setLeft(node4);
    node2->setRight(node5);
    node3->setLeft(node6);
    node3->setRight(node7);
    node4->setLeft(node8);
    node4->setRight(node9);
    node5->setRight(node10);
    node10->setLeft(node11);

    BinarySearchTree<int> tree{node1}; 

    SECTION("Minimum") {
        auto nodeFound = tree.successor(node8);
        REQUIRE(nodeFound == node4);
    }
    SECTION("Maximum") {
        auto nodeFound = tree.successor(node7);
        REQUIRE(nodeFound == nullptr);
    }
    SECTION("Has Right sub tree") {
        auto nodeFound = tree.successor(node5);
        REQUIRE(nodeFound == node11);
    }
    SECTION("Doesn't have Right sub tree") {
        auto nodeFound = tree.successor(node10);
        REQUIRE(nodeFound == node1);
    }
}


TEST_CASE("Insert", "[BinarySearchTree]") {
    SECTION("Empty tree") {
        Node<int>* node1 = new(Node<int>);
        node1->setValue(15);
        BinarySearchTree<int> tree; 
        tree.insert(node1);
        CHECK(tree.getRoot() == node1);
        CHECK(node1->getLeft() == nullptr);
        CHECK(node1->getRight() == nullptr);
        REQUIRE(node1->getParent() == nullptr);
    }

    SECTION("Three nodes tree") {
        Node<int>* node1 = new(Node<int>);
        Node<int>* node2 = new(Node<int>);
        Node<int>* node3 = new(Node<int>);
        node1->setValue(15);
        node2->setValue(14);
        node3->setValue(16);
        BinarySearchTree<int> tree; 
        tree.insert(node1);
        tree.insert(node2);
        tree.insert(node3)
        ;
        CHECK(tree.getRoot() == node1);
        CHECK(node1->getLeft() == node2);
        CHECK(node1->getRight() == node3);
        CHECK(node1->getParent() == nullptr);
        CHECK(node2->getParent() == node1);
        REQUIRE(node3->getParent() == node1);
    }
}

TEST_CASE("Remove", "[BinarySearchTree]"){
    SECTION("Empty Tree"){
        BinarySearchTree<int> tree; 
        tree.remove(nullptr);
        CHECK(tree.getRoot() == nullptr);
        REQUIRE(tree.getSize() == 0);

    }

    SECTION("Only root"){
        Node<int>* node = new(Node<int>);
        node->setValue(15);
        BinarySearchTree<int> tree(node);

        tree.remove(node);

        CHECK(tree.getRoot() == nullptr);
        REQUIRE(tree.getSize() == 0);
    }

    SECTION("Only left child"){
        Node<int>* node1 = new(Node<int>);
        Node<int>* node2 = new(Node<int>);
        node1->setValue(15);
        node2->setValue(14);

        BinarySearchTree<int> tree(node1);
        tree.insert(node2);

        tree.remove(node1);

        CHECK(tree.getRoot() == node2);
        REQUIRE(tree.getSize() == 1);
    }

    SECTION("Only right child"){
        Node<int>* node1 = new(Node<int>);
        Node<int>* node2 = new(Node<int>);
        node1->setValue(15);
        node2->setValue(16);

        BinarySearchTree<int> tree(node1);
        tree.insert(node2);

        tree.remove(node1);

        CHECK(tree.getRoot() == node2);
        REQUIRE(tree.getSize() == 1);
    }

    SECTION("Right child is the successor"){
        Node<int>* node1 = new(Node<int>);
        Node<int>* node2 = new(Node<int>);
        Node<int>* node3 = new(Node<int>);
        node1->setValue(15);
        node2->setValue(16);
        node3->setValue(14);

        BinarySearchTree<int> tree(node1);
        tree.insert(node2);
        tree.insert(node3);

        tree.remove(node1);

        CHECK(tree.getRoot() == node2);
        CHECK(tree.getRoot()->getLeft() == node3);
        CHECK(node3->getParent() == node2);
        REQUIRE(tree.getSize() == 2);
    }

    SECTION("Right child is not the successor"){
        Node<int>* node1 = new(Node<int>);
        Node<int>* node2 = new(Node<int>);
        Node<int>* node3 = new(Node<int>);
        Node<int>* node4 = new(Node<int>);
        node1->setValue(15);
        node2->setValue(17);
        node3->setValue(14);
        node4->setValue(16);

        BinarySearchTree<int> tree(node1);
        tree.insert(node2);
        tree.insert(node3);
        tree.insert(node4);

        tree.remove(node1);

        CHECK(tree.getRoot() == node4);
        CHECK(tree.getRoot()->getLeft() == node3);
        CHECK(tree.getRoot()->getRight() == node2);
        CHECK(node3->getParent() == node4);
        CHECK(node2->getParent() == node4);
        REQUIRE(tree.getSize() == 3);
    }
}