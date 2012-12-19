#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
char f[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int n,m;
bool erase(vector<pair<int,int> > pos){
    bool reachable[2][502][502];
    memset(reachable, false, sizeof(reachable));
    int x,y;
    
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            y = pos[i].first;
            x = pos[i].second;
            do{
                y += dy[j];
                x += dx[j];
                if(f[y][x] == '.'){
                    reachable[i][y][x] = true;
                }else{
                    break;
                }
            }while(f[y][x] == '.');
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(reachable[0][i][j] && reachable[1][i][j]){
                return true;
            }
        }
    }
    return false;
}

int main(){

    cin >> m >> n;
    vector<pair<int,int> > place[26];

    memset(f, -1, sizeof(f));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> f[i][j];
            if(f[i][j] == '.') continue;
            place[f[i][j] - 'A'].push_back(make_pair(i,j));
        }
    }

    int ret=0;
    bool isended = false;
    while(!isended){
        isended = true;
        for(int i=0;i<26;i++){
            if((int)place[i].size() != 0){
                if(erase(place[i])){
                    ret += 2;
                    isended = false;
                    f[place[i][0].first][place[i][0].second] = '.';
                    f[place[i][1].first][place[i][1].second] = '.';
                    place[i].clear();
                }
            }
        }
    }
    cout << ret << endl;
}
