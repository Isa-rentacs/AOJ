#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int val[20];

int main(){
    int n,w;

    while(cin >> n >> w){
        if((n|w) == 0) break;
        int maxh=0, maxw = 0, tmp;
        double ret=0;
        memset(val, 0, sizeof(val));

        for(int i=0;i<n;i++){
            cin >> tmp;
            val[tmp/w]++;
            maxw = max(maxw, tmp/w);
            maxh = max(maxh, val[tmp/w]);
        }
        maxw++;
        for(int i=0;i<maxw;i++){
            ret += ((double)(maxw-i-1)/(maxw-1)) * ((double)val[i] / maxh);
        }
        printf("%.7f\n", ret+0.01);
    }
}
