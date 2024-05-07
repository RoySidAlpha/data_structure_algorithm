#include <iostream>
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

void level_order (TreeNode *root) {
    std::queue <TreeNode*> Queue;
    Queue.push(root);
    while (!Queue.empty())
    {
        std::cout << Queue.front()->info << " ";
        if (Queue.front()->left != NULL)
            Queue.push(Queue.front()->left);
        if (Queue.front()->right != NULL)
            Queue.push(Queue.front()->right);
        Queue.pop();
    }
    
}

void inorder (TreeNode *root) {
    if (root != NULL) {
        inorder (root->left);
        std::cout << root->info << " ";
        inorder (root->right);
    }
}

void preorder (TreeNode *root) {
    if (root != NULL) {
        std::cout << root->info << " ";
        preorder (root->left);
        preorder (root->right);
    }
}

void postorder (TreeNode *root) {
    if (root != NULL) {
        postorder (root->left);
        postorder (root->right);
        std::cout << root->info << " ";
    }
}

int main () {
    TreeNode *root;
    createTree (&root);
    std::cout << "Inorder traversal : ";
    inorder (root);
    std::cout << "\nPre-order traversal : ";
    preorder (root);
    std::cout << "\nPost-order traversal : ";
    postorder (root);
    std::cout << "\nLevel-order traversal : ";
    level_order (root);
}