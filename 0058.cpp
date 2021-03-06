#include <iostream>
#include <cmath>

using namespace std;

int main(void){
  double ax,ay,bx,by,cx,cy,dx,dy;

  while(cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy){
    if(ax == bx){
      if(cy == dy){
	cout << "YES" << endl;
      }else{
	cout << "NO" << endl;
      }
    }else if(cx == dx){
      if(ay == by){
	cout << "YES" << endl;
      }else{
	cout << "NO" << endl;
      }
    }else{
      double arg1, arg2;
      arg1 = (by - ay) / (bx - ax);
      arg2 = (dy - cy) / (dx - cx);
      if(fabs(arg1*arg2 + 1) < 1e-6){
	cout << "YES" << endl;
      }else{
	cout << "NO" << endl;
      }
    }
  }
}
