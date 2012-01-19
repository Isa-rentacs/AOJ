#include <iostream>
#include <string>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int w,h;
    while(cin >> w >> h){
        if((w|h) == 0) break;
        string str;
        int n;
        int dir = 1;
        int x = 1;
        int y = 1;
        while(cin >> str){
            if(str == "STOP"){
                break;
            }else if(str == "RIGHT"){
                dir--;
                if(dir == -1) dir = 3;
            }else if(str == "LEFT"){
                dir++;
                if(dir == 4) dir = 0;
            }else{
                if(str == "FORWARD"){
                    cin >> n;
                }else{
                    cin >> n;
                    n *= -1;
                }
                x += dx[dir] * n;
                y += dy[dir] * n;
                if(x < 1) x = 1;
                if(x > w) x = w;
                if(y < 1) y = 1;
                if(y > h) y = h;
            }
        }
        cout << x << " " << y << endl;
    }
}
