#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n,k,t,u,v,l,tmp;
    bool car[10002];
    cin >> n >> k >> t >> u >> v >> l;

    memset(car,false,sizeof(car));

    for(int i=0;i<n;i++){
        cin >> tmp;
        car[tmp] = true;
    }

    int stock = 0,fast = 0, slow = 0, rem = 0;
    for(int i=0;i<l;i++){
        if(rem == 0 && stock > 0){
            rem = v*t;
            stock--;
        }
        if(car[i]){
            if(rem == 0){
                rem = v*t;
            }else{
                if(stock == k){
                    rem = v*t;
                }else{
                    stock++;
                }
            }
        }
        if(rem > 0){
            fast++;
            rem--;
        }else{
            slow++;
        }
    }
    printf("%.10f\n", (double)fast/v + (double)slow/u);
}
