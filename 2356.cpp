#include <iostream>
#include <cstring>

using namespace std;

int cnt[26];

long long combination(int n,int k){
    if(k == 1) return n;
    return n * combination(n-1,k-1);
}

int main(){
    string str;
    cin >> str;
    long long ret = 1;
    int n = str.size();
    

    for(int i=0;i<n;i++){
        cnt[str[i] - 'a']++;
    }

    int timesodd = 0;
    for(int i=0;i<n;i++){
        if(cnt[i] % 2){
            timesodd++;
            cnt[i]--;
            cnt[i] /= 2;
        }
    }
    if(timesodd > 1){
        cout << 0 << endl;
    }else{
        
    }    
}
