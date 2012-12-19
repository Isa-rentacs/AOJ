#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

int f[101][101];
int chk[101][101];

int main(){
    int n;
    
    while(cin >> n && n){
        int x,y,ret=0,tmp;
        set<int> s;

        memset(chk, -1, sizeof(chk));

        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                cin >> x >> y;
                f[i][j] = x * 1000 + y;
            }
        }
        
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                x = i;
                y = j;
                while(chk[x][y] == -1){
                    s.insert(x*1000+y);
                    chk[x][y] = f[x][y];
                    tmp = f[x][y];
                    x = tmp / 1000;
                    y = tmp % 1000;
                }
                if(s.find(x*1000+y) != s.end()){
                    ret++;
                }
                s.clear();
            }
        }
        cout << ret << endl;
    }
}
