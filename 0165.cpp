#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(void){
    int n;
    bool isprime[1000001];
    vector<int> primes;

    //sieve
    memset(isprime, true, sizeof(isprime));
    for(int i=2;i<=1000000;i++){
        if(isprime[i] == true){
            primes.push_back(i);
            for(int j=2;i*j<=1000000;j++){
                isprime[i*j] = false;
            }
        }
    }

    int prize,ret,p,m;
    while(cin >> n && n){
        ret = 0;
        prize = 0;
        for(int i=0;i<n;i++){
            cin >> p >> m;
            prize = upper_bound(primes.begin(), primes.end(),p+m) - 
                lower_bound(primes.begin(),primes.end(),p-m);
            
            if(prize == 0){
                ret -= 1;
            }else{
                ret += prize-1;
            }
        }
        if(ret <= 0){
            cout << 0 << endl;
        }else{
            cout << ret << endl;
        }
    }
}
