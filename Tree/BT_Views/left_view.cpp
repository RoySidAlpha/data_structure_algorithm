// Input : 
//                  1       ------  level 1
//                /   \ 
//               2     3    ------  level 2
//              / \     \ 
//             4   5     6   ------  level 3
// Left View : 1 2 4

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
// Left View :1 2 4 5 6

#include<iostream>
#include <vector>
#include <map>
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

std::vector <int> leftView (TreeNode *root) {
    std::map <int , int> mp;
    std::vector <int> LeftView;
    std::queue <std::pair <TreeNode* , int>> Queue;
    if (root != NULL) { Queue.push ({root,0}); }    // cause root is situated in 0 level
    while (! Queue.empty()) {
        TreeNode* current = Queue.front().first;
        int level = Queue.front().second;
        Queue.pop();
        if (!mp.count(level)) {      // If this node is the first node from left in this level then store it
            mp[level] = current->info;
            LeftView.push_back (current->info);
        }
        if (current->left != NULL)                  // statement - 1
            Queue.push ({current->left,level+1}); // level increases in next level
        if (current->right != NULL)                 // statemen - 2
            Queue.push ({current->left,level+1});
    }
    return LeftView;
}

int main()
{
    TreeNode *root = NULL;
    createTree (&root);
    std::vector <int> LeftView = leftView (root);
    for (auto item : LeftView)
        std::cout << item << " ";
    std::cout <<std::endl;
    return 0;
}

/*

In case of Right View just interchange statement 1 & statement 2

*/