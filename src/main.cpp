#include "maxPlanarSubset.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
        return 0;
    }

    // Open input and output files
    std::ifstream inFile(argv[1]);
    std::ofstream outFile(argv[2]);

    // Process each test case
    int vertices;
    while (inFile >> vertices && vertices != 0) {
        int n = vertices / 2;  // number of chords
        MaxPlanarSubset mps(n);

        // Read chords
        for (int i = 0; i < n; i++) {
            int start, end;
            inFile >> start >> end;
            mps.addChord(start, end);
        }

        // Solve and get result
        int maxChords = mps.solve(0, vertices-1);
        std::vector<Chord> solution = mps.getSolution();

        // Sort solution by first endpoint
        std::sort(solution.begin(), solution.end(), 
                 [](const Chord& a, const Chord& b) { return a.start < b.start; });

        // Output results
        outFile << maxChords << std::endl;
        for (const Chord& chord : solution) {
            outFile << chord.start << " " << chord.end << std::endl;
        }
    }

    inFile.close();
    outFile.close();
    return 0;
}