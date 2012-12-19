#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int s,d,m;
int k[101];
int w[101][51];
int p[101][51];
int f[101];
int dp[5001][301];


int main(){
    while(cin >> s >> d >> m){
        memset(w, 0, sizeof(w));
        memset(p, 0, sizeof(p));
        memset(f, 0, sizeof(f));
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<s;i++){
            cin >> k[i];
            for(int j=0;j<k[i];j++){
                cin >> w[i][j];
                cin >> p[i][j];
            }
        }
        for(int i=0;i<d;i++){
            cin >> f[i];
        }
        dp[0][0] = 0;

        int cnt = 0;
        for(int i=0;i<d;i++){
            for(int l=0;l<k[f[i]];l++){
                for(int j=0;j<=m;j++){
                    if(j+p[f[i]][l] <= m && dp[cnt][j] != -1){
                        dp[cnt+1][j+p[f[i]][l]] = max(dp[cnt+1][j+p[f[i]][l]],dp[cnt][j] + w[f[i]][l]);
                    }
                    dp[cnt+1][j] = max(dp[cnt+1][j], dp[cnt][j]);
                }
                cnt++;
            }
        }
        int maxw = 0;
        int minp = 0; 
        for(int i=0;i<=m;i++){
            if(maxw < dp[cnt][i]){
                maxw = dp[cnt][i];
                minp = i;
            }
        }
        cout << maxw << " " << minp << endl;
    }
}
