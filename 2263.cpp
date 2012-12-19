#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<pair<int,int> > v; //<B,A>
    int a,b;
    cin >> n;
    int dp[n+1][n+1];
    fill((int *)dp, (int *)dp+(n+1)*(n+1), 1 << 29);
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v.push_back(make_pair(b,a));
    }
    dp[0][0] = 0;
    sort(v.begin(), v.end());
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j] + v[i].second <= v[i].first){
                dp[i+1][j+1] = min(dp[i][j+1], dp[i][j] + v[i].second);
            }
            dp[i+1][j] = min(dp[i][j],dp[i+1][j]);
        }
    }
    int ret;
    for(int i=0;i<=n;i++){
        if(dp[n][i] != 1<<29){
            ret = i;
        }
    }
    cout << ret << endl;
}
