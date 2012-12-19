#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
vector<int> primes,sums;
bool isprime[1 << 15];

int main(){
    int n;
    memset(isprime, true, sizeof(isprime));
    for(int i=2;i<(1<<15);++i){
        if(isprime[i]){
            primes.push_back(i);
            for(int j=2;i*j<(1 << 15);++j){
                isprime[i*j] = false;
            }
        }
    }
    int m = primes.size();

    for(int i=0;i<m;++i){
        for(int j=i;j<m;++j){
            sums.push_back(primes[i]+primes[j]);
        }
    }
    sort(sums.begin(), sums.end());
    while(cin >> n && n){
        cout << upper_bound(sums.begin(), sums.end(), n) - lower_bound(sums.begin(), sums.end(), n) << endl;
    }
}
