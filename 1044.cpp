#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
  string str;
  char c;
  while(cin >> str >> c){
    int t;
    vector<string> v;
    string buf = "";
    bool isOneWord = true;
    if(c == 'X')break;
    if('A' <= str[0] && str[0] <= 'Z'){
      //upper camel case
      for(int j=0;j<str.size();j++){
	if('A' <= str[j] && str[j] <= 'Z'){
	  if(j!=0)v.push_back(buf);
	  buf = "";
	  buf += str[j] - 'A' + 'a';
	}else{
	  buf += str[j];
	}
      }
      v.push_back(buf);
    }else{
      for(int i=0;i<str.size();i++){
	if(str[i] == '_'){
	  //snake case
	  for(int j=0;j<str.size();j++){
	    if(str[j] == '_'){
	      v.push_back(buf);
	      buf = "";
	    }else{
	      buf += str[j];
	    }
	  }
	  v.push_back(buf);
	  isOneWord = false;
	  break;
	}else if('A' <= str[i] && str[i] <= 'Z'){
	  //lower cames case
	  for(int j=0;j<str.size();j++){
	    if('A' <= str[j] && str[j] <= 'Z'){
	      if(j!=0)v.push_back(buf);
	      buf = "";
	      buf += str[j] - 'A' + 'a';
	    }else{
	      buf += str[j];
	    }
	  }
	  v.push_back(buf);
	  isOneWord = false;
	  break;
	}
      }
      if(isOneWord){
	v.push_back(str);
      }
    }
    //convert
    if(c == 'L'){
      for(int i=0;i<v.size();i++){
	if(i==0){
	  cout << v[i];
	}else{
	  v[i][0] -= 'a' - 'A';
	  cout << v[i];
	}
      }
    }else if(c == 'U'){
      for(int i=0;i<v.size();i++){
	v[i][0] -= 'a' - 'A';
	cout << v[i];
      }
    }else{
      for(int i=0;i<v.size();i++){
	cout << v[i];
	if(i != v.size()-1) cout << "_";
      }
    }
    cout << endl;
  }
}
