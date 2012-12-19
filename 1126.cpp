#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool lt(string arg1, string arg2){
    if(arg1.size() == arg2.size()){
        return arg1 < arg2;
    }
    return arg1.size() <= arg2.size();
}

int main(){
    int w, h;

    while(cin >> w >> h){
        if((w|h) == 0) break;

        string dp[h+1][w+1];
        char b[h+1][w+1];
        char tmp;

        for(int i=0;i<=h;++i){
            for(int j=0;j<=w;++j){
                dp[i][j] = "";
            }
        }

        for(int i=1;i<=h;++i){
            for(int j=1;j<=w;++j){
                cin >> tmp;
                if('0' <= tmp && tmp <= '9'){
                    b[i][j] = tmp;
                }else{
                    b[i][j] = -1;
                }
            }
        }

        string ret="";
        for(int i=1;i<=h;++i){
            for(int j=1;j<=w;++j){
                if(b[i][j] == -1){
                    dp[i][j] = "";
                }else{
                    string str[2];
                    str[0] = dp[i-1][j] + b[i][j];
                    str[1] = dp[i][j-1] + b[i][j];
                    if(str[0] == "0") str[0] = "";
                    if(str[1] == "0") str[1] = "";

                    if(lt(str[0],str[1])){
                        dp[i][j] = str[1];
                    }else{
                        dp[i][j] = str[0];
                    }
                }
                if(lt(ret,dp[i][j])){
                    ret = dp[i][j];
                }
            }
        }
        cout << ret << endl;
    }
}
