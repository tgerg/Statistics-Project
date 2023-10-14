#include <iostream>
#include "p1_library.hpp"
#include "stats.hpp"
using std::cout, std::endl, std::cin, std::string, std::vector;

int main() {
  string file;
  string col;
  cout << "enter a filename" << endl;
  cin >> file;
  cout << "enter a column name" << endl;
  cin >> col;
  cout << "reading column " << col << " from " << file << endl;
  vector<double> v = extract_column(file, col);
  sort(v);

  summarize(v);
  cout << endl;
  cout << "count = " << count(v) << endl;
  cout << "sum = " << sum(v) << endl;
  cout << "mean = " << mean(v) << endl;
  cout << "stdev = " << stdev(v) << endl;
  cout << "median = " << median(v) << endl;
  cout << "mode = " << mode(v) << endl;
  cout << "min = " << min(v) << endl;
  cout << "max = " << max(v) << endl;
  percentile(v,0);
  percentile(v,25);
  percentile(v,50);
  percentile(v,75);
  percentile(v,100);
}