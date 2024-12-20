#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
using namespace std;

int main() {
    ifstream infile ("input.txt");
    list<int> list1, list2;
    int x;

    // Read input file and put into linked lists
    while(!infile.eof()) {
        infile >> x;
        list1.push_front(x);
        
        infile >> x;
        list2.push_front(x);
    }

    // Check that sizes match
    if(list1.size() != list2.size()) {
        cout << "Lists dont have the same size!";
        return 1;
    }

    // Sort lists
    list1.sort();
    list2.sort();

    // Accumulate the absolute difference of distance pairs
    int listSize = list1.size();
    int distAcc = 0;
    for(int i = 0; i < listSize; i++) {
        distAcc += abs(list1.back() - list2.back());
        list1.pop_back();
        list2.pop_back();
    }

    // Print result
    cout << distAcc;
    return 0;
}