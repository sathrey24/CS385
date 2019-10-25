/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Sanjay Athrey  
 * Date        : 9/29/19
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector< vector<int> > get_ways(int num_stairs) {
    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.
    // based on stairclimber.py algorithm
    vector <vector <int>> ways;
	if (num_stairs <= 0) {
		ways.push_back(vector<int>());
		return ways;
    }
	else{
		for(int i=1; i<=3; i++){
			if(num_stairs >= i){
                vector <vector <int>> result;
				result = get_ways(num_stairs - i);
				for(auto &r : result){
					r.push_back(i);
                    ways.push_back(r);
                }                
			}
		}
	}
    return ways;
}

int size (int i){
    int size = 1;
    while(i > 10){
        i = i/10;
        size ++;
    }
    return size;

}

void display_ways(const vector< vector<int> > &ways) {
    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.
    if (ways.size() == 1){
        cout << 1 << " way to climb " << 1 << " stair." << endl;
    }
    if (ways.size() > 1){
        cout << ways.size() << " ways to climb " << ways.at(0).size() << " stairs." << endl;
    }   
	for(unsigned int i=0; i<=ways.size(); i++){
		cout << setw(size(ways.size())) << i+1 << ". " << "[";
		for(unsigned int k = ways[i].size() - 1; k >= 1; k--){
			cout << ways[i][k] << ", ";
		}
		cout << ways[i][0] << "]" << endl;
	}

}

int main(int argc, char * const argv[]) {
	if(argc != 2){
		cout << "Usage: ./stairclimber <number of stairs>";
		return 1;
	}
	int num_stairs;
    istringstream iss(argv[1]);
    if (!(iss >> num_stairs) || num_stairs < 1){
        cout << "Error: Number of stairs must be a positive integer." << endl;
        return 1;
    }
	else {
		vector<vector<int>> ways = get_ways(num_stairs);
		display_ways(ways);
		return 0;
		}
	}


   