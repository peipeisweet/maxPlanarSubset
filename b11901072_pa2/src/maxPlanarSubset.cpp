#include "maxPlanarSubset.h"
#include <algorithm>
using namespace std;

MaxPlanarSubset::MaxPlanarSubset(int size) : n(size) {
    dp.resize(2*n, std::vector<int>(2*n, -1));
    path.resize(2*n, std::vector<int>(2*n, -1));
}

bool MaxPlanarSubset::intersect(const Chord& a, const Chord& b) {
    return !((a.start < b.start && a.end < b.start) ||
            (a.start > b.end && a.end > b.end) ||
            (a.start > b.start && a.end < b.end) ||
            (a.start < b.start && a.end > b.end));
}

void MaxPlanarSubset::addChord(int start, int end) {
    chords.push_back(Chord(start, end));
}

void MaxPlanarSubset::reconstructSolution(int i, int j, std::vector<Chord>& result) {
    if (i >= j) return;
    
    if (path[i][j] == -1) {
        reconstructSolution(i + 1, j, result);
    } else {
        result.push_back(Chord(i, path[i][j]));
        reconstructSolution(i + 1, path[i][j] - 1, result);
        reconstructSolution(path[i][j] + 1, j, result);
    }
}

int MaxPlanarSubset::solve(int i, int j) {
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    // Don't include chord starting at i
    int val = solve(i + 1, j);
    
    // Try to include chords starting at i
    for (const Chord& chord : chords) {
        if (chord.start == i && chord.end <= j) {
            int current = 1 + solve(i + 1, chord.end - 1) + solve(chord.end + 1, j);
            if (current > val) {
                val = current;
                path[i][j] = chord.end;
            }
        }
    }

    dp[i][j] = val;
    return val;
}

std::vector<Chord> MaxPlanarSubset::getSolution() {
    std::vector<Chord> result;
    reconstructSolution(0, 2*n-1, result);
    return result;
}