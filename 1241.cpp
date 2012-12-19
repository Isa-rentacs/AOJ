#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    vector<int> sq;
    int dp[5][1<<15+1];

    memset(dp,0,sizeof(dp));
    for(int i=1;i*i<=(1<<15);++i){
        sq.push_back(i*i);
        dp[0][i*i] = 1;
    }

    for(int i=0;i<4;++i){
        for(int j=0;j<(1<<15);++j){
            for(int k=0;k<sq.size();++k){
                dp[i+1][j+sq[k]] += dp[i][j];
            }
        }
    }

    int n;
    while(cin >> n && n){
        cout << dp[4][n] << endl;
    }
}
