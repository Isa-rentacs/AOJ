#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
  int my1,my2,op;
  bool isused[11];

  while(cin >> my1 >> my2 >> op){
    int candidate = 0;
    fill(isused, isused+11, false);
    isused[my1] = true;
    isused[my2] = true;
    isused[op]  = true;
    if(my1+my2<=10){
      cout << "YES" << endl;
    }else{
      for(int i=1;i<=10;i++){
	if(isused[i] == false && my1+my2+i <= 20){
	  candidate++;
	}
      }
      if((double)candidate / 7 > 0.5){
	cout << "YES" << endl;
      }else{
	cout << "NO" << endl;
      }
    }
  }
}
