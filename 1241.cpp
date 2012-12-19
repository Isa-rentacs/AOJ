#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int dp[200][5][(1<<15)+1];

int main(){
    int n;
    vector<int> sq;
    
    for(int i=1;i*i<=(1 << 15);++i){
        sq.push_back(i*i);
    }
    int sqn = sq.size();



    dp[0][0][0] = 1;

    for(int i=1;i<=sqn;++i){
        for(int j=0;j<=(1 << 15);++j){
            for(int k=0;k<=4;++k){
                for(int l=0;l<=4;++l){
                    if(k+l <= 4 && j+sq[i-1]*l <= (1 << 15)){
                        dp[i][k+l][j+sq[i-1]*l] += dp[i-1][k][j];
                    }
                }
            }
        }
    }
    
    while(cin >> n && n){
        int ret = 0;

        for(int i=0;i<=4;++i){
            ret += dp[sqn][i][n];
        }
        cout << ret << endl;
    }
}
