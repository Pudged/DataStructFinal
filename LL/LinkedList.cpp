#include "LinkedList.hpp"
#include <vector>

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
}

float LinkedList::insertLL(vector<int> data, int index)
{
    Node *temp = new Node;
    temp->key = data[index];
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }

    else 
    {
        Node *temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2 ->next = temp;
    }

    return 0;
}

float LinkedList::searchLL(int searchKey)  
{  
    Node *temp = head;

    while (temp != NULL)  
    {  
        if (temp->key == searchKey)
        {
            //cout << "FOUND" << endl;
            return 1;
        }
        temp = temp->next;  
    }  
    return 0;
}  


void LinkedList::displayLL()
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "Empty LL" << endl;
    }

    else
    {
        while (temp != NULL)
        {
            cout << temp->key << " -> ";
            temp = temp->next;
        }
    }
}
