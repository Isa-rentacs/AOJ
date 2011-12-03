#include <iostream>
#include <string>

using namespace std;

int main(void){
  string str;
  int ret = 0;
  while(cin >> str){
    bool isParin = true;
    for(int i=0;i<str.size()/2;i++){
      if(str[i] != str[str.size()-1-i]) isParin = false;
    }
    if(isParin) ret++;
  }
  cout << ret << endl;
}
