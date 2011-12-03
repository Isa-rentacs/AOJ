#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isPrime[1000000];

int main(void){
  vector<int> pvec;
  //篩
  fill(isPrime,isPrime+1000000,true);
  for(int i=2;i<=50000;i++){
    if(isPrime[i] == true){
      pvec.push_back(i);
      for(int j=2;i*j<1000000;j++){
	isPrime[i*j] = false;
      }
    }
  }
  int tmp;
  while(cin >> tmp){
    int ret = 0;
    if(!tmp) break;
    for(int i=0;pvec[i]*2 <= tmp;i++){
      if(binary_search(pvec.begin(), pvec.end(), tmp-pvec[i])) ret++;
    }
    cout << ret << endl;
  }
}
