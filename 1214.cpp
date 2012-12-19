#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>

using namespace std;

#define INF 1e+9

int f[10][10];
int visited[10][10];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int w,h;
int gy,gx;
int sy,sx;

struct state{
    int y;
    int x;
    int hp;
    int t;

    state(){}
    state(int _y, int _x, int _hp, int _t):y(_y), x(_x), hp(_hp), t(_t){}
};

int solve(){
    memset(visited, -1, sizeof(visited));
    deque<state> q;
    state st;
    int ny, nx;
    q.push_back(state(sy,sx,6,0));
    visited[sy][sx] = 6;

    while(!q.empty()){
        st = q.front();
        q.pop_front();

        if(st.y == gy && st.x == gx){
            return st.t;
        }

        if(st.hp == 1) continue;

        for(int i=0;i<4;i++){
            ny = st.y + dy[i];
            nx = st.x + dx[i];

            if(f[ny][nx] == 0) continue;

            if(visited[ny][nx] < st.hp){
                visited[ny][nx] = st.hp;
                if(f[ny][nx] == 4){
                    q.push_back(state(ny,nx,6,st.t+1));
                }else{
                    q.push_back(state(ny,nx,st.hp-1,st.t+1));
                }
            }
        }
    }
    return -1;
}

int main(){
    while(cin >> w >> h){
        if((w|h) == 0) break;

        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin >> f[i][j];
                if(f[i][j] == 3){
                    gy = i;
                    gx = j;
                }else if(f[i][j] == 2){
                    sy = i;
                    sx = j;
                }
            }
        }
        int ret= solve();

        cout << ret << endl;
    }
}
