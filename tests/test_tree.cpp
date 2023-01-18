#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <../source/main.cpp>


TEST(AvlTreeTestGroup, AvlTreeInsert) {
    // Arange
    const int expected_data = 10;
    struct node* root = NULL;

    // Act
    root = insert(root, expected_data);

    // Assert
    ASSERT_TRUE(root->key == expected_data);
}

TEST(AvlTreeTestGroup, AvlTreeIsEmpty) {
    // Arange
    const int expected_data = 10;
    struct node* root = NULL;

    // Act
    root = insert(root, expected_data);
    root = deleteNode(root, expected_data);

    // Assert
    ASSERT_TRUE(root == nullptr);
}

TEST(AvlTreeTestGroup, AvlTreeRemove) {
    // Arange
    struct node* root = NULL;

    // Act
    bool empty_flag = IsEmpty(root);

    // Assert
    ASSERT_TRUE(empty_flag);
}

TEST(AvlTreeTestGroup, AvlTreeToString) {
    // Arange
    struct node* root = NULL;
    std::string expected = " 1  3  4  6  7  8  10  14 ";

    // Act
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    // Assert
    ASSERT_TRUE(ToString(root) == expected);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
