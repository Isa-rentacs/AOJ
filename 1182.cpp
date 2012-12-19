#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

#define INF 1<<29

using namespace std;

int n,m,c,s,g;
int lines[21][101][101];
int edges[101][101];
int visited[101];
int p[21];
vector<int> q[21], r[21];
int cost[21][20050];

class state{
public:
    int pos;
    int cost;
    
    state(){}
    state(int _p, int _c):pos(_p), cost(_c){}

    bool operator <(const state &arg) const{
        return cost > arg.cost;
    }
};

void calc_price(){
    int index = 0;
    for(int i=0;i<c;i++){
        index = 0;
        cost[i][0] = 0;
        for(int j=1;j<20050;j++){
            cost[i][j] = cost[i][j-1] + r[i][index];
            if(index < (int)q[i].size() && j == q[i][index]){
                index++;
            }
        }
    }
}

int main(){
    while(cin >> n >> m >> c >> s >> g){
        int x,y,d,co,tmp;
        if((n|m|c|s|g) == 0) break;
        s--; g--;
        fill((int *)lines, (int *)lines+21*101*101, INF);
        fill((int *)edges, (int *)edges+101*101, INF);
        fill((int *)visited, (int *)visited+101, INF);
        fill((int *)cost, (int *)cost+21*20050, INF);
        for(int i=0;i<21;i++){
            q[i].clear();
            r[i].clear();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<c;j++){
                lines[j][i][i] = 0;
            }
        }
        for(int i=0;i<m;i++){
            cin >> x >> y >> d >> co;
            lines[co-1][x-1][y-1] = min(lines[co-1][x-1][y-1], d);
            lines[co-1][y-1][x-1] = min(lines[co-1][y-1][x-1], d);
        }

        for(int i=0;i<c;i++){
            cin >> p[i];
        }
        for(int i=0;i<c;i++){
            for(int j=0;j<p[i]-1;j++){
                cin >> tmp;
                q[i].push_back(tmp);
            }
            for(int j=0;j<p[i];j++){
                cin >> tmp;
                r[i].push_back(tmp);
            }
        }
        calc_price();

        //WF
        for(int i=0;i<c;i++){
            for(int k=0;k<n;k++){
                for(int p=0;p<n;p++){
                    for(int q=0;q<n;q++){
                        lines[i][p][q] = min(lines[i][p][q],
                                                lines[i][p][k] +
                                                lines[i][k][q]);
                    }
                }
            }
        }

        //pick the least cost
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<c;k++){
                    if(lines[k][i][j] != INF){
                        edges[i][j] = min(edges[i][j], cost[k][lines[k][i][j]]);
                    }
                }
            }
        }

        priority_queue<state> q;
        state st;

        q.push(state(s,0));
        visited[s] = 0;
        while(!q.empty()){
            st = q.top();
            q.pop();

            if(st.pos == g){
                break;
            }
            
            for(int i=0;i<n;i++){
                tmp = st.cost + edges[st.pos][i];
                if(tmp < visited[i]){
                    visited[i] = tmp;
                    q.push(state(i, visited[i]));
                }
            }
            
        }
        if(visited[g] == INF){
            cout << -1 << endl;
        }else{
            cout << visited[g] << endl;
        }
    }
}
