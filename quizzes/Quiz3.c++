/*
CS371p: Quiz #3 (7 pts)
*/

/* -----------------------------------------------------------------------
 1. List any TWO pieces of advice from "Advice for Computer Science
    College Students".
    (2 pts)

write
learn C
learn microeconomics
excel in non-CS classes
take programming-intensive classes
stop worrying about jobs going to India
get a good summer internship
*/

/* -----------------------------------------------------------------------
 2. What is the output of the following?
    In the context of Collatz, what is f() computing?
    (4 pts)

5
11

For odd n it's computing (3n + 1) / 2.
(3n + 1) / 2
3n/2 + 1/2
n + n/2 + 1/2
n + n/2 + 1, because n is odd
n + (n >> 1) + 1
*/

#include <iostream> // cout, endl

using namespace std;

int f (int n) {
    return n + (n >> 1) + 1;}

int main () {
    cout << f(3) << endl;
    cout << f(7) << endl;
    return 0;}
