// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// -----------
// TestCollatz
// -----------

// ----
// read
// ----

/**
 * Should read two numbers in and store them correctly.
 */
TEST(Collatz, read) {
    string s("1 10\n");
    const pair<int, int> p = collatz_read(s);
    ASSERT_EQ( 1, p.first);
    ASSERT_EQ(10, p.second);}

/**
 * If the numbers are reversed, that's ok for now.
 */
TEST(Collatz, read_2) {
    string s("11 10\n");
    const pair<int, int> p = collatz_read(s);
    ASSERT_EQ(11, p.first);
    ASSERT_EQ(10, p.second);}
				
// ----
// eval
// ----

/**
 * Test known values 1 10 20
 */
TEST(Collatz, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

/**
 * Test known values 100 200 125
 */
TEST(Collatz, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

/**
 * Test known values 201 210 89
 */
TEST(Collatz, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

/**
 * Test known values 900 1000 174
 */
TEST(Collatz, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

/**
 * Find correct value for n = 1.
 */
TEST(Collatz, eval_5) {
    const int v = collatz_eval(1, 1);
    ASSERT_EQ(1, v);}
/**
 * Two of the same number shouldn't cause a problem
 */		
TEST(Collatz, eval_10_10) {
    const int v = collatz_eval(10, 10);
    ASSERT_EQ(7, v);}		

/**
 * Increments of each other should not cause a problem.
 */
TEST(Collatz, eval_9_10) {
	const int v = collatz_eval(9, 10);
	ASSERT_EQ(20, v);}

/**
 * Test much higher known value: 11630 57433 340.
 */
TEST(Collatz, eval_high) {
    const int v = collatz_eval(11630, 57433);
    ASSERT_EQ(340, v);}		

/**
 * If the numbers are reversed, still return the correct answer
 */
TEST(Collatz, eval_reverse) {
	const int v = collatz_eval(10, 1);
	ASSERT_EQ(20, v);}		
	
		
// -----
// print
// -----

/**
 * Check for accurate printing
 */
TEST(Collatz, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

/**
 * Check for acceptability of multiple lines of code
 */
TEST(Collatz, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

/**
 * Test multiple edge cases
 */
TEST(Collatz, solve_2) {
    istringstream r("10 1\n7 7\n10000 10000\n79901 13866\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("10 1 20\n7 7 17\n10000 10000 30\n79901 13866 351\n", w.str());}
/*
% ls -al /usr/include/gtest/
...
gtest.h
...



% locate libgtest.a
/usr/lib/libgtest.a
...



% locate libpthread.a
...
/usr/lib32/libpthread.a



% locate libgtest_main.a
/usr/lib/libgtest_main.a
...



% g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -lpthread



% valgrind TestCollatz        >  TestCollatz.out 2>&1
% gcov-4.7 -b Collatz.c++     >> TestCollatz.out
% gcov-4.7 -b TestCollatz.c++ >> TestCollatz.out



% cat TestCollatz.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestCollatz
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from Collatz
[ RUN      ] Collatz.read
[       OK ] Collatz.read (31 ms)
[ RUN      ] Collatz.eval_1
[       OK ] Collatz.eval_1 (5 ms)
[ RUN      ] Collatz.eval_2
[       OK ] Collatz.eval_2 (3 ms)
[ RUN      ] Collatz.eval_3
[       OK ] Collatz.eval_3 (3 ms)
[ RUN      ] Collatz.eval_4
[       OK ] Collatz.eval_4 (3 ms)
[ RUN      ] Collatz.print
[       OK ] Collatz.print (17 ms)
[ RUN      ] Collatz.solve
[       OK ] Collatz.solve (10 ms)
[----------] 7 tests from Collatz (88 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[  PASSED  ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225==     in use at exit: 0 bytes in 0 blocks
==14225==   total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'Collatz.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'Collatz.c++.gcov'
...
File 'TestCollatz.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestCollatz.c++.gcov'
...
*/
