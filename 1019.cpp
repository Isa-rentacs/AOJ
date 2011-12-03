#include <iostream>

using namespace std;

int main(void){
  int n,k;

  while(cin >> n >> k){
    if((n|k) == 0) break;
    int s[k];
    int b[n][k];
    for(int i=0;i<k;i++) cin >> s[i];
    for(int i=0;i<n;i++){
      for(int j=0;j<k;j++){
	cin >> b[i][j];
      }
    }
    bool isok = true;
    for(int i=0;i<k;i++){
      int tmp=0;
      for(int j=0;j<n;j++){
	tmp += b[j][i];
      }
      if(tmp > s[i]){
	isok = false;
      }
    }
    isok?cout << "Yes" << endl:cout << "No" << endl;
  }
}
