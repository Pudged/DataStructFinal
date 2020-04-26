#include "HashLin.hpp"

using namespace std;

void HashTableLin::insert(int key)
{
    HashNodeLin *node = new HashNodeLin (key);
    int index = hashCode(key);

    if (table[index] == 0)
    {
      table[index] = node;
    }

    else
    {
      for (int i = (index + 1) % size; i != index; i = (i + 1) % size)
      {
        if (table[i] == 0)
        {
          table[i] = node;
          return;
        }
        else if (table[i]->key != key)
        {
          insertCollisions ++;
        }
      }
      cout << "Can not insert (" << key << ")Table is full" << endl;
      return;
    }
}

void HashTableLin::search(int searchKey)
{
    int index = hashCode(searchKey);
    int count = 0;

    while (table[index] != NULL)
    {
      int count2 = 0;

      if (count2 + 1 > size)
      {
        return;
      }

      if (table[index]->key != searchKey)
      {
        searchCollisions++;
      }
      if (table[index]->key == searchKey)
      {
        return;
      }
      index ++;
      index = index % size;
    }
}

int HashTableLin::hashCode(int k)
{
    return k % size;
}

void HashTableLin::printHashTable()
  {
    for (int i = 0; i < size; i++)
    {
      if (table[i] != 0)
      {
        cout << "[" << i << "] -> Key: " << table[i]->key << " (#" << hashCode(table[i]->key) << ")" << endl;
      }
      else
      {
        //cout << "[" << i << "] -> Empty" << endl;
      }
    }
  }