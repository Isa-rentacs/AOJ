#include <iostream>

using namespace std;

int rec(int n, int k){
    if(n == 1) return 1;
    return (k-1+rec(n-1,k))%n + 1;
}

int main(){
    int n,k,m;

    while(cin >> n >> k >> m){
        if((n|k|m) == 0) break;
        if(k==1){
            if(m==1){
                cout << n << endl;
            }else{
                cout << m-1 << endl;
            }
            continue;
        }
        int bias = m-k;
        while(bias < 0){
            bias += n;
        }
        int ret = (rec(n,k)+bias)%n;
        if(ret == 0) ret = n;
        cout << ret << endl;
    }
}
