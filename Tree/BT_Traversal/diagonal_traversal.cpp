#include <bits/stdc++.h>

using namespace std;

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

unordered_map <int , unordered_set<int>> diag_nodes (TreeNode* root) {
    unordered_map <int , unordered_set<int>>diag;
    queue <pair <TreeNode* , int>>Q;
    if (root != NULL) {
        Q.push({root,0});
        int max_dd = 0;
        while (!Q.empty()) {
            TreeNode* current = Q.front().first;
            int dd = Q.front().second;
            max_dd = max(max_dd , dd);
            diag[dd].emplace(current->info);
            if (current->left != NULL)
                Q.push({current->left,dd+1});
            if (current->right != NULL)
                Q.push({current->right,dd});
            Q.pop();
        }
    }
    return diag;
}


bool diagonal_traversal (TreeNode *root1 , TreeNode *root2) {
    unordered_map <int , unordered_set<int>> diag1 = diag_nodes (root1);
    unordered_map <int , unordered_set<int>> diag2 = diag_nodes (root2);
    
    if (diag1.size() != diag2.size())
        return false;
    else {
        for (int i = 0 ; i < diag1.size() ; i++)
            if (diag1[i] != diag2[i])
                return false;
    }
    return true;
}

int main () {
    TreeNode *root1;
    createTree (&root1);
    TreeNode *root2;
    createTree (&root2);
    bool result = diagonal_traversal (root1 , root2);
	std::cout << "result : " << result << "\n";
}