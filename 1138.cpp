#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstring>
#include <queue>

using namespace std;

#define INF 1e+9

class state{
public:
    float cost;
    unsigned char  used;
    unsigned char  node;

    state(float _c, unsigned char _u, unsigned char _n):cost(_c), used(_u), node(_n){}
    state(){}
    bool operator <(const state &arg) const{
         if(cost != arg.cost){
             return cost > arg.cost;
         }
         return node > arg.node;
     }
 };

int n,m,p,a,b;
int t[9];
float d[31][31];
float dd[513][31];
priority_queue<state> q;

void solve(){
    state st;
    bool visited[513][m];
    
    memset(visited, false, sizeof(visited));
    q.push(state(.0,0,a));

    while(!q.empty()){
        st = q.top();
        q.pop();
        if(st.cost > dd[st.used][st.node]) continue;
        if(st.node == b) break;
        for(int i=0;i<m;i++){
            if(d[st.node][i] != INF){
                for(int j=0;j<n;j++){
                    if((st.used & (1 << j)) == 0 &&  
                       st.cost + (double)d[st.node][i] / t[j] < dd[st.used | (1 << j)][i]){
                        dd[st.used | (1 << j)][i] = st.cost + (double)d[st.node][i] / t[j];
                        q.push(state(st.cost + (double)d[st.node][i] / t[j], st.used | (1 << j), i));
                    }
                }
            }
        }
    }
}

int main(){
    while(cin >> n >> m >> p >> a >> b){
        int src,dst,cost;
        q = priority_queue<state>();
        if((n | m | p | a | b) == 0) break;
        fill((float *)d, (float *)d+31*31, INF);
        fill((float *)dd, (float *)dd+513*31, INF);
        
        a--;
        b--;
        for(int i=0;i<n;i++){
            cin >> t[i];
        }
        for(int i=0;i<p;i++){
            cin >> src >> dst >> cost;
            d[src-1][dst-1] = cost;
            d[dst-1][src-1] = cost;
        }
        solve();
        
        float ret = INF;
        for(int i=0;i<513;i++){
            ret = min(ret, dd[i][b]);
        }
        if(ret == INF){
            cout << "Impossible" << endl;
        }else{
            cout << ret << endl;
        }
    }
}
