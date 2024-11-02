Problem Statement:
  Given a set of chords in a circle, find the largest subset of chords such that no two chords in the subset intersect.

Build Instructions:
**make sure your are in the ./b11901072_pa2/**
  make

Usage:
  ./bin/mps <input_file> <output_file>

Input format:
  first line is an even integer 2N(the number of points).
  following lines are pairs of integers i and j representing chord endpoints.

Output format:
  first line is the number of non-intersecting chords in the solution.
  following lines are pairs of endpoints for each chord in the solution.
  
File structure:
  b11901072_pa2/
    bin/
      mps
    src/
      main.cpp
      maxPlanarSubset.cpp
      maxPlanarSubset.h
    doc/
      report.pdf
    makefile
    README.md  //this file