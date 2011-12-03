#include <iostream>
using namespace std;
main(){
  int n;
  while(cin>>n&&n){
    int ret=0,t;
    for(int i=0;i<n/4;i++){
      cin >> t;
      ret+=t;
    }
    cout << ret << endl;
  }
}
