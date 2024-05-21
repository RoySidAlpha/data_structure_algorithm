// Input: parent[] = {1, 5, 5, 2, 2, -1, 3}
// Output: root of below tree
//           5
//         /  \ 
//        1    2
//       /    / \ 
//      0    3   4
//          /
//         6 
// Explanation: 
// Index of -1 is 5.  So 5 is root.  
// 5 is present at indexes 1 and 2.  So 1 and 2 are
// children of 5.  
// 1 is present at index 0, so 0 is child of 1.
// 2 is present at indexes 3 and 4.  So 3 and 4 are
// children of 2.  
// 3 is present at index 6, so 6 is child of 3.


// Input: parent[] = {-1, 0, 0, 1, 1, 3, 5};
// Output: root of below tree
//          0
//        /   \ 
//       1     2
//      / \ 
//     3   4
//    /
//   5 
//  /
// 6

#include<iostream>
#include <unordered_map>
#include <vector>
#include <queue>

class TreeNode {
    public :
        int info;
        TreeNode *left;
        TreeNode *right;
        TreeNode (int data) {
            info = data;
            left = NULL;
            right = NULL;
        }
};

class display {
    public :
        TreeNode *root;
        void display_level_order () {
            if (root == NULL) { std::cout << "Tree is empty"; }
            else {
                std::queue <TreeNode*> Queue;
                Queue.push (root);
                while (! Queue.empty()) {
                    TreeNode *current = Queue.front();
                    std::cout << current->info << " ";
                    if (current->left != NULL) { Queue.push (current->left); }
                    if (current->right != NULL) { Queue.push (current->right); }
                    Queue.pop ();
                }
                std::cout << std::endl;
            }
        }
};

TreeNode* createTreeFromParentArray (std::vector <int> parent_array) {
    std::unordered_map <int , std::vector<int>> mp;
    for (int i = 0 ; i < parent_array.size() ; i++)
        mp[parent_array[i]].push_back(i);
    std::queue <TreeNode*> Queue;
    TreeNode* root = new TreeNode (mp[-1][0]);
    Queue.push (root);
    while (!Queue.empty()) {
        TreeNode *current = Queue.front();
        int key = current->info;
        for (int i = 0 ; i < mp[key].size() ; i++) {
            switch (i) {
                case 0: current->left = new TreeNode (mp[key][i]);
                        Queue.push (current->left);
                        break;
                case 1: current->right = new TreeNode (mp[key][i]);
                        Queue.push (current->right);
                        break;
            }
        }
        Queue.pop();
    }
    return root;
}

int main()
{
    std::vector <int> parent_array = {-1, 0, 0, 1, 1, 3, 5, 0, 4};
    display DISPLAY;
    DISPLAY.root = createTreeFromParentArray (parent_array);
    DISPLAY.display_level_order();
    return EXIT_SUCCESS;
}