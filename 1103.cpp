#include <iostream>
#include <cstring>

using namespace std;

int dx[4],dy[4],ret=0;
int f[4][4];

void dfs(int depth){
    int x=-1,y=-1,nx,ny;

    if(depth == 8){
        ret++;
        return;
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(f[i][j] == 0){
                y = i;
                x = j;
                break;
            }
        }
        if(x >= 0) break;
    }
    f[y][x] = 1;
    for(int i=0;i<4;i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(0 <= nx && nx < 4 && 0 <= ny && ny < 4 && !f[ny][nx]){
            f[ny][nx] = 1;
            dfs(depth+1);
            f[ny][nx] = 0;
        }
    }
    f[y][x] = 0;
}

int main(){
    while(cin >> dx[0] >> dy[0]){
        memset(f, 0, sizeof(f));
        if(dx[0] > 4) break;
        ret=0;
        for(int i=1;i<4;i++){
            cin >> dx[i] >> dy[i];
        }
        dfs(0);
        cout << ret << endl;
    }
}
