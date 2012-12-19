#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[32][32];

int main(){
    memset(dp, 0, sizeof(dp));
    string str, left, right;
    
    cin >> str;
    bool flg = false;
    for(int i=0;i<str.size();i++){
        if(str[i] == 'i' || str[i] == 'w'){
            flg = true;
        }else if(flg){
            right += str[i];
        }else{
            left += str[i];
        }
    }
    int n=left.size(), m=right.size();
    for(int i=0;i<m;i++){
        if(right[i] == '('){
            right[i] = ')';
        }else if(right[i] == ')'){
            right[i] = '(';
        }else if(right[i] == '['){
            right[i] = ']';
        }else if(right[i] == ']'){
            right[i] = '[';
        }else if(right[i] == '{'){
            right[i] = '}';
        }else if(right[i] == '}'){
            right[i] = '{';
        }
    }
    reverse(left.begin(), left.end());
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(left[i] == right[j]){
                dp[i+1][j+1] = dp[i][j]+1;
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    cout << dp[n][m]*2 + 3 << endl;
}
