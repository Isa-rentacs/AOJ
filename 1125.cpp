#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool f[101][101];
int dp[101][101];

int main(){
    int w,h,n,x,y,s,t;

    while(cin >> n && n){
        cin >> w >> h;
        memset(f, false, sizeof(f));
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<n;++i){
            cin >> x >> y;
            f[y][x] = true;
        }
        cin >> s >> t;
        for(int i=1;i<=h;++i){
            for(int j=1;j<=w;++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + f[i][j];
            }
        }

        int ret = -1;
        for(int i=1;i<=h;++i){
            for(int j=1;j<=w;++j){
                if(i >= t && j >= s){
                    ret = max(ret, dp[i][j] - dp[i-t][j] - dp[i][j-s] + dp[i-t][j-s]);
                }
            }
        }

        cout << ret << endl;
    }
}
