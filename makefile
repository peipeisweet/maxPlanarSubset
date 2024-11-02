PP = g++

main : ./src/main.cpp ./src/maxPlanarSubset.cpp
	$(PP) -std=c++11 -O3 ./src/main.cpp ./src/maxPlanarSubset.cpp -o ./bin/mps

clean : 
	rm ./bin/mps