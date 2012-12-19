#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
pair<double, vector<int> > dp[15][1 << 15];
int iton[15];
int x[15];
int w[15];
int n;

#define INF 1e+20

pair<double, vector<int> > solve(int state, int pos, int weight){
    if(dp[pos][state].first != INF) return dp[pos][state];
    pair<double, vector<int> > ret(0, vector<int>()),tmp;
    ret.second.push_back(iton[pos]);

    if(state == (1<<n)-1) return ret;

    ret.first = INF;
    for(int i=0;i<n;i++){
        if((state & (1 << i)) == 0){
            tmp = solve(state|(1<<i),i,weight+w[i]);
            tmp.first += abs(x[pos] - x[i]) / (2000.0 / (70+weight));
            if(ret.first > tmp.first){
                ret = tmp;
            }
        }
    }

    ret.second.push_back(iton[pos]);
    return dp[pos][state] = ret;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> iton[i] >> x[i] >> w[i];
        w[i] *= 20;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<n);j++){
            dp[i][j] = pair<double, vector<int> >(INF,vector<int>());
        }
    }

    pair<double, vector<int> > ret(INF, vector<int>()), tmp;
    for(int i=0;i<n;i++){
        tmp = solve(1 << i, i, w[i]);
        if(tmp.first < ret.first){
            ret = tmp;
        }
    }
    reverse(ret.second.begin(), ret.second.end());

    for(int i=0;i<ret.second.size()-1;i++){
        cout << ret.second[i] << " ";
    }
    cout << ret.second.back() << endl;
    return 0;
}
