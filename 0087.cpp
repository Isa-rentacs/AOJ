#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

bool debug = false;

double toint(string str){
  istringstream iss(str);
  double ret;

  iss >> ret;
  return ret;
}

int main(void){
  stack<double> st;
  string str;
  string tmp = "";
  while(getline(cin, str)){
     for(int i=0;i<str.size();i++){
      if(debug) cout << i << ":" << str[i] << endl;
      if(('0' <= str[i] && str[i] <= '9') || str[i] == '.' ||
	 (str[i] == '-' && '0' <= str[i+1] && str[i+1] <= '9')){
	tmp += str[i];
      }else if(str[i] == ' '){
	if(!tmp.empty()){
	  st.push(toint(tmp));
	  if(debug) cout << "pushed " << tmp << endl;
	  tmp.clear();
	}
      }else{
	double arg1, arg2;
	arg2 = st.top(); st.pop();
	arg1 = st.top(); st.pop();
	if(str[i] == '+'){
	  st.push(arg1 + arg2);
	}else if(str[i] == '-'){
	  st.push(arg1 - arg2);
	}else if(str[i] == '*'){
	  st.push(arg1 * arg2);
	}else{
	  st.push(arg1 / arg2);
	}
      }
    }
    if(!st.empty()){
      printf("%.7f\n", st.top());
    }if(!tmp.empty()){
      printf("%.7f\n", toint(tmp));
      tmp.clear();
    }
    while(!st.empty()) st.pop();
  }
  
}
