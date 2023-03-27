/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();
void test_sum_big_data_set();

void test_count_small_data_set();
void test_count_big_data_set();

void test_median();
void test_mode();
void test_min();
void test_max();
void test_std_dev();
void test_percentile();
void test_summarize();

int main() {
  
  test_sum_small_data_set();
  test_sum_big_data_set();
  test_count_small_data_set();
  test_count_big_data_set();
  test_median();
  test_mode();
  test_min();
  test_max();
  test_std_dev();
  test_percentile();
  test_summarize();

  return 0;
}

void test_summarize(){
  cout << "test_summarize1" << endl;
  vector<double> data23 = {3, 5, 2, 1, 5, 5, 2, 10, 13, 2, 10};
  
  vector<pair<double, int>> newVect = summarize(data23);
  
  cout << "actual: ";
  for (int i = 0; i < newVect.size(); i++)
  {
    cout << newVect[i].first << ": ";
    cout << newVect[i].second << " " << endl;
  }

  cout << "expected: " << endl;
  cout << "{{1, 1}, {2, 3}, {3, 1}, {5, 3}, {10, 2}, {13, 1}";

  cout << "test_summarize2" << endl;
  vector<double> data24 = {6, 12, 12, 4, 8, 4, 9, 10, 432.3, 0.4, 9, 0.4};
  vector<pair<double, int>> newVect2 = summarize(data24);
  
  cout << "actual: ";
  for (int i = 0; i < newVect2.size(); i++)
  {
    cout << newVect2[i].first << ": ";
    cout << newVect2[i].second << " " << endl;
  }

  cout << "expected: " << endl;
  cout << "{0.4, 2}, {4, 2}, {6, 1}, {8, 1}, {9, 2}, {10, 1}, {12, 2}, {432.3, 1}}";


  cout << "test_summarize3" << endl;
  vector<double> data25 = {6};
  vector<pair<double, int>> newVect3 = summarize(data25);
  cout << "actual: ";
  for (int i = 0; i < newVect3.size(); i++)
  {
    cout << newVect3[i].first << ": ";
    cout << newVect3[i].second << " " << endl;
  }

  cout << "expected: " << endl;
  cout << "{{6, 1}}";
  
}


void test_sum_small_data_set() {
  cout << "test_sum_big_data_set" << endl;

  vector<double> data1 = {1, 2, 3};
  assert(sum(data1) == 6);

  cout << "PASS!" << endl;
}

void test_sum_big_data_set() {
  cout << "test_sum_big_data_set" << endl;

  vector<double> data2 = {1.2, 2.4, 3.12, 5, 4, 6, 7, 8, 13, 45, 74};
  assert(sum(data2) == 168.72);

  cout << "PASS!" << endl;
}

void test_count_small_data_set() {
  cout << "test_count_small_data_set" << endl;

  vector<double> data3;
  data3.push_back(1);
  data3.push_back(2.3);
  data3.push_back(3);

  assert(count(data3) == 3);

  cout << "PASS!" << endl;
}

void test_count_big_data_set() {
  cout << "test_count_big_data_set" << endl;

  vector<double> data4 = {1, 2.3, 3.67, 5, 4, 6, 7, 8.1, 13, 45, 74};
  assert(count(data4) == 11);

  cout << "PASS!" << endl;
}

void test_median(){
  cout << "test_median_even" << endl;
  vector<double> data5 = {2.3, 1, 13, 5, 7, 6, 4, 8.1, 3.67, 45, 74, 75};
  assert(median(data5) == 6.5);
  cout << "PASS!" << endl;


  cout << "test_median_odd" << endl;
  vector<double> data6 = {1, 45, 3.67, 8.1, 7, 6, 5, 4, 13, 2.3, 74};
  assert(median(data6) == 6);
  cout << "PASS!" << endl;


  cout << "test_median_one" << endl;
  vector<double> data7 = {3.2};
  assert(median(data7) == 3.2);
  cout << "PASS!" << endl;

}

