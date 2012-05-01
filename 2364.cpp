#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int f[1001][1001];
bool checked[1001][1001];
int gx,gy,n;

bool solve(int hour){

}

int main(){
    int w,h,x,y;
    char c;

    while(cin >> w >> h){
        if((w|h) == 0) break;

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> c;
                if(c == '.'){
                    f[i][j] = 0;
                }else if(c == '#'){
                    f[i][j] = -1;
                }else if(c == 't'){
                    gx = j;
                    gy = h;
                    f[i][j] = 0;
                }
            }
        }
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> x >> y;
            f[y][x] = i+1;
        }
        int lb = 0, ub = 2000,mid;
        while(ub - lb > 1){
            mid = (lb+ub)/2;
            if(solve(mid)){
                ub = mid;
            }else{
                lb = mid;
            }
        }

        if(ub > n){
            cout << -1 << endl;
        }else{
            cout << ub << endl;
        }
    }
}
