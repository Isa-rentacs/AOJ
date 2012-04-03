#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    vector<int> primes;
    bool isprime[200001];
    
    memset(isprime, true, sizeof(isprime));

    for(int i=2;i<200001;++i){
        if(isprime[i]){
            primes.push_back(i);
            for(int j=2;i*j<200001;++j){
                isprime[i*j] = false;
            }
        }
    }

    int N,P;
    while(cin >> N >> P){
        if(N == -1 && P == -1) break;
        vector<int> sums;
        vector<int>::iterator it,jt;
        it = upper_bound(primes.begin(), primes.end(), N);
        
        for(int i=0;i<100;++i){
            jt = it;
            for(int j=0;j<100;++j){
                sums.push_back((*it) + (*jt));
                ++jt;
            }
            ++it;
        }
        sort(sums.begin(), sums.end());
        cout << sums[P-1] << endl;
    }
}
