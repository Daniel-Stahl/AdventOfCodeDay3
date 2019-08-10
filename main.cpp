#include <fstream>
#include <string.h>
#include <vector>
#include <cstring>
#include <iostream>
#include <utility>

using namespace std;

int main() {
    ifstream inFile;
    char trash;
    int id;
    pair<int, int> coord;
    pair<int, int> box;
    vector<int> row(1000);
    vector<vector<int>> col(1000, row);
    int count;
    
    inFile.open("/Users/stahl/Desktop/Guardians/AdventOfCodeDay3/AdventOfCodeDay3/data.txt");
    
    if (!inFile) {
        cout << "No file exists" << endl;
    } else {
        cout << "File is good!" << endl;
    }
    
    while (!inFile.eof()) {
        inFile >> trash >> id >> trash >> coord.first >> trash >> coord.second >> trash >> box.first >> trash >> box.second;
        
        for (int i = 0; i < box.first; i++) {
            for (int k = 0; k < box.second; k++) {
                col.at(coord.first + i).at(coord.second + k)++;
            }
        }
//        cout << "Coords: " << coord.first << ", " << coord.second << endl;
//        cout << "Box: " << box.first << ", " << box.second << endl;
    }
    
    for (int i = 0; i < col.size(); i++) {
        for (int k = 0; k < col.size(); k++) {
            if (col.at(i).at(k) > 1) {
                count++;
            }
        }
    }

    cout << "Count is: " << count << endl;
    
    inFile.close();
    
    inFile.open("/Users/stahl/Desktop/Guardians/AdventOfCodeDay3/AdventOfCodeDay3/data.txt");
    
    while (!inFile.eof()) {
        bool success = true;
        inFile >> trash >> id >> trash >> coord.first >> trash >> coord.second >> trash >> box.first >> trash >> box.second;
        
        for (int i = 0; i < box.first; i++) {
            for (int k = 0; k < box.second; k++) {
                if (col.at(coord.first + i).at(coord.second + k) != 1) {
                    success = false;
                }
            }
        }
        
        if (success == true) {
            cout << "ID: " << id << endl;
        }
        
    }
}


//    char testData[] = "#10 @ 529,203: 10x21";
//    char searchData[] = "#10@,:x";
//    char* stringPos = nullptr;
//
//    stringPos = strpbrk(testData, searchData);
//
//    if (stringPos != nullptr) {
//        cout << "Found" << endl;
//        *stringPos = ' ';
//        cout << testData << endl;
//    } else {
//        cout << "No such thing exists" << endl;
//    }
