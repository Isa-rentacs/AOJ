#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int log[10001][1261];
int state[1001];

int main(){
    int n,m,r,q;

    while(cin >> n >> m){
        if((n|m) == 0) break;
        memset(log, -1, sizeof(log));
        memset(state, -1, sizeof(state));
        cin >> r;
        
        int t, _n, _m, s, ts, te, mq, tmp;
        for(int i=0;i<r;i++){
            cin >> t >> _n >> _m >> s;
            if(s){//login
                state[_n] = t;
            }else{//logout
                for(int j=state[_n];j<=t;j++){
                    log[_m][j] = t;
                }
            }
        }

        cin >> q;
        int ret;
        for(int i=0;i<q;i++){
            ret = 0;
            cin >> ts >> te >> mq;
            tmp = ts;
            while(tmp < te){
                if(log[mq][tmp] != -1 && tmp != log[mq][tmp]){
                    ret += min(te, log[mq][tmp]) - tmp;
                    tmp = min(te, log[mq][tmp]);
                }else{
                    tmp++;
                }
            }
            cout << ret << endl;
        }
    }
}
