// Input : 
//                  1       ------  level 1
//                /   \ 
//               2     3    ------  level 2
//              / \     \ 
//             4   5     6   ------  level 3
//                  \
//                   7       ------  level 4
// LCA of (4,7) : 2

// Input :
//         1               ------   level 1
//       /   \ 
//     2       3           ------   level 2
//       \   
//         4               ------   level 3
//           \ 
//             5           ------   level 4
//              \ 
//                6        ------   level 5
// LCA of (4,6) : 4

#include<iostream>
#include <queue>

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
    root->left->right->right = new TreeNode(7 , nullptr , nullptr);
    root->right = new TreeNode (3 , nullptr , nullptr);
    root->right->right = new TreeNode (6 , nullptr , nullptr);
    return root;
}

TreeNode* lowest_common_ancestor (TreeNode* &root , TreeNode* &node1 , TreeNode* &node2) {
    if (root == nullptr) return nullptr;
    else {
        TreeNode* left_node = lowest_common_ancestor (root->left , node1 , node2);
        TreeNode* right_node = lowest_common_ancestor (root->right , node1 , node2);
        if (root == node1 || root == node2 || (left_node && right_node))  return root;
        else if (left_node) return left_node;
        else if (right_node) return right_node;
        else return nullptr;
    }
}

int find_distance (TreeNode* &root , TreeNode* &node) {
    int distance = 0;
    queue <pair <TreeNode* , int>> QUEUE;
    QUEUE.push ({root,0});

    while (!QUEUE.empty()) {
        size_t size = QUEUE.size();
        for (int i = 0 ; i < size ; i++) {
            auto temp = QUEUE.front();
            if (temp.first == node) return temp.second;
            if (temp.first->left != nullptr) QUEUE.push ({temp.first->left,temp.second+1});
            if (temp.first->right != nullptr) QUEUE.push ({temp.first->right,temp.second+1});
            QUEUE.pop();
        }
    }

}

int distance_between_nodes (TreeNode* &root , TreeNode* &node1 , TreeNode* &node2) {
    TreeNode* lca = lowest_common_ancestor (root , node1 , node2);
    int d1 = find_distance (lca , node1);
    int d2 = find_distance (lca , node2);

    return (d1+d2);
}

int main () {
    TreeNode* root = createTree();
    TreeNode* node1 = root->left->left;
    TreeNode* node2 = root->left->right->right;
    int distance =  distance_between_nodes (root , node1 , node2);
    cout << "Distance between " << node1->info << " and " << node2->info << " : " << distance << endl;
}