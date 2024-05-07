#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

struct TreeNode {
    int info;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode* constructTree (TreeNode *head , std::vector<int> data) {

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

int main () {
    std::vector<int> data;
    read_data_from_file (data);
    TreeNode *head = constructTree (head , data);
    return EXIT_SUCCESS;
}