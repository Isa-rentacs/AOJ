#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
  int n;
  int k;
  while(cin >> n >> k){
    if((n|k) == 0) break;

    int d[n][n];

    fill((int *)d, (int *)d+n*n, 65535);
    for(int i=0;i<n;i++) d[i][i] = 0;
    for(int i=0;i<k;i++){
      int p,q;
      cin >> p >> q;
      d[p-1][q-1] = 1;
      d[q-1][p-1] = 1;
    }

    //WF
    for(int r=0;r<n;r++)
      for(int p=0;p<n;p++)
	for(int q=0;q<n;q++){
	  d[p][q] = min(d[p][q], d[p][r]+d[r][q]);
	}
    int ret = 0;
    for(int i=1;i<n;i++){
      if(d[0][i] < 3) ret++;
    }
    cout << ret << endl;
  }
}
