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
}

void printLeftBoundary (TreeNode *root) {
    if (root != NULL) {
        if (root->left != NULL) {
            std::cout << root->info << " ";
            printLeftBoundary (root->left);
        }
        else if (root->right != NULL) {
	    std::cout << root->info << " ";
            printLeftBoundary (root->right);
        }
    }
}

void printRightBoundary (TreeNode *root) {
    if (root != NULL) {
        if (root->right != NULL) {
            std::cout << root->info << " ";
            printRightBoundary (root->right);
        }
        else if (root->left != NULL) {
            std::cout << root->info << " ";
            printRightBoundary (root->left);
        }
    }
}

void printLeaves (TreeNode *root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL)
            std::cout << root->info << " ";
        printLeaves (root->left);
        printLeaves (root->right);
    }
}

void boundary_traversal (TreeNode *root) {
    /*left boundary*/
    if (root != NULL) {
        std::cout << root->info << " ";
        printLeftBoundary (root->left);
        printLeaves (root->left);
        printLeaves (root->right);
        printRightBoundary (root->right);
    }
    /*leaves*/
    /*right boundary*/
}

int main () {
    TreeNode *root;
    createTree (&root);
    boundary_traversal (root);
}