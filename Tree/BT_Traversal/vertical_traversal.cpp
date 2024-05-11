// Input : 
//                  1       ------  level 1
//                /   \ 
//               2     3    ------  level 2
//              / \     \ 
//             4   5     6   ------  level 3


#include <iostream>
#include <queue>
#include <map>

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

void vertical_traversal (TreeNode* &root) {
    queue <pair <TreeNode* , int >> QUEUE;
    map <int , vector <TreeNode*>> result;
    if (root != nullptr) QUEUE.push ({root,0});
    
    while (QUEUE.size()) {
        size_t k = QUEUE.size();
        for (int i = 0 ; i < k ; i++) {
            auto temp = QUEUE.front();
            TreeNode* node = temp.first;
            int rank = temp.second;
            result[rank].push_back (node);
            if (node->left) QUEUE.push ({node->left , rank-1});
            if (node->right) QUEUE.push ({node->right , rank+1});
            QUEUE.pop();
        }
    }
    for (auto it = result.begin() ; it != result.end() ; it++) {
        int pos = it->first;
        for (int i = 0 ; i < result[pos].size() ; i++)
            cout << result[pos][i]->info << " ";
        cout << endl;
    }
}

int main () {
    TreeNode* root =  createTree ();
    vertical_traversal (root);
    return EXIT_SUCCESS;
}