#include <iostream>

using namespace std;

int main(void){
  int n,k;

  cin >> n >> k;
  while(k--){
    int x,y;
    cin >> y >> x;
    y -= 1; x -= 1;
    if(y > n/2) y = n - y - 1;
    if(x > n/2) x = n - x - 1;
    if(y > x) swap(x,y);
    if(y%3 == 0){
      cout << 1 << endl;
    }else if(y%3==1){
      cout << 2 << endl;
    }else{
      cout << 3 << endl;
    }
  }
}
