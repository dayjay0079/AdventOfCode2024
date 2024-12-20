#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main() {
    ifstream infile ("input.txt");
    map<int, int> occ1, occ2;
    int x;

    // Read input file and count how occurences of each number
    // (im assuming the memory at map indexes is preinitialized to 0)
    while(!infile.eof()) {
        infile >> x;
        occ1[x]++;
        
        infile >> x;
        occ2[x]++;
    }

    int simScore = 0;
    int lim = max(occ1.rbegin()->first, occ2.rbegin()->first);
    for(int i = 0; i < lim; i++) {
        int value = occ1[i] * i * occ2[i];
        simScore += value;
    }

    cout << simScore;

    return 0;
}