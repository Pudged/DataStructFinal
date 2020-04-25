#include "HashLin.hpp"

using namespace std;

void HashTableLin::insert(int key)
{
    HashNodeLin *node = new HashNodeLin (key);
    int index = hashCode(key, size);

    if (table[index] == 0)
    {
        table[index] = node;
    }

    else if (table[index]->key == key)
    {
        //cout << "Key in use" << endl;
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

            else if (table[i]->key == key)
            {
                //cout << "Key in use" << endl;
                return;
            }
        }

        cout << "Can not insert (" << key << "). Table is full" << endl;
        return;
    }
}

HashNodeLin *HashTableLin::search(int searchKey)
{
  int index = hashCode(searchKey, size);
  if (table[index] == 0)
  {
    return 0;
  }

  else if (table[index]->key == searchKey)
  {
    return table[index];
  }

  else
  {
    for (int i = (index + 1) % size; i != index; i = (i + 1) % size)
    {
        if (table[i] == 0)
        {
          return 0;
        }

        else if (table[i]->key == searchKey)
        {
          return table[i];
        }
    }
    return 0;
  }
}

int HashTableLin::hashCode(int k, int tableSize)
{
    int hash = 0;
    string tempKey = to_string(k);
    for (int i = 0; i < tempKey.length(); i++)
    {
        hash += tempKey[i];
    }

    return hash % tableSize;
}

void HashTableLin::printHashTable()
  {
    for (int i = 0; i < size; i++)
    {
      if (table[i] != 0)
      {
        cout << "[" << i << "] -> Key: " << table[i]->key << " (#" << hashCode(table[i]->key, size) << ")" << endl;
      }
      else
      {
        //cout << "[" << i << "] -> Empty" << endl;
      }
    }
  }