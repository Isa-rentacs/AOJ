#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int p,n[6],m[6]={1,5,10,50,100,500};
int change[1000000];

int cntchange(int arg){
    if(change[arg] != -1) return change[arg];
    int origin = arg, ret = 0, tmp;
    for(int i=5;i>=0;--i){
        tmp = arg / m[i];
        arg -= tmp * m[i];
        ret += tmp;
    }
    return change[origin] = ret; 
}

int possible(int arg){
    int ret=0, tmp;
    for(int i=5;i>=0;--i){
        tmp = arg / m[i];
        tmp = min(tmp, n[i]);
        arg -= tmp * m[i];
        ret += tmp;
    }

    return arg==0?ret:-1;
}

int main(){
    int sum;
    memset(change, -1, sizeof(change));
    while(cin >> p && p){
        int ub = 0;
        for(int i=0;i<6;++i){
            cin >> n[i];
            ub += n[i] * m[i];
        }

        int ret = 1 << 20;
        for(int i=p;i<=ub;++i){
            int pay;
            pay = possible(i);
            if(pay != -1){
                ret = min(ret, pay+cntchange(i-p));
            }
        }
        cout << ret << endl;
    }
}
