#include <iostream>

using namespace std;

int main(){
    int x,y,w,h,n;
    int xx,yy;
    int cases;
    cin >> cases;

    for(int c=0;c<cases;++c){
        int ret=0;
        cin >> x >> y >> w >> h >> n;
        for(int i=0;i<n;i++){
            cin >> xx >> yy;
            if(x <= xx && xx <= x+w &&
               y <= yy && yy <= y+h){
                ret++;
            }
        }
        cout << ret << endl;
    }
}
