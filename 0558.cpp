#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdio>

#define INF 1 << 29

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
char f[1003][1003];
bool visited[1003][1003][10];

class S{
public:
    int x;
    int y;
    int lvl;
    int step;

    S(int x, int y, int lvl, int step):x(x),y(y),lvl(lvl),step(step){}
};

int main(){
    int h,w,lvl,sx,sy,gx,gy;
    cin >> h >> w >> lvl;
    fill((char *)f, (char *)f+1003*1003, 'X');
    fill((bool *)visited, (bool *)visited+1003*1003*10, false);

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> f[i][j];
            if(f[i][j] == 'S'){
                sx = j;
                sy = i;
            }else if(f[i][j] == lvl + '0'){
                gx = j;
                gy = i;
            }
        }
    }
    deque<S> q;
    q.push_back(S(sx,sy,1,0));
    visited[sy][sx][1] = true;
    int px,py,tmplvl,tmpstep;
    while(!q.empty()){
        px = q.front().x;
        py = q.front().y;
        tmplvl = q.front().lvl;
        tmpstep = q.front().step;
        q.pop_front();

        //printf("current:(y = %d, x = %d, lvl = %d, step = %d)\n", py,px,tmplvl,tmpstep);

        if(py == gy && px == gx && tmplvl == lvl+1){
            break;
        }
        visited[py][px][tmplvl] = tmpstep;
        for(int i=0;i<4;i++){
            int nx = px + dx[i];
            int ny = py + dy[i];

            if(f[ny][nx] != 'X'){
                if(f[ny][nx] == tmplvl +'0'){
                    q.push_back(S(nx,ny,tmplvl+1,tmpstep+1));
                }else{
                    if(!visited[ny][nx][tmplvl]){
                        q.push_back(S(nx,ny,tmplvl,tmpstep+1));
                        visited[ny][nx][tmplvl] = true;
                    }
                }
            }
        }
    }
    cout << tmpstep << endl;
}
