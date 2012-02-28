#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int n;
    while(cin >> n && n){
        bool field[21][21];
        int px = 10;
        int py = 10;
        vector<pair<int,int> > js(n);
        memset(field, false, sizeof(field));
        for(int i=0;i<n;i++){
            cin >> js[i].first >> js[i].second;
        }
        int m,dir;
        char c;
        int times;
        cin >> m;
        field[px][py] = true;
        for(int i=0;i<m;i++){
            cin >> c;
            if(c == 'E'){
                dir = 0;
            }else if(c == 'N'){
                dir = 1;
            }else if(c == 'W'){
                dir = 2;
            }else{
                dir = 3;
            }
            cin >> times;
            for(int j=0;j<times;j++){
                px += dx[dir];
                py += dy[dir];
                field[px][py] = true;
            }
        }
        bool isok = true;
        for(int i=0;i<n;i++){
            if(field[js[i].first][js[i].second] == false){
                isok = false;
            }
        }
        if(isok){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
