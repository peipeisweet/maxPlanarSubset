//File name : maxPlanarSubset.cpp
//Student ID : b11901072

#include "maxPlanarSubset.h"
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int MPS::mps(int start, int end) {
    _dp.assign(_num_point, vector<int>(_num_point, 0));
    
    // Fill DP table for increasing lengths
    for (int len = 1; len < _num_point; len++) {
        for (int i = 0; i + len < _num_point; i++) {
            int j = i + len;
            
            // Default: don't use position j
            _dp[i][j] = (len == 1) ? 0 : _dp[i][j-1];
            
            // Check if we can use chord ending at j
            int k = _chord_tab[j];
            if (k >= i && k < j) {
                if (k == i) {
                    // Direct connection
                    int temp = (i + 1 < j) ? _dp[i+1][j-1] : 0;
                    _dp[i][j] = max(_dp[i][j], 1 + temp);
                } else {
                    // Connection through k
                    int temp = 1;
                    if (k > i) temp += _dp[i][k-1];
                    if (k + 1 < j) temp += _dp[k+1][j-1];
                    _dp[i][j] = max(_dp[i][j], temp);
                }
            }
        }
    }
    
    return _dp[start][end];
}

void MPS::find_solution(int i, int j) {
    if (j <= i) return;
    
    int k = _chord_tab[j];
    if (k < i || k > j) {
        find_solution(i, j-1);
        return;
    }
    
    if (k == i) {
        _result.emplace_back(i, j);
        find_solution(i+1, j-1);
        return;
    }
    
    // Compare using chord (k,j) vs not using it
    int score_with_k = 1;
    if (k > i) score_with_k += _dp[i][k-1];
    if (k + 1 < j) score_with_k += _dp[k+1][j-1];
    
    if (score_with_k > _dp[i][j-1]) {
        _result.emplace_back(k, j);
        find_solution(i, k-1);
        find_solution(k+1, j-1);
    } else {
        find_solution(i, j-1);
    }
}

void MPS::mps_k(int i, int j) {
    _result.clear();
    find_solution(i, j);
}

bool MPS::loadfile(const char*& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: failed to open file " << filename << endl;
        return false;
    }
    
    if (!(file >> _num_point)) {
        cerr << "Error: failed to read number of points" << endl;
        return false;
    }
    
    _num = _num_point / 2;
    _chord_tab.assign(_num_point, -1);
    
    int i, j;
    while (file >> i >> j) {
        if (i >= 0 && i < _num_point && j >= 0 && j < _num_point) {
            _chord_tab[i] = j;
            _chord_tab[j] = i;
        }
    }
    
    file.close();
    return true;
}

bool MPS::outputfile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: failed to write file " << filename << endl;
        return false;
    }
    
    file << _result.size() << endl;
    
    sort(_result.begin(), _result.end());
    for (const auto& pair : _result) {
        file << pair.first << " " << pair.second << endl;
    }
    
    file.close();
    return true;
}

int MPS::getpair(const int i, const int j) {
    if (i >= 0 && i < _num_point && j >= 0 && j < _num_point) {
        return _dp[i][j];
    }
    return 0;
}