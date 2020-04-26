#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

struct HashNodeQuad
{
    int key;

    HashNodeQuad()
    {
        key = 0;
    }

    HashNodeQuad(int insertKey)
    {
        key = insertKey;
    }

    ~HashNodeQuad() {}

};

class HashTableQuad
{
    HashNodeQuad **table;
    int size;
    

    public:
        HashTableQuad()
        {
            size = 40009;
            insertCollisions = 0;
            searchCollisions = 0;
            table = new HashNodeQuad * [size];
            for (int i = 0; i < size; i++)
            {
                table[i] = NULL;
            }
        }

        ~HashTableQuad() 
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