#ifndef MAX_PLANAR_SUBSET_H
#define MAX_PLANAR_SUBSET_H

#include <vector>
using namespace std;

// Structure to represent a chord
struct Chord {
    int start, end;
    Chord(int s, int e) : start(s), end(e) {}
};

class MaxPlanarSubset {
private:
    std::vector<Chord> chords;
    std::vector<std::vector<int>> dp;
    std::vector<std::vector<int>> path;
    int n;  // number of chords

    // Helper functions
    bool intersect(const Chord& a, const Chord& b);
    void reconstructSolution(int i, int j, std::vector<Chord>& result);

public:
    // Constructor
    explicit MaxPlanarSubset(int size);

    // Public member functions
    void addChord(int start, int end);
    int solve(int i, int j);
    std::vector<Chord> getSolution();
};

#endif // MAX_PLANAR_SUBSET_H