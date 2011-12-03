#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
  double ax[4],ay[4], bx[4],by[4];

  while(cin >> ax[0] >> ay[0]>> ax[1] >> ay[1] >> bx[0] >> by[0] >> bx[1] >> by[1]){
    bool in = true;
    
    if(ay[1] < by[0] || ay[0] > by[1]){
      in = false;
    }else if(ax[1] < bx[0] || bx[1] < ax[0]){
      in = false;
    }
    if(in){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}
