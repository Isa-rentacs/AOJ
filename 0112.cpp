#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int n;

  while(cin >> n && n){
    vector<int> time;
    int tmp;
    long long now=0;
    long long ret=0;
    for(int i=0;i<n;i++){
      cin >> tmp;
      time.push_back(tmp);
    }
    sort(time.begin(), time.end());
    for(int i=0;i<n;i++){
      ret += now;
      now += time[i];
    }
    cout << ret << endl;
  }
}
