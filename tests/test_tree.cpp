#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <Binary_tree.cpp>


using namespace std;


TEST(BinaryTreeTestGroup, BinaryTree) {
    // Arange
    const int expected_data = 10;
    Tree* myTree = new Tree();

    // Act
    myTree->root->key = expected_data;

    // Assert
    ASSERT_TRUE(myTree->root->key == expected_data);
}

TEST(BinaryTreeTestGroup, BinaryTreeInsertKey) {
    // Arange
    const int expected_data = 3;
    Tree* myTree = new Tree();

    // Act
    myTree->insert(expected_data);

    // Assert
    ASSERT_TRUE(myTree->root->key == expected_data);
}

TEST(BinaryTreeTestGroup, BinaryTreeInsertNode) {
    // Arange
    const int expected_key = 3;
    Tree* myTree = new Tree();
    Node* myNode = new Node(4);

    // Act
    myTree->insert(expected_key, myNode);
    Node* treeNode = myTree->root->right;

    // Assert
    ASSERT_TRUE(treeNode->key == expected_key);
}

TEST(BinaryTreeTestGroup, BinaryTreeDelete) {
    // Arange
    Tree* myTree = new Tree();

    // Act
    myTree->deleteTree();

    // Assert
    ASSERT_TRUE(myTree->root == nullptr);
}

TEST(BinaryTreeTestGroup, BinaryTreeEmpty) {
    // Arange
    const int expected_data = 3;
    Tree* myTree = new Tree();

    // Act
    myTree->insert(expected_data);
    bool isEmpty = myTree->IsEmpty();

    // Assert
    ASSERT_FALSE(isEmpty == true);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}