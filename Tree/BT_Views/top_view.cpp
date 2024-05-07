//        1
//     /     \ 
//    2       3
//   /  \    / \ 
//  4    5  6   7
// Top view of the above binary tree is
// 4 2 1 3 7 {level(4)=-2 , level(2)=-1 , level(1)=0 , level(3) = 1 , level(7) = 2}

//         1
//       /   \ 
//     2       3
//       \   
//         4  
//           \ 
//             5
//              \ 
//                6
// Top view of the above binary tree is
// 2 1 3 6

// complexity : O(n) where n = no. of nodes in binary tree

#include<iostream>
#include <map>
#include <vector>
#include <queue>

class TreeNode {
    public:
        int info;
        TreeNode* left;
        TreeNode* right;
        TreeNode (int data) {
            info = data;
            left = NULL;
            right = NULL;
        }
};

void createTree (TreeNode **root) {
    (*root) = new TreeNode (1);
    (*root)->left = new TreeNode (2);
    (*root)->left->left = new TreeNode (4);
    (*root)->left->right = new TreeNode (5);
    (*root)->right = new TreeNode (3);
    (*root)->right->left = new TreeNode (6);
    (*root)->right->right = new TreeNode (7);
}

std::vector <int> TreeTopView (TreeNode *root) {
    std::vector <int> TopView;
    std::map <int , int> mp;
    std::queue <std::pair <TreeNode* , int>> Queue;
    if (root != NULL) { Queue.push ({root,0}); } // or we can push "std::pair<TreeNode*,int>(root,0)"
    while (!Queue.empty()) {
        TreeNode* current = Queue.front().first;
        int vertical_level = Queue.front().second;
        Queue.pop();
        // check if this node is first in this 'level' by searching in map
        if (!mp.count(vertical_level)) { mp[vertical_level] = current->info; }
        // push the left node and its level in queue
        if (current->left != NULL) { Queue.push ({current->left,vertical_level-1}); }
        // push the right node and its level in queue
        if (current->right != NULL) { Queue.push ({current->right,vertical_level+1}); }
    }
    for (auto it : mp)
        TopView.push_back (it.second);  // fetch the node data in vector and then return
    return TopView;
}

int main()
{
    TreeNode *root = NULL;
    createTree (&root);
    std::vector <int> TopView = TreeTopView (root);
    // Displaying the vector
    for (auto item : TopView)
        std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}