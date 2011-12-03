#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int d;
 
  while(cin >> d && d){
    int n,m,k,tmp,ret=0;
    vector<int> stores;
    stores.push_back(d);
    stores.push_back(0);

    cin >> n >> m;
    for(int i=0;i<n-1;i++){
      cin >> tmp;
      stores.push_back(tmp);
    }

    sort(stores.begin(), stores.end());
    vector<int>::iterator it,jt;  
    for(int i=0;i<m;i++){
      cin >> k;
      if(k==0) continue;
      it = lower_bound(stores.begin(),stores.end(),k);
      jt = it;
      jt--;
      ret += min(k - (*jt), (*it) - k);
    }
    cout << ret << endl;
  }
}
