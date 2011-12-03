#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(void){
  string str = "";
  string tmp;
  bool digit = false;
  long long ret=0;
  long long itmp;
  while(getline(cin,tmp)){
    int n = tmp.size();

    for(int i=0;i<tmp.size();i++){
      if('0' <= tmp[i] && tmp[i] <= '9'){
	str += tmp[i];
      }else if(!str.empty()){
	//cout << str << endl;
	istringstream iss(str);
	iss >> itmp;
	ret += itmp;
	str.clear();
      }
    }
    if(!str.empty()){
      istringstream iss(str);
      iss >> itmp;
      ret += itmp;
      str.clear();
    }
  }
  cout << ret << endl;
}
