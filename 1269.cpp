#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

long long dp[200][15][1121];
bool isprime[1121];
vector<int> primes;

int main(){
    memset(isprime, true, sizeof(isprime));
    for(int i=2;i<=1120;++i){
        if(isprime[i]){
            primes.push_back(i);
            for(int j=2;i*j<=1120;++j){
                isprime[i*j] = false;
            }
        }
    }
    int sz = primes.size();

    dp[0][0][0] = 1;
    
    for(int i=1;i<=sz;i++){
        for(int j=0;j<=14;j++){
            for(int k=0;k<=1120;k++){
                if(k+primes[i-1] <= 1120 && j != 14){
                    dp[i][j+1][k+primes[i-1]] += dp[i-1][j][k];
                }
                dp[i][j][k] += dp[i-1][j][k];
            }
        }
    }

    int n,k;
    while(cin >> n >> k){
        if((n|k) == 0) break;
        cout << dp[sz][k][n] << endl;
    }
}
