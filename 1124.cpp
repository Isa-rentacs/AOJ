#include <iostream>
#include <cstring>

using namespace std;

int v[101];

int main(){
    int n,q;

    while(cin >> n >> q){
        if((n|q) == 0) break;
        memset(v, 0, sizeof(v));
        int num,tmp,ret=0,maxi=q-1;

        for(int i=0;i<n;++i){
            cin >> num;
            for(int j=0;j<num;++j){
                cin >> tmp;
                v[tmp]++;
            }
        }
        for(int i=0;i<101;i++){
            if(v[i] > maxi){
                ret = i;
                maxi = v[i];
            }
        }
        cout << ret << endl;
    }
}