void test_mode(){
  cout << "test_mode_reg" << endl;
  vector<double> data8 = {1, 45, 3.67, 8.1, 7, 3.67, 5, 4, 13, 2.3, 74};
  assert(mode(data8) == 3.67);
  cout << "PASS!" << endl;

  cout << "test_mode_special" << endl;
  vector<double> data9 = {1, 45, 3.67, 8.1, 7, 3.67, 5, 4, 13, 2.3, 7};
  assert(mode(data9) == 3.67);
  cout << "PASS!" << endl;

  cout << "test_mode_special2" << endl;
  vector<double> data10 = {1, 45, 1, 3.67, 8.1, 7, 3.67, 5, 4, 13, 2.3, 7};
  assert(mode(data10) == 1);
  cout << "PASS!" << endl;

  cout << "test_mode_special3" << endl;
  vector<double> data11 = {1, 45, 11, 3.67, 8.1, 7, 3.62, 5, 4, 13, 2.3, 99};
  assert(mode(data11) == 1);
  cout << "PASS!" << endl;
}

void test_min(){
  cout << "test_min_reg" << endl;
  vector<double> data12 = {1, 45, 3.67, 8.1, 7, 3.67, 5, 4, 13, 2.3, 74};
  assert(min(data12) == 1);
  cout << "PASS!" << endl;

  cout << "test_min_small" << endl;
  vector<double> data13 = {5};
  assert(min(data13) == 5);
  cout << "PASS!" << endl;

  cout << "test_min_unordered" << endl;
  vector<double> data14 = {4, 2, 8, 11, 13.2, 4, 6, 6, 6};
  assert(min(data14) == 5);
  cout << "PASS!" << endl;
}

void test_max(){
  cout << "test_max_reg" << endl;
  vector<double> data15 = {1, 45, 3.67, 8.1, 7, 3.67, 5, 4, 13, 2.3, 74, 6};
  assert(max(data15) == 74);
  cout << "PASS!" << endl;

  cout << "test_max_small" << endl;
  vector<double> data16 = {5};
  assert(max(data16) == 5);
  cout << "PASS!" << endl;

  cout << "test_max2" << endl;
  vector<double> data17 = {4, 2, 8, 11, 13.2, 4, 6, 6, 6};
  assert(max(data17) == 13.2);
  cout << "PASS!" << endl;
}

void test_std_dev(){
  cout << "test_std_dev1" << endl;
  vector<double> data18 = {10, 7, 6, 9, 8};
  assert(stdev(data18) == 1.58114);
  cout << "PASS!" << endl;

  cout << "test_std_dev2" << endl;
  vector<double> data19 = {5, 7};
  assert(stdev(data19) == 1.41421);
  cout << "PASS!" << endl;

  cout << "test_std_dev3" << endl;
  vector<double> data20 = {4.3, 12.3, 7, 9, 12, 9, 10.1, 3.214, 14};
  assert(stdev(data20) == 3.63433);
  cout << "PASS!" << endl;

}

void test_percentile(){
  cout << "test_percentile_0th" << endl;
  vector<double> data21 = {10, 7, 6, 9, 8, 11, 3, 6, 7, 8, 2};
  assert(percentile(data21, 0) == 2);
  cout << "PASS!" << endl;

  cout << "test_percentile_25th" << endl;
  assert(percentile(data21, .25) == 6);
  cout << "PASS!" << endl;

  cout << "test_percentile_50th" << endl;
  assert(percentile(data21, .5) == 7);
  cout << "PASS!" << endl;

  cout << "test_percentile_75th" << endl;
  assert(percentile(data21, .75) == 8.5);
  cout << "PASS!" << endl;

  cout << "test_percentile_100th" << endl;
  assert(percentile(data21, 1) == 11);
  cout << "PASS!" << endl;


  cout << "test2_percentile_0th" << endl;
  vector<double> data22 = {2.3, 5, 1, 90, 8, 2, 3.42, 3, 9};
  assert(percentile(data22, 0) == 1);
  cout << "PASS!" << endl;

  cout << "test_percentile_25th" << endl;
  assert(percentile(data22, .25) == 2.3);
  cout << "PASS!" << endl;

  cout << "test_percentile_50th" << endl;
  assert(percentile(data22, .5) == 3.42);
  cout << "PASS!" << endl;

  cout << "test_percentile_75th" << endl;
  assert(percentile(data22, .75) == 8);
  cout << "PASS!" << endl;

  cout << "test_percentile_100th" << endl;
  assert(percentile(data22, 1) == 90);
  cout << "PASS!" << endl;
}

