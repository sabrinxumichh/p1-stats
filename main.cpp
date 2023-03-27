//'Project UID 5366c7e2b77742d5b2142097e51561a5'
#include <iostream>
#include <vector>
#include "p1_library.h"
#include "stats.h"
using namespace std;

int main() {

  cout << "enter a filename" << endl;
  string fileName;
  cin >> fileName;

  cout << "enter a column name" << endl;
  string column;
  cin >> column;

  cout << "reading column " << column << " from " << fileName << endl;
  vector<double> v = extract_column(fileName, column);

  cout << "Summary (value: frequency)" << endl;
  vector<pair<double, int>> v2 = summarize(v);
  for(size_t i = 0; i < v2.size(); i++){
    cout << v2[i].first << ": " << v2[i].second << endl;
  }

  cout << "count = " << count(v) << endl;
  cout << "sum = " << sum(v) << endl;
  cout << "mean = " << mean(v) << endl;
  cout << "stdev = " << stdev(v) << endl;
  cout << "median = " << median(v) << endl;
  cout << "mode = " << mode(v) << endl;
  cout << "min = " << min(v) << endl;
  cout << "max = " << max(v) << endl;
  cout << "  0th percentile = " << percentile(v, 0) << endl;
  cout << " 25th percentile = " << percentile(v, .25) << endl;
  cout << " 50th percentile = " << percentile(v, .50) << endl;
  cout << " 75th percentile = " << percentile(v, .75) << endl;
  cout << "100th percentile = " << percentile(v, 1) << endl;

}
