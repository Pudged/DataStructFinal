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
        key = -1;
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
            table = new HashNodeLin * [40009];
            for (int i = 0; i < size; i++)
            {
                table[i] = 0;
            }
        }

        ~HashTableLin() 
        { 
            delete[] table; 
        }

        void insert (int key);
        HashNodeLin *search(int key);
        int hashCode(int k, int table_size);
        void printHashTable();
};