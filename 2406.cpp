#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int n,t,e;
    cin >> n >> t >> e;

    int ans = -1;
    int tmp,rem;
    for(int i=0;i<n;i++){
        cin >> tmp;
        rem = t % tmp;
        if(rem <= e || tmp <= rem + e ){
            ans = i+1;
        }
    }
    cout << ans << endl;
}
