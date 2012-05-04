#include <iostream>
#include <cstring>

using namespace std;

int cnt[26];
long long c[40][40];


long long combination(int n,int k){
    if(c[n][k] != -1) return c[n][k];

    if(k == 0 || n == k){
        return c[n][k] = 1;
    }
    c[n][k] = combination(n-1,k) + combination(n-1,k-1);
    return c[n][k];
}

int main(){
    string str;
    cin >> str;
    long long ret = 1;
    int n = str.size();
    memset(c,-1,sizeof(c));

    for(int i=0;i<n;i++){
        cnt[str[i] - 'a']++;
    }

    int timesodd = 0;
    for(int i=0;i<n;i++){
        if(cnt[i] % 2){
            timesodd++;
            cnt[i]--;
        }
        cnt[i] /= 2;
    }
    if(timesodd > 1){
        cout << 0 << endl;
    }else{
        int len = n/2;
        for(int i=0;i<26;i++){
            if(cnt[i] != 0){
                ret *= combination(len,cnt[i]);
                len -= cnt[i];
            }
        }
        cout << ret << endl;
    }    
}
