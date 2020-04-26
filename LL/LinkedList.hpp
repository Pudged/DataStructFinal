// Linked List header for USPS Final Project
#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int key;
    Node *next;
};

class LinkedList
{
    private:
        Node *head;
    
    public:
        LinkedList();
        float insertLL(vector<int> data, int startIndex);
        float searchLL(int searchKey);
        void displayLL();
};