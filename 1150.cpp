#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int f[60][30];
int memo[2][60][30];
int lx[9] = { 1, 1, 2, 1, 2, 3, 1, 2, 1};
int ly[9] = {-2,-1,-1, 0, 0, 0, 1, 1, 2};
int rx[9] = {-1,-1,-2,-1,-2,-3,-1,-2,-1};
int ry[9] = {-2,-1,-1, 0, 0, 0, 1, 1, 2};
int w,h;
class state{
public:
    int foot;
    int x;
    int y;
    int cost;

    state(int f,int x, int y, int c):foot(f),x(x),y(y),cost(c){}
};

#define INF 1 << 29

int main(){
    char tmp;
    while(cin >> w >> h){
        if((w|h) == 0) break;
        deque<state> q;
        vector<pair<int,int> > v;
        fill((int *)memo, (int *)memo+2*60*30, INF);
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> tmp;
                if(tmp == 'X'){
                    f[i][j] = INF;
                }else if(tmp == 'S'){
                    f[i][j] = 0;
                    q.push_back(state(0,j,i,0));
                    q.push_back(state(1,j,i,0));
                    memo[0][i][j] = 0;
                    memo[1][i][j] = 0;
                }else if(tmp == 'T'){
                    f[i][j] = 0;
                    v.push_back(make_pair(i,j));
                }else{
                    f[i][j] = tmp - '0';
                }
            }
        }
        
        int tx,ty,tf,tc,nx,ny;
        int ret = INF;
        while(!q.empty()){
            tx = q.front().x;
            ty = q.front().y;
            tf = q.front().foot; //0:left 1:right
            tc = q.front().cost;

            //cout << "(" << tf << ")" << ty << " " << tx << " " << tc << endl;
            q.pop_front();

            for(int i=0;i<9;i++){
                if(tf == 0){
                    nx = tx + lx[i];
                    ny = ty + ly[i];
                }else{
                    nx = tx + rx[i];
                    ny = ty + ry[i];
                }

                //cout << "ny =" << ny << " nx = " << nx << endl;
                if(!(0 <= nx && nx < w && 0 <= ny && ny < h)){
                    continue;
                }else{
                    if(tc+f[ny][nx] < memo[1-tf][ny][nx]){
                        memo[1-tf][ny][nx] = tc+f[ny][nx];
                        q.push_back(state(1-tf,nx,ny,memo[1-tf][ny][nx]));
                    }
                }
            }
        }

        for(int i=0;i<v.size();i++){
            ret = min(ret, memo[0][v[i].first][v[i].second]);
            ret = min(ret, memo[1][v[i].first][v[i].second]);
        }

        if(ret == INF){
            cout << -1 << endl;
        }else{
            cout << ret << endl;
        }
    }
}
