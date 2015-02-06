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

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
		
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
	int max = 1;
	// If the numbers are reversed, fix them.
	if (j < i) {
		int temp = i;
		i = j;
		j = temp;
	}
	for (i; i <= j; i++) {
		int n = i;
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
		if (r > max)
			max = r;
	}
	return max;
}
		//		n = n + n/2 + 1;
		//		r += 2;

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
