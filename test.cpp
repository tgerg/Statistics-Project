//Kth Highest
#include <vector>
#include <string>
#include <iostream>
using namespace std;

double kth_highest();

double kth_highest(std::vector<double> v, int k) {
std::sort(v.begin(), v.end());
for(int i = 0; i < k; ++i) {
double value = v.at(v.size()-1);
while (v.at(v.size()-1) == value){
v.pop_back();
}
}
return v.at(v.size()-1);
}

int main(){
cout << kth_highest({1,2,3,4,5},4) << endl;
cout << kth_highest({4,7,56,0,0.5},2) << endl;

return 0;
}
