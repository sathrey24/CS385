/*******************************************************************************
 * Name    : gcd.cpp
 * Author  : Sanjay Athrey
 * Version : 1.0
 * Date    : August 29, 2019
 * Description : Computes the GCD of two command-line arguments.
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <sstream>

using namespace std;

int gcd_recursive(int m, int n){
    m = abs(m);
    n = abs(n);

    if (m == 0){
        return n;
    }
    if (n == 0){
        return m;
    }
    else{
        return gcd_recursive(n, m % n);
    }
}

int gcd_iterative (int m, int n){
    m = abs(m);
	n = abs(n);
	
	if ( n == 0){
	    return m;
	}	
	if (m == 0){
	    return n;
	}
    if (m == n){
        return m;
    }
	else while ((m!=n) && (n!=0)){
        int m1 = m % n;
	    m = n;
	    n = m1;
	} 	
	return m;
}

int main(int argc, char* const argv[]) {
  int m, n;
  istringstream iss;
  if (argc != 3) {
    cerr << "Usage: " << argv[0] << " <integer m> <integer n>"
        << endl;
    return 1;
  }
  iss.str(argv[1]);
  if ( !(iss >> m) ) {
    cerr << "Error: The first argument is not a valid integer."
        << endl;
    return 1;
  }
  iss.clear(); // clear the error code
  iss.str(argv[2]);
  if ( !(iss >> n) ) {
    cerr << "Error: The second argument is not a valid integer."
        << endl;
    return 1;
  }
  cout << "Iterative: gcd(" << m << ", " << n << ") = " << gcd_iterative(m, n) << endl;
  cout << "Recursive: gcd(" << m << ", " << n << ") = " << gcd_recursive(m, n) << endl;
}


