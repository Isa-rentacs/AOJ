#include <iostream>

using namespace std;

int main(void){
  int a,b,n;

  while(cin >> a >>b >> n){
    int remain = a % b;
    int ret = 0;
    for(int i=0;i<n;i++){
      remain *= 10;
      //cout << remain / b << " ";
      ret += remain / b;
      remain = remain % b;
    }
    cout << ret << endl;
  }
}
