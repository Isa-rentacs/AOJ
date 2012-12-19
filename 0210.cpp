#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class person{
public:
    int x;
    int y;
    int dir;
    bool exit;
    person(int x, int y, int dir, int exit):
        x(x),y(y),dir(dir),exit(exit){}
};

//priority:(person-dir,next-dir)
//south-right
//east-right
//north-right
//west-right
//west-front
//south-front
//east-front
//north-front
//north-left
//west-left
//south-left
//east-left
//east-back
//north-back
//west-back
//south-back
int w,h;
int f[32][32];
int dx[4] = {1,0,-1,0}; //E,N,W,S
int dy[4] = {0,-1,0,1};
int dir[16] = { 3, 0, 1, 2, 2, 3, 0, 1, 1, 2, 3, 0, 0, 1, 2, 3};
int ndir[16] ={ 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1};

void pr(){
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(f[i][j] == -1){
                cout << "#";
            }else if(f[i][j] == 0){
                cout << ".";
            }else if(f[i][j] == 1){
                cout << "X";
            }else{
                cout << f[i][j]-2;
            }
        }
        cout << endl;
    }
}

int main(){
    while(cin >> w >> h){
        if((w|h) == 0) break;
        char tmp;
        vector<person> ps;
        memset(f, -1,sizeof(f));

        int cnt = 2;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin >> tmp;
                if(tmp == '#'){
                    f[i][j] = -1;
                }else if(tmp == 'X'){
                    f[i][j] = 1;
                }else if(tmp == '.'){
                    f[i][j] = 0;
                }else if(tmp == 'E'){
                    ps.push_back(person(j,i,0,false));
                    f[i][j] = cnt++;
                }else if(tmp == 'N'){
                    ps.push_back(person(j,i,1,false));
                    f[i][j] = cnt++;
                }else if(tmp == 'W'){
                    ps.push_back(person(j,i,2,false));
                    f[i][j] = cnt++;
                }else{
                    ps.push_back(person(j,i,3,false));
                    f[i][j] = cnt++;
                }
            }
        }

        int res=0;
        bool isended;
        bool moved[(int)ps.size()];
        vector<pair<int,int> > inst;
        for(;;){
            memset(moved, false, sizeof(moved));
            //pr();
            isended = true;
            for(int j=0;j<16;j++){
                for(int i=0;i<(int)ps.size();i++){
                    if(ps[i].exit == false){
                        isended = false;
                        if(ps[i].dir == dir[j] && moved[i] == false){
                            int nx = ps[i].x + dx[ndir[j]];
                            int ny = ps[i].y + dy[ndir[j]];
                            if(f[ny][nx] == -1) continue;
                            //cout << i << ":" << ny << " " << nx << " " << f[ny][nx] << endl;
                            if(f[ny][nx] == 1){
                                //cout << "evac" << endl;
                                ps[i].exit = true;
                                f[ps[i].y][ps[i].x] = -2;
                                moved[i] = true;
                                inst.push_back(make_pair(ps[i].y,ps[i].x));
                            }else if(f[ny][nx] == 0){
                                //cout << "move" << endl;
                                f[ps[i].y][ps[i].x] = -2;
                                inst.push_back(make_pair(ps[i].y,ps[i].x));
                                ps[i].x = nx;
                                ps[i].y = ny;
                                ps[i].dir = ndir[j];
                                f[ny][nx] = i+2;
                                //cout << ny << " " << nx << endl;
                                moved[i] = true;                         
                            }else if(f[ny][nx] >= 2 && moved[f[ny][nx]-2] == true){
                                //cout << moved[f[ny][nx]-2] << endl;
                                moved[i] = true;
                            }
                        }
                    }
                }
            }
            for(int i=0;i<(int)inst.size();i++){
                f[inst[i].first][inst[i].second] = 0;
            }
            inst.clear();
            //int hoge;
            //cin >> hoge;
            if(isended || res > 200) break;
            res++;
        }
        if(res >= 180){
            cout << "NA" << endl;
        }else{
            cout << res << endl;
        }
    }
}
