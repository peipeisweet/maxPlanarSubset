//File name : main.cpp
//Student ID : b11901072

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include "maxPlanarSubset.h"

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    MPS mps;
    int _n;
    
    if (mps.loadfile(argv[1])) {
        _n = mps.getnumber();
        int mps_val = mps.mps(0, 2 * _n - 1);
        mps.mps_k(0, 2 * _n - 1);
        
        string output_filename = argv[2];
        if (!mps.outputfile(output_filename)) {
            cerr << "Failed to write the output file." << endl;
            return 1;
        }
    } else {
        cerr << "Failed to read the input file." << endl;
        return 1;
    }
    
    return 0;
}