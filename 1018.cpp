#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
  int n;
  while(cin >> n){
    int t[n];
    long long ret=0;
    for(int i=0;i<n;i++)cin >> t[i];
    sort(t,t+n);
    for(int i=0;i<n;i++) ret += t[i]*(n-i);
    cout << ret << endl;
  }
}
