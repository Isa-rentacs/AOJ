#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int ret=0;
    cin >> str;
    int n = str.size();
    for(int i=0;i<n/2;++i){
        if(str[i] == str[n-i-1]){
            if(str[i] == '(' || str[i] == ')'){
                ret++;
            }
        }else{
            if(!((str[i] == '(' && str[n-i-1] == ')') ||
                 (str[i] == ')' && str[n-i-1] == '('))){
                ret++;
            }
        }
    }
    if(n%2==1){
        if(str[n/2] != 'i' && str[n/2] != 'w'){
            ret++;
        }
    }
    cout << ret << endl;
}
