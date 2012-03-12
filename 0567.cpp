#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n,a,b,c,t;
    double rate,ret;
    cin >> n >> a >> b >> c;
    int p = a, pr[n];
    for(int i=0;i<n;i++){
        cin >> pr[i];
    }
    sort(pr,pr+n);
    ret = (double)c/p;
    int tmpc = c, tmpp = p;
    for(int i=0;i<n;i++){
        tmpc = c;
        tmpp = p;
        for(int j=0;j<i;j++){
            tmpc += pr[n-1-j];
            tmpp += b;
        }
        ret = max(ret, (double)tmpc/tmpp);
    }
    cout << (int)floor(ret) << endl;
}
