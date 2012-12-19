#include <iostream>
#include <cstring>

using namespace std;

bool knew[101][101];
int pat[101];
int main(){
    int n,m,k,p;

    while(cin >> n && n){
        memset(knew, 0, sizeof(knew));
        memset(pat,0,sizeof(pat));
        for(int i=0;i<n;i++){
            cin >> m;
            for(int j=0;j<m;j++){
                cin >> p;
                knew[i][p] = true;
            }
        }
        cin >> k;
        for(int i=0;i<k;i++){
            cin >> p;
            pat[i] = p;
        }

        int cand=-1;
        bool sus;
        for(int i=0;i<n;i++){
            sus = true;
            for(int j=0;j<k;j++){
                if(knew[i][pat[j]] == false){
                    sus = false;
                    break;
                }
            }
            if(sus){
                if(cand == -1){
                    cand = i+1;
                }else{
                    cand = -1;
                    break;
                }
            }
        }
        cout << cand << endl;
    }
}
