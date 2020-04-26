#include "BST.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

BSTree::BSTree()
{
    root = NULL;
}

void treeDestructor (treeNode *currNode)
{
  if (currNode == NULL)
  {
    return;
  }

  else
  {
    treeDestructor(currNode->left);
    treeDestructor(currNode->right);

    delete currNode;
  }
}

BSTree::~BSTree()
{
    treeDestructor(root);
}

void addNodeHelper(treeNode* currNode, treeNode* newNode)
{
    if (currNode->key > newNode->key)
    {
        if (currNode->left == NULL)
        {
            currNode->left = newNode;
        }

        else
        {
            addNodeHelper(currNode->left, newNode);
        }
        
    }

    else
    {
        if (currNode->right == NULL)
        {
            currNode->right = newNode;
        }

        else
        {
            addNodeHelper(currNode->right, newNode);
        }
        
    }

}

void BSTree::insertBST(int key)
{
    treeNode *newNode = new treeNode(key);
    
    if (root != NULL)
    {
        addNodeHelper(root, newNode);
    }

    else
    {
        root = newNode;
    }
}

treeNode *searchHelper(treeNode *currNode, int searchKey)
{
    if (currNode == NULL)
    {
        return NULL;
    }

    if (currNode->key == searchKey)
    {
        return (currNode);
    }

    if (currNode->key > searchKey)
    {
        return searchHelper(currNode->left, searchKey);
    }
    return searchHelper(currNode->right, searchKey);
}

void BSTree::searchBST(int key)
{
    searchHelper(root, key);
}

void printTreeHelper(treeNode* currNode){ // in order traverser
    if (currNode == NULL)
    {
        return;
    }
        printTreeHelper( currNode->left);
        cout << currNode->key << " ";
        printTreeHelper( currNode->right);
}

void BSTree::printTree()
{
    if (root == NULL)
    {
        cout << "Tree is Empty. Cannot print" << endl;
    }

    else
    {
        printTreeHelper(root);
    }
}