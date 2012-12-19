#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1<<16],w_sum[1<<16],top=0;
int fl[10001],k;
int w[16],ind=0;
int n,m,W;

int main(){
    cin >> n >> m >> W;
    m -= 1;

    memset(fl,0, sizeof(fl));
    memset(w_sum, 0, sizeof(w_sum));
    fill((int *)dp, (int *)dp+(1<<16), 1<<29);
    for(int i=0;i<n;i++){
        cin >> k;
        for(int j=0;j<k;j++){
            cin >> w[ind];
            fl[i] |= (1 << ind);
            ind++;
            top = i;
        }
    }

    if(fl[0] == (1 << ind) - 1){
        cout << 0 << endl;
        return 0;
    }

    for(int i=0;i<(1 << ind);i++){
        for(int j=0;j<ind;j++){
            if(i&(1<<j)){
                w_sum[i] += w[j];
            }
        }
    }
    
    dp[0] = 0;
    for(int i=0;i<(1<<ind);i++){
        for(int j=i;j!=0;--j&=i){
            if(w_sum[j] <= W){
                dp[i] = min(dp[i], dp[i^j]+1);
            }
        }
    }

    int ret = abs(top - m);
    for(int i=top;i>0;i--){
        ret += 2 * dp[fl[i]] -1;
        fl[i-1] |= fl[i];
    }
    cout << ret << endl;
}
