#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

char f[12][6];
bool checked[12][6];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int checkfrom(int i, int j){
    pair<int,int> tmp;
    deque<pair<int,int> > q;
    vector<pair<int,int> > modi;
    int cnt = 0,nx,ny;
    char color = f[i][j];

    q.push_back(make_pair(i,j));
    checked[i][j] = true;
    while(!q.empty()){
        tmp = q.front();
        q.pop_front();
        modi.push_back(tmp);
        cnt++;
        for(int i=0;i<4;i++){
            nx = tmp.first + dx[i];
            ny = tmp.second + dy[i];
            if(0 <= nx && nx < 12 &&
               0 <= ny && ny < 6 &&
               !checked[nx][ny] &&
               f[nx][ny] == color){
                q.push_back(make_pair(nx,ny));
                checked[nx][ny] = true;
            }
        }
    }
    if(cnt >= 4){
        for(int i=0;i<modi.size();i++){
            f[modi[i].first][modi[i].second] = '.';
            for(int j=0;j<4;j++){
                if(f[modi[i].first + dx[j]][modi[i].second + dy[j]] == 'O'){
                    f[modi[i].first + dx[j]][modi[i].second + dy[j]] = '.';
                }
            }
        }
    }
    return cnt;
}

int main(){
    int n;
    scanf("%d", &n);



    for(int x=0;x<n;x++){
        memset(f, 0, sizeof(f));

        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                scanf(" %c", &f[i][j]);
            }
        }
        int max_deleted = 0;
        int res = 0,tx,ty;
        while(1){
            max_deleted = 0;
            memset(checked, false, sizeof(checked));
            for(int i=11;i>=0;i--){
                for(int j=0;j<6;j++){
                    if(f[i][j] != '.' && f[i][j] != 'O' && !checked[i][j]){
                        max_deleted = max(checkfrom(i, j), max_deleted);
                    }
                }
            }
            for(int i=0;i<6;i++){
                int base = 11;
                for(int j=11;j>=0;j--){
                    if(f[j][i] != '.'){
                        f[base][i] = f[j][i];
                        base--;
                    }
                }
                while(base >= 0){
                    f[base][i] = '.';
                    base--;
                }
            }
            
            if(max_deleted < 4) break;
            res++;
        }
        cout << res << endl;
    }
}
