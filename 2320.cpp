#include <iostream>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

int h,w,x,y,dir;
long long l;
char c;
char ansdir[4] = {'E', 'N', 'W', 'S'};
bool f[102][102];
long long memo[102][102][4];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main(){
    while(cin >> h >> w >> l){
        if((h|w|l) == 0) break;
        memset(f,false,sizeof(f));
        memset(memo,-1,sizeof(memo));
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin >> c;
                if(c == '.'){
                    f[i][j] = true;
                }else if(c == '#'){
                    f[i][j] = false;
                }else{
                    f[i][j] = true;
                    y = i;
                    x = j;
                    if(c == 'E'){
                        dir = 0;
                    }else if(c == 'N'){
                        dir = 1;
                    }else if(c == 'W'){
                        dir = 2;
                    }else{
                        dir = 3;
                    }
                }
            }
        }
        long long t=0;
        memo[y][x][dir] = 0;
        while(t != l){
            //search
            int ndir;
            for(int i=0;i<4;i++){
                ndir = (dir - i + 4)%4;
                if(f[y+dy[ndir]][x+dx[ndir]]) break;
            }
            dir = ndir;
            y += dy[ndir];
            x += dx[ndir];
            t++;
            if(memo[y][x][dir] != -1){
                ll loop = t - memo[y][x][dir];
                ll left = l - t;
                ll div = left / loop;
                t += div * loop;
                memset(memo,-1,sizeof(memo));
            }else{
                memo[y][x][dir] = t;
            }
        }
        cout << y << " " << x << " " << ansdir[dir] << endl;
    }
}
