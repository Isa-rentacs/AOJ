#include <iostream>
#include <cstring>

using namespace std;
int dp[18][301][301];
int hoge;
int main(){
    memset(dp,0,sizeof(dp));
    for(int i=0;i<301;++i) dp[0][i][i] = 1;
    
    for(int i=1;i<18;i++){
        for(int j=0;j<301;j++){
            for(int k=0;k<301;++k){
                int cnt=0;
                while((i+1)*(i+1)*cnt+k<301){
                    dp[i][j+cnt][(i+1)*(i+1)*cnt+k] += dp[i-1][j][k];
                    cnt++;
                }
            }
        }
    }

    int n;
    while(cin >> n && n){
        int ret=0;
        for(int i=0;i<301;++i) ret+= dp[17][i][n];
        cout << ret << endl;
    }
}
