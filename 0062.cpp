#include <iostream>
using namespace std;
int main(void){
  char tmp[10];
  char buf;
  while(cin >> buf){
    tmp[0] = buf - '0';
    for(int i=1;i<10;i++){
      cin >> buf;
      tmp[i] = buf -'0';
    }
    for(int i=8;i>=0;i--){
      for(int j=0;j<=i;j++){
	tmp[j] = (tmp[j] + tmp[j+1]) % 10;
      }
    }
    cout << (int)tmp[0] << endl;
  }
}
