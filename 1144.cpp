#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int ret;
int xg, yg;

void dfs(int f[][22], int xx, int yy, int depth){
    int next;
    int pos;
    //cerr << xx << " " << yy << " " << depth << endl;
    //cin >> pos;
    if(depth == 10) return;

    for(int i=0;i<4;i++){ //for 4 directions
        for(int j=1;;j++){
            next = f[xx+dx[i]*j][yy+dy[i]*j];
            if(next == -1){
                break;
            }else if(next == 0){
                //do nothing
            }else if(next == 1){
                if(j != 1){
                    //break a block
                    f[xx+dx[i]*j][yy+dy[i]*j] = 0;
                    dfs(f, xx+dx[i]*(j-1), yy+dy[i]*(j-1),depth+1);
                    //regenerate block
                    f[xx+dx[i]*j][yy+dy[i]*j] = 1;
                    break;
                }else{
                    break;
                }
            }else if(next == 3){
                ret = min(ret, depth+1);
                break;
            }
        }
    }
}

int main(){
    int w,h;
    int f[22][22];
    int xs,ys;
    while(cin >> w >> h){
        if((w|h) == 0) break;
        ret = 11;
        memset(f, -1, sizeof(f));
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin >> f[j][i];
                if(f[j][i] == 2){
                    xs = j;
                    ys = i;
                    f[j][i] = 0;
                }
                if(f[j][i] == 3){
                    xg = j;
                    yg = i;
                }
            }
        }

        dfs(f,xs,ys,0);
        if(ret == 11){
            cout << -1 << endl;
        }else{
            cout << ret << endl;
        }
    }
}
