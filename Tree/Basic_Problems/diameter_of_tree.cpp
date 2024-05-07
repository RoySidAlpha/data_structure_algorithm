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
    (*root)->left->left->left = newNode (6);
    (*root)->left->left->left->left = newNode (7);
    (*root)->right = newNode (3);
}

int height_of_tree (TreeNode *root) {
    if (root == NULL) { return 0; }
    else { return std::max (height_of_tree(root->left) , height_of_tree(root->right))+1; }
}

int diameter_of_tree (TreeNode *root) {
    if (root == NULL) { return 0; }
    else {
        return std::max ((height_of_tree(root->left)+height_of_tree(root->right)+1), \
                        std::max (diameter_of_tree(root->left), diameter_of_tree(root->right)));
    }
}

int main () {
    TreeNode *root;
    createTree (&root);
    std::cout << "The diameter of tree is : " << diameter_of_tree (root) << std::endl;
}