#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string str;
    while(getline(cin,str)){
        if(str == ".") break;
        stack<char> st;
        char c;
        bool isok=true;
        for(int i=0;i<str.size();i++){
            c = str[i];
            if(c == '(' || c == '['){
                st.push(c);
            }else if(c == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    isok = false;
                    break;
                }
            }else if(c == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }else{
                    isok = false;
                    break;
                }
            }
        }
        if(!st.empty()) isok = false;
        cout << (isok?"yes":"no") << endl;
    }
}
