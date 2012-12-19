#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int f[10][10];
int h,w,c;
int ret=-1;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

void pr(){
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cout << f[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void bfs(int count, int color){
    int orig,cnt=1;
    vector<pair<int,int> > vec;
    deque<pair<int ,int> > q;
    bool visited[10][10];
    
    memset(visited, false, sizeof(visited));
    orig = f[1][1];
    q.push_back(make_pair(1,1));
    visited[1][1] = true;
    vec.push_back(make_pair(1,1));
    int tx,ty,nx,ny;
    while(!q.empty()){
        ty = q.front().first;
        tx = q.front().second;
        q.pop_front();

        for(int i=0;i<4;i++){
            ny = ty + dy[i];
            nx = tx + dx[i];

            if(f[ny][nx] == orig && visited[ny][nx] == false){
                visited[ny][nx] = true;
                vec.push_back(make_pair(ny,nx));
                q.push_back(make_pair(ny,nx));
                if(orig == c)cnt++;
            }
        }
    }
    
    if(count == 5){
        ret = max(ret, cnt);
        return;
    }

    for(int i=0;i<vec.size();i++){
        f[vec[i].first][vec[i].second] = color;
    }

    for(int i=1;i<=6;i++){
        if(i != color){
            bfs(count+1,i);
        }
    }

    for(int i=0;i<vec.size();i++){
        f[vec[i].first][vec[i].second] = orig;
    }
}

int main(){
    while(cin >> h >> w >> c){
        if((h|w|c) == 0) break;
        ret = -1;
        memset(f, -1, sizeof(f));
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin >> f[i][j];
            }
        }
        for(int i=1;i<=6;i++){
            if(f[1][1] != i){
                bfs(0,i);
            }
        }
        cout << ret << endl;
    }
}
