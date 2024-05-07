#include <iostream>

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
    (*root)->left->left->left = newNode (6);
    (*root)->left->left->left->left = newNode (7);
}

int height_of_tree (TreeNode *root) {
    if (root == NULL) { return 0; }
    else { return std::max (height_of_tree(root->left) , height_of_tree(root->right))+1; }
}

int main () {
    TreeNode *root;
    createTree (&root);
    std::cout << "height of tree is : " << height_of_tree (root) << std::endl;
}