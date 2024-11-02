//File name : maxPlanarSubset.h
//Student ID : b11901072

#ifndef MPS_MGR_H
#define MPS_MGR_H

#include <vector>
#include <string>

class MPS {
public:
    MPS() : _num(1), _num_point(0) {}
    ~MPS() {}
    
    bool loadfile(const char*&);
    bool outputfile(const std::string&);
    int getnumber() { return _num; }
    int getpair(const int i, const int j);
    int mps(int, int);
    void mps_k(int, int);
    
private:
    int _num;
    int _num_point;
    std::vector<int> _chord_tab;
    std::vector<std::vector<int>> _dp;
    std::vector<std::pair<int,int>> _result;
    void find_solution(int i, int j);
};

#endif // MPS_MGR_H