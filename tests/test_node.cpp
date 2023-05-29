#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <Node.cpp>


using namespace std;


TEST(NodeTestGroup, NodeTest) {
    // Arange
    const int key = 4;

    // Act
    Node* node = new Node(key);

    // Assert
    ASSERT_TRUE(node->key == key);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}