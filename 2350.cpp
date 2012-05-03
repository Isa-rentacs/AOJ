#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

#define ll long long

using namespace std;

int digitAt(int arg, int d){
    int ret;

    ret = arg % (int)pow(10, d+1);
    ret /= (int)pow(10, d);
    return ret;
}

int bitcount(int arg){
    int ret=0;
    while(arg > 0){
        if(arg & 1) ret++;
        arg >>= 1;
    }
    return ret;
}

int main(){
    int a,b,k,tmp=0,borrow=0,ta,tb,ret=0;
    cin >> a >> b >> k;

    int n = log10(a) + 1;

    for(int i=0;i<(1 << n);i++){
        if(bitcount(i) <= k){
            tmp = 0;
            borrow = 0;
            for(int j=0;j<n;j++){
                ta = digitAt(a,j);
                tb = digitAt(b,j);
                if(ta - borrow >= tb){
                    tmp += (ta - tb - borrow) * pow(10, j);
                    borrow = 0;
                }else{
                    tmp += (ta - tb - borrow + 10) * pow(10, j);
                    if((1 << j) & i){
                        borrow = 0;
                    }else{
                        borrow = 1;
                    }
                }
            }
            ret = max(ret, tmp);
        }
    }
    cout << ret << endl;
}
