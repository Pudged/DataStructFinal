#include "HashQuad.hpp"

using namespace std;

void HashTableQuad::insert(int key)
{
    HashNodeQuad *node = new HashNodeQuad (key);
    int index = hashCode(key);
    int count = 1;

    if (table[index] == 0)
    {
      table[index] = node;
    }

    else
    {
      for (int i = (index + count * count) % size; i != index; i = (i + count * count) % size)
      {
        if (table[i] == 0)
        {
          table[i] = node;
          return;
        }
        else if (table[i]->key != key)
        {
          insertCollisions ++;
          count ++;
        }
      }
      cout << "Can not insert (" << key << ")Table is full" << endl;
      return;
    }
}

void HashTableQuad::search(int searchKey)
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
        count ++;
      }
      if (table[index]->key == searchKey)
      {
        return;
      }
      index = index + count * count;
      index = index % size;
    }
}

int HashTableQuad::hashCode(int k)
{
    return k % size;
}

void HashTableQuad::printHashTable()
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