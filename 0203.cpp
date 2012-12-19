#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dw[3] = {-1,0,1};

int main(){
    int w,h;

    while(cin >> w >> h){
        if(!(w|h)) break;
        int field[h+2][w+2];
        int dp[h+2][w+2];
        int kind;
        long long ret=0;
        fill((int *)field, (int *)field+(h+2)*(w+2), 1);
        fill((int *)dp, (int *)dp+(h+2)*(w+2), 0);

        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin >> field[i][j];
            }
        }

        for(int i=1;i<=w;i++){
            if(field[1][i] == 0) dp[1][i] = 1;
        }
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                kind = field[i][j];
                if(kind == 0){
                    for(int k=0;k<3;k++){
                        if(field[i+1][j+dw[k]] == 0 || 
                           (field[i+1][j+dw[k]] == 2 && k == 1)){
                            dp[i+1][j+dw[k]] += dp[i][j];
                        }
                    }
                }else if(kind == 2){
                    if(i != h-1){
                        if(field[i+2][j] != 1){
                            dp[i+2][j] += dp[i][j];
                        }
                    }else{
                        ret += dp[i][j];
                    }
                }
            }
        }

        for(int i=1;i<=w;i++){
            ret += dp[h][i];
        }
        cout << ret << endl;
    }
}
