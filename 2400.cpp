#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

struct team{
    int num;
    int ac;
    int pen;

    bool operator<(const team &arg) const{
        if(ac != arg.ac){
            return ac > arg.ac;
        }else if(pen != arg.pen){
            return pen < arg.pen;
        }else{
            return num < arg.num;
        }
    }

    team(int _n, int _ac, int _pen):num(_n),ac(_ac),pen(_pen){}

};

int main(){
    int t,p,r;

    while(cin >> t >> p >> r){
        if((t|p|r) == 0) break;
        vector<team> teams;
        int wa_cnt[t+1][p+1];
        bool aced[t+1][p+1];
        int tid,pid,time;
        string mes;

        memset(wa_cnt, 0, sizeof(wa_cnt));
        memset(aced, 0, sizeof(aced));


        for(int i=0;i<t;i++){
            teams.push_back(team(i+1,0,0));
        }

        for(int i=0;i<r;i++){
            cin >> tid >> pid >> time >> mes;
            if(aced[tid][pid]) continue;

            if(mes == "CORRECT"){
                teams[tid-1].ac++;
                teams[tid-1].pen += wa_cnt[tid][pid] * 1200 + time;
                aced[tid][pid] = true;
            }else{
                wa_cnt[tid][pid]++;
            }
        }
        sort(teams.begin(), teams.end());
        for(int i=0;i<t;i++){
            cout << teams[i].num << " " << teams[i].ac << " " << teams[i].pen << endl;
        }
    }
}
