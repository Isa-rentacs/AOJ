#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        int m,p;
        int x,y;
        cin >> p;
        complex<double> v[p];
        for(int i=0;i<p;i++){
            cin >> x >> y;
            v[i] = complex<double>(x,y);
        }
        complex<double> e[p-1];
        for(int i=1;i<p;i++){
            e[i-1] = v[i] - v[i-1];
            //cerr << e[i-1] << endl;
        }

        for(int i=0;i<n;i++){
            cin >> m;
            complex<double> tgt[m];
            complex<double> tgte[m-1];
            for(int j=0;j<m;j++){
                cin >> x >> y;
                tgt[j] = complex<double>(x,y);
            }

            //if no. of vertex is different
            if(p != m) continue;

            for(int j=1;j<m;j++){
                tgte[j-1] = tgt[j] - tgt[j-1];
                //cerr << tgte[j-1] << endl;
            }
            bool ismatched;
            for(int j=0;j<4;j++){
                ismatched = true;
                for(int k=0;k<m-1;k++){
                    //cerr << "compare:" << e[k] << " and " << tgte[k] << endl; 
                    if(e[k] != tgte[k]){
                        ismatched = false;
                        break;
                    }
                }
                if(ismatched){
                    cout << i+1 << endl;
                    break;
                }

                ismatched = true;
                for(int k=0;k<m-1;k++){
                    //cerr << "compare:" << e[k] << " and " << tgte[m-k-2] << endl;
                    if(e[k] != tgte[m-k-2]){
                        ismatched = false;
                        break;
                    }
                }
                if(ismatched){
                    cout << i+1 << endl;
                    break;
                }else{
                    for(int k=0;k<m-1;k++){
                        tgte[k] *= complex<double>(0,1);
                    }
                }
            }
        }
        cout << "+++++" << endl;
    }
}
