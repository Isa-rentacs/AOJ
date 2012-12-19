#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

double color[20][3];
double dist[20][20];

int bitcount(int arg){
    int ret = 0;
    while(arg > 0){
        if(arg & 1) ret++;
        arg >>= 1;
    }
    return ret;
}

int main(){
    int n,m;
    
    while(cin >> n >> m){
        if((n|m) == 0) break;
        
        memset(color, 0, sizeof(color));
        memset(dist, 0, sizeof(dist));

        for(int i=0;i<n;i++){
            cin >> color[i][0] >> color[i][1] >> color[i][2];
        }

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                dist[i][j] = 
                    pow(abs(color[i][0] - color[j][0]), 2) +
                    pow(abs(color[i][1] - color[j][1]), 2) +
                    pow(abs(color[i][2] - color[j][2]), 2);
                dist[j][i] = dist[i][j];
            }
        }

        double tmp, ret=-1;

        for(int i=0;i<(1 << n);i++){
            if(bitcount(i) == m){ //choosed m colors
                tmp = 0;
                for(int j=0;j<n;j++){
                    if((i & (1 << j))){
                        for(int k=j+1;k<n;k++){
                            if((i & (1 << k))){
                                tmp += dist[j][k];
                            }
                        }
                    }
                }
                ret = max(ret, tmp);
            }
        }
        printf("%.17f\n", ret);
    }
}
