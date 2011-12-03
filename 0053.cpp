#include <iostream>
#include <algorithm>

using namespace std;

int p[10000];
bool isPrime[1000000];

int main(void){
  int pnum=0;
  //篩
  fill(isPrime,isPrime+1000000,true);
  for(int i=2;pnum<10000;i++){
     if(isPrime[i] == true){
      p[pnum++] = i;
      for(int j=2;i*j<1000000;j++){
	isPrime[i*j] = false;
      }
    }
  }

  int tmp;
  while(cin >> tmp){
    int ret=0;
    if(!tmp) break;
    for(int i=0;i<tmp;i++) ret+=p[i];
    cout << ret << endl;
  }
}
