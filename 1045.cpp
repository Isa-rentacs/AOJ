#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main(void){
  int n;
  while(cin >> n && n){
    int a[n],sum,ret = 1<<29;
    for(int i=0;i<n;i++) cin >> a[i];
    sum = accumulate(a,a+n,0);
    for(int i=1;i<(1<<n)-1;i++){
      int tmp=0;
      for(int j=0;j<n;j++){
	if(i&(1<<j)) tmp+=a[j];
      }
      ret = min(ret, abs(tmp - (sum-tmp)));
    }
    cout << ret << endl;
  }
}
