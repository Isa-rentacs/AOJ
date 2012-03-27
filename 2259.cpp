#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,m,ret=0,s,t;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        t=0;
        for(int j=0;j<m;j++){
            cin >> s;
            t += s;
        }
        ret = max(ret, t);
    }
    cout << ret << endl;
}
