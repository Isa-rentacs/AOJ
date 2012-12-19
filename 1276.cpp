#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

bool isprime[1300001];
vector<int> primes;

int main(){
    memset(isprime,true,sizeof(isprime));

    for(int i=2;i<=1300000;++i){
        if(isprime[i]){
            primes.push_back(i);
            for(int j=2;i*j<=1300000;j++){
                isprime[i*j] = false;
            }
        }
    }

    int n;
    while(cin >> n && n){
        if(find(primes.begin(), primes.end(), n) != primes.end()){
            cout << 0 << endl;
        }else{
            vector<int>::iterator it = upper_bound(primes.begin(), primes.end(), n);
            cout << *it - *(it-1) << endl;
        }
    }
}
