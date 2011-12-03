#include <iostream>
using namespace std;
main(){
  int x,y;
  while(cin >> x >> y){
    if((x|y) == 0) break;
    (x%2&&y%2)?cout<<"no"<<endl:cout<<"yes"<<endl;
  }
}
