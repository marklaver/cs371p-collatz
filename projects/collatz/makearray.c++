// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

using namespace std;

// ------------
// collatz_eval
// ------------

void collatz_eval () {

	cout << "{ ";
	for (unsigned int x = 1; x <= 10000; x++) {
		unsigned int n = x;
		int r = 1;
		while (n > 1) {
			if ((n % 2) != 0) {
				n = n + n/2 + 1;
				r += 2;
			}
			else {
				n = n / 2;
				r++;
			}
		}
    if (x > 1)
      cout << ",";
		cout << " " << r;
	}
	cout << "}" << endl;
}

// -------------
// collatz_solve
// -------------

int main () {
    using namespace std;
    collatz_eval();
    return 0;}				
