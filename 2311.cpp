#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int main(){
    int turn=0;
    int b[10][10];
    char c;
    memset(b, -1, sizeof(b));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin >> c;
            if(c == 'o'){
                b[i+1][j+1] = 0;
            }else if(c == 'x'){
                b[i+1][j+1] = 1;
            }
        }
    }

    int cx,cy;
    int px,py;
    int prevnum=1,num,_num,tmp;
    vector<int> dir,tmpdir;
    while(1){
        dir.clear();
        num = 0;
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                _num = 0;
                if(!turn){
                    cx = j;
                    cy = i;
                }else{
                    cx = 9-j;
                    cy = 9-i;
                }
                if(b[cy][cx] == -1){
                    //foreach direction
                    for(int k=0;k<8;k++){
                        tmp=1;
                        if(b[cy+dy[k]][cx+dx[k]] == turn ||
                           b[cy+dy[k]][cx+dx[k]] == -1){
                            //隣が空もしくは同色ならcontinue
                            continue;
                        }
                        while(b[cy+dy[k]*tmp][cx+dx[k]*tmp] == 1-turn){
                            tmp++;
                        }
                        if(b[cy+dy[k]*tmp][cx+dx[k]*tmp] == turn){
                            _num += tmp-1;
                            tmpdir.push_back(k);
                        }
                    }
                }
                if(num < _num){
                    num = _num;
                    px = cx;
                    py = cy;
                    dir = tmpdir;
                }
                tmpdir.clear();
            }
        }

        //置く
        if(dir.size()) b[py][px] = turn;
        for(int i=0;i<dir.size();i++){
            tmp = 1;
            while(b[py+dy[dir[i]]*tmp][px+dx[dir[i]]*tmp] != turn){
                b[py+dy[dir[i]]*tmp][px+dx[dir[i]]*tmp] = turn;
                tmp++;
            }
        }
        if(!prevnum && !num) break;        
        prevnum = num;
        turn = 1 - turn;
    }
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            if(b[i][j] == 0){
                cout << 'o';
            }else if(b[i][j] == 1){
                cout << 'x';
            }else{
                cout << '.';
            }
        }
        cout << endl;
    }
}
