// Ivan Rodriguez
// CSCI 2270 Final Project

#include "LinkedList.hpp"
#include "BST.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <chrono> 
#include <vector>

using namespace std;
using namespace std::chrono; 

vector<int> insertArray(vector<int> data, string filename)
{
    string temp;

    ifstream iFile;
    iFile.open(filename);

     string line;
    while (getline(iFile, line))
    {
        istringstream iss(line);
        while(getline(iss, temp, ','))
        {
            data.push_back(stoi(temp));
        }
    }

    return data;
}

void printArray(vector<int> data, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        cout << data[i] << ", ";
    }
    cout << endl;
}

int main()
{
    /*
        *****************************************************************************************Establishing arrays of both data sets using file I/O*****************************************************************************************
    */
    vector<int> dataA, dataB, randIndex;
    dataA = insertArray(dataA, "dataSetA.csv");
    dataB = insertArray(dataB, "dataSetB.csv");
    vector<double> insertTime;
    vector<double> searchTime;
    bool flag = false;
    int startIndex = 0, endIndex = 99;
    /*printArray(dataA, 0, 100);
    cout << endl;
    printArray(dataB, 0, 100);*/

    //*****************************************************************************************Linked List Implementation*****************************************************************************************

    LinkedList dataALL, dataBLL;

    // LL Insertion
    while (!flag)
    {
        if (endIndex == 40000 - 1)
        {
            flag = true;
        }

        auto start = high_resolution_clock::now();
        for (int i = startIndex; i < endIndex; i++)
        {
            dataALL.insertLL(dataA, i); //change data between set A and B
        }
        
        
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        insertTime.push_back(duration.count()/100.0);
        startIndex += 100;
        endIndex += 100;
    }

    //dataALL.displayLL();
    //cout << insertTime.size() << endl;
    /*for (int i = 0; i < insertTime.size(); i++)
    {
        cout << insertTime[i] << " ";
    }*/

    startIndex = 0; endIndex = 100; flag = false;
    //dataALL.searchLL(dataA[150]);

    // LL Search
    while (!flag)
    {
        if (endIndex == 40000)
        {
            flag = true;
        }

        randIndex.clear();
        for (int i = 0; i < 100; i++)
        {
            randIndex.push_back(rand() % endIndex);
        }

        auto start = high_resolution_clock::now();
        for (int i = 0; i < 100; i++)
        {
            dataALL.searchLL(dataA[randIndex[i]]); // change to dataset B
        }

        
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        searchTime.push_back(duration.count()/100.0);
        endIndex += 100;

    }
    //cout << searchTime.size() << endl;
    /*for (int i = 0; i < searchTime.size(); i++)
    {
        cout << searchTime[i] << " ";
    }*/

    // Output times to csv files
    ofstream oFile;
    oFile.open("insertTimesLL_A.csv"); // change titles between data sets
    for (int i = 0; i < insertTime.size(); i++)
    {
        oFile << insertTime[i] << endl;
    }
    oFile.close();

    oFile.open("searchTimesLL_A.csv"); // change titles between data sets
    for (int i = 0; i < searchTime.size(); i++)
    {
        oFile << searchTime[i] << endl;
    }
    oFile.close();
    insertTime.clear();
    searchTime.clear();

    return 0;
}