#include <iostream>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

bool isprime[1000001];
int fact[1000001];
bool isfox[1000001];
int primes[78498];

inline int factorial(ll arg, int base){
    int ret = 0;
    while(arg % base == 0){
        arg /= base;
        ret++;
    }
    return ret;
}

int main(){
    std::ios_base::sync_with_stdio(false);    
    int cnt=0;
    ll a,b;
    for(int i=2;i<1000001;i++){
        if(!isprime[i]){
            primes[cnt++] = i;
            for(int j=2;i*j<1000001;j++){
                isprime[i*j] = true;
            }
        }
    }
    cin >> a >> b;
    ll len,bias;
    if(a - b < 2){
        bias = 2;
    }else{
        bias = a - b;
    }
    len = a + b - bias + 1;

    fill((int *)fact, (int *)fact+1000001, 1 << 29);

    for(int i=0;(ll)primes[i]*primes[i] <= a+b;i++){
        for(int j=(primes[i] - bias % primes[i])%primes[i];j<len;j+=primes[i]){
            if(isfox[j]) continue;
            int tmp = factorial(j+bias,primes[i]);
            if(tmp != 0){
                if(fact[j] == 1 << 29 || fact[j] >= tmp){
                    fact[j] = tmp;
                }else{
                    isfox[j] = true;
                }
            }
        }
    }
    int res = 0;
    for(int i=0;i<len;i++){
        res += !isfox[i]?1:0;            
    }
    cout << res << endl;
}
