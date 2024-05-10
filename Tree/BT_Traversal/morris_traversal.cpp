// Input : 
//                  1       ------  level 1
//                /   \ 
//               2     3    ------  level 2
//              / \     \ 
//             4   5     6   ------  level 3


#include <iostream>

using namespace std;

struct TreeNode {
    TreeNode () : info (0) , left (nullptr) , right (nullptr) {}
    TreeNode (int data , struct TreeNode* left , struct TreeNode* right) :
    info (data) , left (left) , right (right) {}
    int info;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

TreeNode* createTree () {
    TreeNode* root = new TreeNode(1 , nullptr , nullptr);
    root->left = new TreeNode(2 , nullptr , nullptr);
    root->left->left = new TreeNode(4 , nullptr , nullptr);
    root->left->right = new TreeNode(5 , nullptr , nullptr);
    root->right = new TreeNode (3 , nullptr , nullptr);
    root->right->right = new TreeNode (6 , nullptr , nullptr);
    return root;
}

void morris_traversal (TreeNode* root) {
    TreeNode* current = root;
    while (current != nullptr) {
        if (!current->left) {   // if left is null then print the node and move right
            cout << current->info << " ";
            current = current->right;
        }
        else {
            TreeNode* previous = current->left;
            while (previous->right && previous->right != current)   // finding the right most node in leftr sub tree
                previous = previous->right;
            if (previous->right == nullptr) {   // if the right most node is null then create the link to root and move to left
                previous->right = current;
                // cout << current->info << " "; // for preorder (delete the print in else part) as before going to left print the current node
                current = current->left;
            }
            else {
                previous->right = nullptr;  // if the link already exist that means the left subtree is already visited, so, delink it, print the node and move right
                cout << current->info << " ";   // remove this for preorder traversal
                current = current->right;
            }
        }
    }
}

int main () {
    TreeNode* root = createTree ();
    morris_traversal (root);
    cout << endl;
}