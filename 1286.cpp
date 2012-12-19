#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
    int n,m,k;

    while(cin >> n >> m >> k){
        if((n|m|k) == 0) break;
        double dp[n+1][n*m+1];

        fill((double *)dp, (double *)dp+(n+1)*(n*m+1), 0);

        dp[0][0] = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<=n*m;j++){
                for(int l=1;l<=m;l++){
                    if(j+l <= n*m){
                        dp[i+1][j+l] += dp[i][j] / m;
                    }
                }
            }
        }
        double ret = 0;

        for(int i=0;i<=n*m;++i){
            ret += dp[n][i] * max(1,(i-k));
        }
        printf("%.8f\n", ret);
    }
}
