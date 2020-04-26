#include "HashChain.hpp"

using namespace std;

void HashTable::insert(int key)
{
    int index = hashCode(key);
    HashNode *newNode = new HashNode(key);

    if (table[index] == 0)
    {
        table[index] = newNode;
    }

    else
    {
        insertCollisions++;
        newNode->next = table[index];
        table[index] = newNode;
    }
    
}

void HashTable::search(int key)
{
    int index = hashCode(key);
    
    if (table[index] == 0)
    {
        return;
    }

    else
    {
        
        HashNode *currNode = table[index];
        while(currNode != 0)
        {
            if (currNode->key == key)
            {
                
                return;
            }

            else
            {
                searchCollisions++;
                currNode = currNode->next;
            }
            
        }
        return;
    }
}


int HashTable::hashCode(int k)
{
    return k % size;
}

void HashTable::printHashTable()
{
    for (int i = 0; i < size; i++)
    {
        if (table[i] != 0)
        {
            cout <<"[" << i << "] ";
            HashNode *currNode = table[i];

            while (currNode != 0)
            {
                cout << "-> Key: " << currNode->key << " (#" << hashCode(currNode->key) << ")"; 	  
	            currNode = currNode->next;
            }
            cout << endl;
        }
        else
        {
            cout << "[" << i << "] -> Empty" << endl;
        }
    }
}