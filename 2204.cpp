#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        int maxi=0,mini=501,s,t,i=0,j;
        for(;i<n;++i){
            s=0;
            for(j=0;j<5;++j){
                cin >> t;
                s += t;
            }
            maxi = max(maxi, s);
            mini = min(mini, s);
        }
        cout << maxi << " " << mini << endl;
    }
}
