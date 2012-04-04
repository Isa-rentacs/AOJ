#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,S;

    while(cin >> n >> S){
        if(n+S == 0) break;
        vector<int> r(n);
        int ret=0;
        for(int i=0;i<n;i++){
            cin >> r[i];
        }

        if(n == 1){
            cout << 0 << endl;
            continue;
        }

        sort(r.begin(), r.end());
        for(int i=0;i<n;i++){
            if(r[i] > (double)S/2){
                ret += n-i-1;
            }else{
                ret += r.end() - upper_bound(r.begin(), r.end(), S-r[i]); 
            }
        }
        cout << ret << endl;
    }
}
