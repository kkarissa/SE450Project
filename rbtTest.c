#include <deepstate/DeepState.hpp>
#include "rbt.h"  // Your Red-Black Tree header

using namespace deepstate; // combine tests with a for loop that either inserts or delete

// Test case for insertion
TEST(RBTTest, Insert) { //pick num, assert in there, do for delete and so on (about 6 times)
    RBTree tree = {NULL};  // Initialize an empty Red-Black Tree
    for (int i = 0; i < 6; i++) {
        int value = DeepState_IntInRange(0, 1000); //DeepState_Int();  // Generate a random integer value
        LOG(TRACE) << "inserted " << value;
        RBNode *node = add_rbnode(value);  // Create a node with the random value
        insert(&tree, node);  // Insert the node into the tree

        // Verify the value is in the tree
        RBNode *result = search(tree.root, value);
        ASSERT(result != NULL);  // Assert that the value is found (using ASSERT instead od DeepState_Assert)
        ASSERT(result->data == value);  // Assert that the correct value is returned

        int del_value = DeepState_IntInRange(0, 1000);
        node = add_rbnode(del_value);  // Create a node with the random value
        delete_node(&tree, node);

        LOG(TRACE) << "deleted " << del_value;

        result = search(tree.root, del_value);
        ASSERT(result == NULL); // Assert that the node is no longer found
    }
}
