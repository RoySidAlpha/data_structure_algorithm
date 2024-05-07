#include <iostream>
#include <vector>

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

void store_left_view (TreeNode *root , std::vector <int> &result , int level) {
    if (root != NULL) {
        
        if (level == result.size()) {
            result.push_back (root->info);
        }
        
        store_left_view (root->left , result , level+1);
        store_left_view (root->right , result , level+1);
    }
}

std::vector<int> leftView(TreeNode *root) {
   // Your code here
   std::vector <int> result;
   store_left_view (root , result , 0);
   return result;
}

int main () {
    TreeNode *root;
    createTree (&root);
	std::vector <int> result;
	result = leftView (root);
	std::cout << "The left view of the tree is : ";
	for (int i = 0 ; i < result.size() ; i++)
		std::cout << result[i] << " ";
	std::cout << std::endl;
}