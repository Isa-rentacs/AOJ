#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    int n,k,v,p,tmp,tmp2;
    vector<pair<int,int> > vs;
    cin >> n >> k;
    vector<int> bs[n];
    bool bad[n+1];
    memset(bad, false, sizeof(bad));
    for(int i=0;i<k;i++){
        cin >> v;
        for(int j=0;j<v;j++){
            cin >> tmp;
            bs[i].push_back(tmp);
        }
    }
    cin >> p;
    for(int i=0;i<p;i++){
        cin >> tmp >> tmp2;
        vs.push_back(make_pair(tmp,tmp2));
    }

    for(int i=0;i<k;i++){
        for(int j=0;j<(int)bs[i].size();j++){
            for(int k=j+1;k<(int)bs[i].size();k++){
                for(int l=0;l<(int)vs.size();l++){
                    if((bs[i][j] == vs[l].first && bs[i][k] == vs[l].second) ||
                       (bs[i][j] == vs[l].second && bs[i][k] == vs[l].first)){
                        bad[bs[i][j]] = true;
                        bad[bs[i][k]] = true;
                    }
                }
            }
        }
    }
    int ret = 0;
    for(int i=0;i<=n;i++){
        if(bad[i]) ret++;
    }
    cout << ret << endl;
}
