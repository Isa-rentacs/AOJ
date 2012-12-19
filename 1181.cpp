#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class DICE{
    /*
     * top = 0, right = 1, up = 2, left = 3, down = 4, bottom = 5; 
     */
public:
    DICE(int a, int b, int c, int d, int e, int f){
        v[0] = a;
        v[1] = b;
        v[2] = c;
        v[3] = d;
        v[4] = e;
        v[5] = f;
    }

    DICE(int a, int b, int c){
        v[0] = a;
        v[1] = b;
        v[2] = c;
        v[3] = 7-b;
        v[4] = 7-c;
        v[5] = 7-a;
    }

    DICE(){};
    int v[6];

    void rotate(int arg){
        int tmp=v[0];
        if(arg == 0){
            //North
            v[0] = v[4];
            v[4] = v[5];
            v[5] = v[2];
            v[2] = tmp;
        }else if(arg == 1){
            //East
            v[0] = v[3];
            v[3] = v[5];
            v[5] = v[1];
            v[1] = tmp;
        }else if(arg == 2){
            //West
            v[0] = v[1];
            v[1] = v[5];
            v[5] = v[3];
            v[3] = tmp;
        }else if(arg == 3){
            //South
            v[0] = v[2];
            v[2] = v[5];
            v[5] = v[4];
            v[4] = tmp;
        }else if(arg == 4){
            //right
            tmp = v[4];
            v[4] = v[1];
            v[1] = v[2];
            v[2] = v[3];
            v[3] = tmp;
        }else{
            tmp = v[4];
            v[4] = v[3];
            v[3] = v[2];
            v[2] = v[1];
            v[1] = tmp;
        }
    }

    int top(void){
        return v[0];
    }

    int bottom(void){
        return v[5];
    }
};

int height[300][300];
int table[300][300];

int main(){
    int n,t,f,r;
    DICE d = DICE();
    int x,y;
    while(cin >> n && n){
        memset(table,0,sizeof(table));
        memset(height,0,sizeof(height));
        int res[7] = {0,0,0,0,0,0,0};
        for(int i=0;i<n;i++){
            cin >> t >> f;
            x = 150;
            y = 150;

            if(t == 1){
                switch(f){
                case 3:
                    r = 5;
                    break;
                case 5:
                    r = 4;
                    break;
                case 4:
                    r = 2;
                    break;
                case 2:
                    r = 3;
                    break;
                }
            }else if(t == 2){
                switch(f){
                case 3:
                    r = 1;
                    break;
                case 1:
                    r = 4;
                    break;
                case 4:
                    r = 6;
                    break;
                case 6:
                    r = 3;
                    break;
                }
            }else if(t == 3){
                switch(f){
                case 5:
                    r = 1;
                    break;
                case 1:
                    r = 2;
                    break;
                case 2:
                    r = 6;
                    break;
                case 6:
                    r = 5;
                    break;
                }
            }else if(t == 4){
                switch(f){
                case 2:
                    r = 1;
                    break;
                case 1:
                    r = 5;
                    break;
                case 5:
                    r = 6;
                    break;
                case 6:
                    r = 2;
                    break;
                }
            }else if(t == 5){
                switch(f){
                case 4:
                    r = 1;
                    break;
                case 1:
                    r = 3;
                    break;
                case 3:
                    r = 6;
                    break;
                case 6:
                    r = 4;
                    break;
                }
            }else if(t == 6){
                switch(f){
                case 4:
                    r = 5;
                    break;
                case 5:
                    r = 3;
                    break;
                case 3:
                    r = 2;
                    break;
                case 2:
                    r = 4;
                    break;
                }
            }
            d = DICE(t,r,7-f);
            while(height[y][x] != 0){
                //転がる方向を探す
                int tmp = 0;
                int dir;
                int nx,ny;
                for(int j=1;j<=4;j++){
                    if(j == 1){
                        ny = y;
                        nx = x + 1;
                    }else if(j == 2){
                        ny = y + 1;
                        nx = x;
                    }else if(j == 3){
                        ny = y;
                        nx = x - 1;
                    }else{
                        ny = y - 1;
                        nx = x;
                    }
                    if(4 <= d.v[j] && tmp < d.v[j] && height[ny][nx] < height[y][x]){
                        dir = j;
                        tmp = d.v[j];
                    }
                }
                //転がらない
                if(tmp == 0) break;
                //cerr << "rotate to dir " << dir << " # of eye is " << d.v[dir] << endl;
                //転がる
                if(dir == 1){
                    x++;
                    d.rotate(1);
                }else if(dir == 2){
                    y++;
                    d.rotate(0);
                }else if(dir == 3){
                    x--;
                    d.rotate(2);
                }else{
                    y--;
                    d.rotate(3);
                }
            }
            height[y][x]++;
            if(table[y][x] != 0){
                res[table[y][x]]--;
            }
            table[y][x] = d.top();
            res[d.top()]++;

            //cerr << "dice #" << i+1 << " stopped at ( " << y << ", " << x << "), top = " << d.top() << endl;
        }
        for(int i=1;i<=6;i++){
            cout << res[i];
            if(i!=6){
                cout << " ";
            }
        }
        cout << endl;
    }
}
