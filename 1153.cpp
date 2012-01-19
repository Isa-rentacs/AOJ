#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        if((n|m) == 0) break;
        int a[n], b[m];
        int suma=0, sumb=0;
        int reta = -1, retb = -1;
        for(int i=0;i<n;i++){
            cin >> a[i];
            suma += a[i];
        }
        for(int i=0;i<m;i++){
            cin >> b[i];
            sumb += b[i];
        }
        sort(a,a+n);
        sort(b,b+m);
        bool able = false;
        for(int i=0;i<n && able == false;i++){
            for(int j=0;j<m && able == false;j++){
                if(2 * (a[i] - b[j]) == suma - sumb){
                    reta = a[i];
                    retb = b[j];
                    able = true;
                }
            }
        }
        if(able){
            cout << reta << " " << retb << endl;
        }else{
            cout << -1 << endl;
        }
    }
}
