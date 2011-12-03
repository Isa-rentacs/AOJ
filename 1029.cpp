#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
  int n,m;

  while(cin >> n >> m){
    if((n|m) == 0) break;
    int l[n],r[m],a[n+m+1],ret,s=0,t=0;
    for(int i=0;i<n;i++) cin >> l[i];
    for(int i=0;i<m;i++) cin >> r[i];
    for(int i=0;i<n+m;i++){
      if(s == n){
	a[i] = r[t++];
      }else if(t == m){
	a[i] = l[s++];
      }else{
	if(l[s] > r[t]){
	  a[i] = r[t++];
	}else{
	  a[i] = l[s++];
	}
      }
    }
    ret = a[0];
    for(int i=1;i<n+m;i++){
      ret = max(ret, a[i]-a[i-1]);
    }
    cout << ret << endl;
  }
}
