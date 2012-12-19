#include <iostream>
#include <cstring>
#include <map>

#define MP make_pair

using namespace std;

int main(){
    int cases;
    cin >> cases;
    for(int c=0;c<cases;c++){
        map<pair<pair<int,int>, pair<int,int> >, bool> m;
        int x,y;
        cin >> x >> y;
        int dp[x+1][y+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        int p,a,b,c,d;
        cin >> p;
        for(int i=0;i<p;i++){
            cin >> a >> b >> c >> d;
            m[make_pair(make_pair(a,b), make_pair(c,d))] = true;
            m[make_pair(make_pair(c,d), make_pair(a,b))] = true;
        }

        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0 && j ==0){

                }else if(i == 0){
                    if(m[MP(MP(i,j), MP(i,j-1))] == false &&
                       m[MP(MP(i,j-1), MP(i,j))] == false){
                        dp[i][j] += dp[i][j-1];
                    }
                }else if(j == 0){
                    if(m[MP(MP(i,j), MP(i-1,j))] == false &&
                       m[MP(MP(i-1,j), MP(i,j))] == false ){
                        dp[i][j] += dp[i-1][j];
                    }
                }else{
                    if(m[MP(MP(i,j), MP(i-1,j))] == false &&
                       m[MP(MP(i-1,j), MP(i,j))] == false ){
                        dp[i][j] += dp[i-1][j];
                    }
                    if(m[MP(MP(i,j), MP(i,j-1))] == false &&
                       m[MP(MP(i,j-1), MP(i,j))] == false){
                        dp[i][j] += dp[i][j-1];
                    }
                }
            }
        }
        if(dp[x][y] == 0){
            cout << "Miserable Hokusai!" << endl;
        }else{
            cout << dp[x][y] << endl;
        }
    }
}
