#include <iostream>

using namespace std;

struct treeNode
{
    int key;
    treeNode *left = NULL;
    treeNode *right = NULL;

    treeNode (int insertKey)
    {
        key = insertKey;
    }
};

class BSTree
{
    private:
        treeNode *root;

    public:
        BSTree();
        ~BSTree();
        void insertBST(int key);
        void searchBST(int key);
        void printTree();
};