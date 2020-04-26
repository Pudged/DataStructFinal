#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

struct HashNodeLin
{
    int key;

    HashNodeLin()
    {
        key = 0;
    }

    HashNodeLin(int insertKey)
    {
        key = insertKey;
    }

    ~HashNodeLin() {}

};

class HashTableLin
{
    HashNodeLin **table;
    int size;
    

    public:
        HashTableLin()
        {
            size = 40009;
            insertCollisions = 0;
            searchCollisions = 0;
            table = new HashNodeLin * [size];
            for (int i = 0; i < size; i++)
            {
                table[i] = NULL;
            }
        }

        ~HashTableLin() 
        { 
            delete[] table; 
        }

        void insert (int key);
        void search(int key);
        int hashCode(int k);
        void printHashTable();
        int insertCollisions;
        int searchCollisions;
};