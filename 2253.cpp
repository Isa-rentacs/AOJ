#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//[-30,30] -> [1,61]
bool counted[62][62];
bool dp[2][62][62];
bool obj[62][62];

int dx[6] = {1,1,0,-1,-1,0}

int main(){
    int t, n;

    while(cin >> t >> n){
        memset(counted, false, sizeof(counted));
        memset(dp, false, sizeof(dp));
        memset(obj, false, sizeof(obj));
        int x,y;

        for(int i=0;i<n;i++){
            cin >> x >> y;
            x += 31;
            y += 31;
            obj[x][y] = true;
        }
        int cur=0,nxt=1;
        cin >> x >> y;
        x += 31;
        y += 31;
        counted[x][y] = true;
        dp[cur][x][y] = true;
        for(int i=0;i<t;i++){

        }
    }
}
