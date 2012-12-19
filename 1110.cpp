#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};
map<vector<int>,int> m;
void remove(vector<int> &v, int a1, int a2){
    if(a1 > a2) swap(a1,a2);
    v.erase(v.begin()+a1);
    v.erase(v.begin()+a2-1);
}

void pr(vector<int> &f){
    for(int i=0;i<f.size();i++){
        cout << f[i];
        if(i%4 == 3) cout << endl;
    }
    cout << endl << endl;
}

int solve(vector<int> f){
    if(m.find(f) != m.end()) return m[f];
    vector<int> back;
    bool ended = true;
    int ret = 1 << 29;
    for(int i=0;i<f.size();i++){
        int x = i%4, y = i/4;
        for(int j=0;j<8;j++){
            int nx = x + dx[j];
            int ny = y + dy[j];

            if(!(0 <= nx && nx < 4 && 0 <= ny && ny < 5)){
                continue;
            }else{
                int ind = nx + ny*4;
                if(ind >= f.size()){
                    continue;
                }else if(f[ind] == f[i]){
                    ended = false;
                    back = f;
                    remove(f,i,ind);
                    ret = min(ret,solve(f));
                    f = back;
                }
            }
        }
    }
    if(ended){
        ret = min(ret, (int)f.size());
    }
    return m[f] = ret;
}

int main(){
    int n;
    vector<int> init(20);
    cin >> n;
    for(int i=0;i<n;i++){
        m.clear();
        for(int j=0;j<20;j++){
            cin >> init[j];
        }
        cout << solve(init) << endl;
    }
}
