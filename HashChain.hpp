#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <math.h>

using namespace std;

struct HashNode
{
    int key;
    HashNode *next;

    HashNode()
    {
        key = 0;
        next = 0;
    }

    HashNode(int insertkey)
    {
        key = insertkey;
        next = 0;
    }

    ~HashNode()
    {}

};

class HashTable
{
    HashNode **table;
    int size;

    public:
        HashTable()
        {
            size = 40009;
            table = new HashNode *[size];

            for (int i = 0; i < size; i++)
            {
                table[i] =0;
            }
        }

        ~HashTable()
        {
            for (int i = 0; i < size; i++)
            {
                HashNode *temp = table[i];
                while (temp != 0)
                {
                    HashNode *currNode = temp;
                    temp = temp->next;
                    delete currNode;
                }
            }
            delete [] table;
        }

        void insert (int key);
        void search (int key);
        int hashCode (int k);
        void printHashTable();
};