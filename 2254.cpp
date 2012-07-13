#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t[16][17];
int dp[1 << 17 + 1];
int n,tmp;

int solve(int state){
    if(dp[state] != -1) return dp[state];
    if(state == (1 << n) - 1) return 0;
    int ret = 1<< 30;
    int tmptime;

    for(int i=0;i<n;i++){
        if((state & (1 << i)) == 0){ //not cleared yet
            tmptime = t[i][0];
            for(int j=1;j<=n;j++){
                if((state & (1 << (j-1))) != 0){
                    tmptime = min(tmptime, t[i][j]);
                }
            }
            ret = min(ret, tmptime + solve(state|(1 << i)));
        }
    }
    
    return dp[state] = ret;
}

int main(){
    while(cin >> n && n){
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<n+1;j++){
                cin >> tmp;
                t[i][j] = tmp;
            }
        }
        cout << solve(0) << endl;
    }
}
