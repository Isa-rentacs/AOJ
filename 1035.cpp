#include <iostream>
#include <cstring>
using namespace std;

int main(void){
  int w,q;
  while(cin>>w>>q){
    if((w|q) == 0) break;
    char c;
    int s,t;
    int state[w],width,index;
    bool sleepable;
    memset(state,-1,sizeof(state));
    for(int i=0;i<q;i++){
      cin >> c;
      if(c == 's'){
	cin >> s >> t;
	sleepable = false;
	width = 0;
	index = 0;
	for(int j=0;j<w;j++){
	  if(state[j] == -1){
	    if(width == 0) index = j;
	    width++;
	  }else{
	    width = 0;
	  }
	  if(width >= t){
	    sleepable = true;
	    break;
	  }
	}
	if(sleepable){
	  cout << index << endl;
	  for(int j=0;j<t;j++) state[index+j] = s;
	}else{
	  cout << "impossible" << endl;
	}
      }else{
	cin >> s;
	for(int i=0;i<w;i++){
	  if(state[i] == s){
	    state[i] = -1;
	  }
	}
      }
    }
    cout << "END" << endl;
  }
}
