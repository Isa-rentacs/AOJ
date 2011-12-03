#include <iostream>
#include <algorithm>

using namespace std;

bool isPrime[60000];

int main(void){
  fill(isPrime, isPrime+60000, true);
  for(int i=2;i<60000;i++){
    if(isPrime[i]){
      for(int j=2; i*j<60000;j++){
	isPrime[i*j] = false;
      }
    }
  }

  int n;
  while(cin >> n){
    int tmp=1;
    int mini=0, maxi = 0;
    while(1){
      if(mini == 0 && isPrime[n-tmp] == true) mini = n-tmp;
      if(maxi == 0 && isPrime[n+tmp] == true) maxi = n+tmp;
      if(mini != 0 && maxi != 0) break;
      tmp++;
    }
    cout << mini << " " << maxi << endl;
  }
  return 0;
}
