#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

char f[52][52];
bool visited[52][52];
int w,h;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int bfs(int y, int x){
    deque<pair<int,int> > q;
    set<char> s;
    int ret=1;
    q.push_back(make_pair(y,x));
    visited[y][x] = true;

    int tx, ty, nx, ny;
    while(!q.empty()){
        ty = q.front().first;
        tx = q.front().second;
        q.pop_front();
        for(int i=0;i<4;i++){
            ny = ty + dy[i];
            nx = tx + dx[i];

            if(f[ny][nx] == -1){
                //do nothing
            }else if(f[ny][nx] == 'W'){
                s.insert('W');
            }else if(f[ny][nx] == 'B'){
                s.insert('B');
            }else{
                if(!visited[ny][nx]){
                    visited[ny][nx] = true;
                    q.push_back(make_pair(ny,nx));
                    ret++;
                }
            }
        }
    }
    if(s.size() == 2 || s.size() == 0){
        return -1;
    }else{
        if(s.find('W') != s.end()){
            return ret+10000;
        }else{
            return ret;
        }
    }
}

int main(){
    while(cin >> w >> h){
        if((w|h) == 0) break;
        memset(f, -1 , sizeof(f));
        memset(visited, false, sizeof(visited));

        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin >> f[i][j];
            }
        }
        int bl=0,wh=0,tmp;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(!visited[i][j] && f[i][j] == '.'){
                    tmp = bfs(i,j);
                    if(tmp != -1){
                        if(tmp > 10000){
                            wh += tmp%10000;
                        }else{
                            bl += tmp;
                        }
                    }
                }
            }
        }
        cout << bl << " " << wh << endl;
    }
}
