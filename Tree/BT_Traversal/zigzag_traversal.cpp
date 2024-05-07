#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int info;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

TreeNode* newNode (int data) {
    TreeNode *Node = new TreeNode;
    Node->info = data;
    Node->left = Node->right = NULL;
    return Node;
}

void createTree (TreeNode **root) {
    (*root) = newNode (1);
    (*root)->left = newNode (2);
    (*root)->left->left = newNode (4);
    (*root)->left->right = newNode (5);
    (*root)->right = newNode (3);
}

std::vector <std::vector <int>> zigzag_traversal (TreeNode *root) {
    std::vector <std::vector <int>> result;
        std::queue <TreeNode*> Queue;
        Queue.push (root);
        bool LeftToRight = true;
        while (! Queue.empty()) {
        int size_of_queue = Queue.size();
        std::vector <int> row (size_of_queue);
        for (int i = 0 ; i < size_of_queue ; i++) {
            // Always push left node and then right node
            if (Queue.front()->left) {Queue.push (Queue.front()->left);}
            if (Queue.front()->right) {Queue.push (Queue.front()->right);}
            // Find the correct index to store the data in correct position
            // If LeftToRight is true then fill the row as {1,2,3,.....(size-1)}
            // If LeftToRight is false then fill the row as {(size-1),......3,2,1}
            int index = LeftToRight ? i : (size_of_queue-i-1);
            row [index] = Queue.front()->info;
            Queue.pop();
        }
        result.push_back (row); // push the row in result one by one
        LeftToRight = !LeftToRight; // reversing the order (L->R) <=> (R->L)
    }
    return result;
}

void display_result (std::vector <std::vector <int>> result) {
    for (auto &row: result) {
        for (auto &item: row) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}

int main () {
    TreeNode *root;
    createTree (&root);
    display_result (zigzag_traversal (root));
}