#include <iostream>
#include <string>

using namespace std;

int main(void){
  int n,l,pos,cnt,ret;
  string str;
  while(cin >> n && n){
    pos=0;
    cnt=0;
    ret=0;

    cin >> l;
    cin >> str;
    while(pos < l-2){
      if(str[pos] == 'O'){
	pos++;
      }else{
	if(str[pos+1] == 'O' && str[pos+2] == 'I'){
	  pos += 2;
	  cnt++;
	}else{
	  if(cnt > 0){
	    if(cnt >= n){
	      ret += cnt-n+1;
	    }
	  }
	  cnt = 0;
	  pos++;
	}
      }
    }
    if(cnt > 0){
      if(cnt >= n){
	ret += cnt-n+1;
      }
    }
    cout << ret << endl;
  }
}
