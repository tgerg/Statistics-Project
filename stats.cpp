#include "stats.hpp"
#include "p1_library.hpp"
#include <cassert>
#include <vector>
#include <cmath>
#include <iostream>

using std::string, std::cout, std::endl, std::pair, std::vector, std::make_pair;

vector<pair<double, int> > summarize(vector<double> v) {
  cout << "Summary (value: frequency)" << endl;
  vector<pair<double,int>> list;
  for (int i = 0; i < v.size(); ++i){
    int val = v[i];
    int freq = 1;
    for (int j = 0; j < v.size(); ++j){
        if ((v[i] == v[j]) && (i != j)){
            ++freq;
        }
    }
    pair<double,int> p = {val, freq};
    bool new_num = true;
    for (auto it : list){
        if (it.first == val){
            new_num = false;
        }
    }
    if (new_num){
        list.push_back(p);
        cout << val << ": " << freq << endl;
    }
  }
  return list;
}

int count(vector<double> v) {
    int c = v.size();
    return c;
}

double sum(vector<double> v) {
  double sum = 0;
  for (int i = 0; i < v.size(); ++i){
    sum += v[i];
  }
  return sum;
}

double mean(vector<double> v) {
    double m = sum(v)/count(v);
    return m;
}

double median(vector<double> v) {
    double med;
    int num = v.size();
    if (num % 2 == 0){
        med = (v[(num/2) - 1] + v[num/2])/2.0;
    }else{
        med = v[num/2];
    }
    return med;
}

double mode(vector<double> v) {
    double mode = v[0];
    double max = 1;
    for (int i = 0; i < v.size(); ++i){
        double count = 1;
        for (int j = 0; j < v.size(); ++j){
        if ((i != j) && (v[i] == v[j])){
            ++count;
        }
        }
        if (count > max){
            max = count;
            mode = v[i];
        }
    }
    return mode;
}

double min(vector<double> v) {
    double min = v[0];
    for (int i = 1; i < v.size(); ++i){
        if (min > v[i]){
            min = v[i];
        }
    }
    return min;
}

double max(vector<double> v) {
    double max = v[0];
    for (int i = 1; i < v.size(); ++i){
        if (max < v[i]){
            max = v[i];
        }
    }
    return max;
}

double stdev(vector<double> v) {
    double N = count(v);
    double m = mean(v);
    double sum = 0;
    for (int i = 0; i < v.size(); ++i){
        sum += pow(v[i] - m, 2);
    }
    double sd = sqrt(sum/(N-1));
    return sd;
}

double percentile(vector<double> v, double p) {
  double pct;
  double num = count(v);
  double rank = ((p/100.0)*(num - 1));
  double k;
  double d = modf(rank, &k);
  if (p == 100){
    pct = v[num-1];
  }else{
    pct = v[k] + d*(v[k+1] - v[k]);
  } 
  if (p < 10){
    cout << "  ";
  }else if (p < 100){
    cout << " ";
  }
  cout << p << "th percentile = " << pct << endl;
  return pct;
}