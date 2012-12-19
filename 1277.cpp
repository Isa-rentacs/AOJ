#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

double pr[128][101];
int board[101];

int main(){
    int n,t,l,b;

    while(cin >> n >> t >> l >> b){
        if((n|t|l|b) == 0) break;
        int tmp, nxt;
        memset(board, 0, sizeof(board));
        fill((double *)pr, (double *)pr+128*101, 0);


        for(int i=0;i<l;i++){
            cin >> tmp;
            board[tmp] = 1;
        }
        for(int i=0;i<b;i++){
            cin >> tmp;
            board[tmp] = 2;
        }

        pr[0][0] = 1.0;
        for(int i=1;i<=t;++i){
            for(int j=0;j<n;++j){
                for(int k=1;k<=6;++k){
                    if(j+k <= n){ //in board
                        nxt = j+k;
                    }else{
                        nxt = n - (j+k - n);
                    }
                    if(board[nxt] == 2){
                        nxt = 0;
                    }
                    if(board[nxt] == 1){
                        pr[i+1][nxt] += pr[i-1][j] / 6;
                    }else{
                        pr[i][nxt] += pr[i-1][j] / 6;
                    }
                }
            }
        }

        double ret = 0;
        for(int i=0;i<=t;i++){
            ret += pr[i][n];
        }

        printf("%f\n", ret);
    }
}
