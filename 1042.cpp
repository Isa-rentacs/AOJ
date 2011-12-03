#include <iostream>
#include <string>

using namespace std;

int main(void){
  string str;
  while(getline(cin,str)){
    if(str == "END OF INPUT") break;
    int l=0;
    for(int i=0;i<str.size();i++){
      if(str[i] == ' '){
	cout << l;
	l = 0;
      }else{
	l++;
      }
    }
    if(l)cout << l;
    cout << endl;
  }
}
