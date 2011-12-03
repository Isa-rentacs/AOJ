#include <iostream>
#include <map>
using namespace std;

int main(void){
  int n,t;
  while(cin >> n && n){
    map<int,int> m;
    for(int i=0;i<n;i++){
      cin >> t;
      m[t]++;
    }
    map<int,int>::iterator it = m.begin();
    bool isok = false;
    while(it != m.end()){
      if((*it).second > (double)n/2){
	isok = true;
	cout << (*it).first << endl;
      }
      ++it;
    }
    if(!isok) cout << "NO COLOR" << endl;
  }
}
