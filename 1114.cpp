#include <iostream>
#include <algorithm>
using namespace std;

int f[5][5];

int main(){
    int n;
    cin >> n;
    for(int x=0;x<n;x++){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cin >> f[i][j];
            }
        }
        int ret=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                for(int k=0;k<5;k++){
                    for(int l=0;l<5;l++){
                        bool isok = true;
                        for(int p=i;p<=k;p++){
                            for(int q=j;q<=l;q++){
                                if(!f[p][q]){
                                    isok = false;
                                }
                            }
                        }
                        if(isok && i <= k && j <= l){
                            ret = max(ret, (k-i+1)*(l-j+1));
                        }
                    }
                }
            }
        }
        cout << ret << endl;
    }


}
