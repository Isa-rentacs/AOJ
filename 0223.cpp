#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

bool f[52][52];
bool visited[52][52][52][52];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};


class state{
public:
    int ax;
    int ay;
    int bx;
    int by;
    int depth;

    state(int a, int b, int c, int d, int e){
        ax = a;
        ay = b;
        bx = c;
        by = d;
        depth = e;
    }
};

int main(){
    int w,h;
    while(cin >> w >> h){
        if((w|h) == 0) break;
        int ax,ay,bx,by,tmp;
        deque<state> q;
        cin >> ax >> ay;
        cin >> bx >> by;
        
        memset(f,false,sizeof(f));
        memset(visited, false, sizeof(visited));

        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin >> tmp;
                f[i][j] = tmp?0:1;
            }
        }

        state s = state(ax,ay,bx,by,0);
        int tmpd;
        bool isok = false;
        q.push_back(s);
        visited[ay][ax][by][bx] = true;
        while(!q.empty()){
            s = q.front();
            ax = s.ax;
            ay = s.ay;
            bx = s.bx;
            by = s.by;
            tmpd = s.depth;
            q.pop_front();
            if((ax == bx) && (ay == by)){
                cout << tmpd << endl;
                isok = true;
                break;
            }
            if(tmpd == 100){
                break;
            }
            int nax, nay, nbx, nby;
            for(int i=0;i<4;i++){
                nax = ax+dx[i];
                nay = ay+dy[i];
                nbx = bx+dx[(i+2)%4];
                nby = by+dy[(i+2)%4];
                if(f[nay][nax] == false){
                    nay = ay;
                    nax = ax;
                }
                if(f[nby][nbx] == false){
                    nby = by;
                    nbx = bx;
                }
                if(f[nay][nax] == true && f[nby][nbx] == true &&
                   visited[nay][nax][nby][nbx] == false){
                    q.push_back(state(nax,nay,nbx,nby,tmpd+1));
                    visited[nay][nax][nby][nbx] = true;
                }
            }
        }
        if(!isok) cout << "NA" << endl;
        q.clear();
    }
}
