// Here I am passing the address of root to the function
// and as the function is processing the address so 
// there is no question of returning the address of root
// and no question of losing our root as well

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

struct TreeNode {
    int info;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

void insert_Data (TreeNode **root , int item , std::queue <TreeNode*> &Queue) {
    TreeNode *Node = new TreeNode;
    Node->info = item;
    Node->left = NULL;
    Node->right = NULL;

    if (*root == NULL)
        *root = Node;
    else if (Queue.front()->left == NULL)
        Queue.front()->left = Node;
    else {
        Queue.front()->right = Node;
        Queue.pop();
    }
    Queue.push(Node);
}

void constructTree (TreeNode **root , std::vector <int> &data) {
    std::queue <TreeNode*> Queue;
    for (auto item: data) {
        insert_Data (root , item , Queue);
    }
}

void Display_levelorder (TreeNode *root) {
    if (root == NULL) {std::cout << "Tree is empty...!!!\n";}
    else {
        std::queue <TreeNode*> Queue;
        Queue.push(root);
        while (! Queue.empty()) {
            std::cout << Queue.front()->info << " ";
            if (Queue.front()->left != NULL)
                Queue.push(Queue.front()->left);
            if (Queue.front()->right != NULL)
                Queue.push(Queue.front()->right);
            Queue.pop();
        }
    }
}

/*  Reading the data from input file */
void read_data_from_file (std::vector <int> &data) {
    std::ifstream myFile;
    myFile.open ("data.txt");
    if (! myFile.is_open())
        std::cerr << "File can't open\n";
    std::string num,line;
    std::getline(myFile,line);
    std::stringstream ss(line);
    while (std::getline (ss, num , ','))
        data.push_back(std::stoi(num));
    myFile.close();
}

int main()
{
    std::vector <int> data;
    read_data_from_file (data);
    TreeNode *root = NULL;
    constructTree (&root,data);
    // root = constructTree (root,data); // function returns the actual root
    Display_levelorder (root);
    return EXIT_SUCCESS;
}