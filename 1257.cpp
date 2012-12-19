#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

vector<int> primes;
bool isprime[10001];
int cnt[10001];

int main(){
    int n;

    memset(isprime,true,sizeof(isprime));

    for(int i=2;i<=10000;i++){
        if(isprime[i]){
            primes.push_back(i);
            for(int j=2;i*j<=10000;++j){
                isprime[i*j] = false;
            }
        }
    }

    int sz = primes.size();
    
    for(int i=0;i<sz;i++){
        int tmp=0;
        for(int j=i;j<sz;j++){
            tmp += primes[j];
            if(tmp > 10000) break;
            cnt[tmp]++;
        }
    }

    while(cin >> n && n){
        cout << cnt[n] << endl;
    }
}
