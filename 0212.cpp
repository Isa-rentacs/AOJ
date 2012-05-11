#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

#define INF 1 << 29

using namespace std;

int c,n,m,s,d;
int cost[101][101];

class S{
public:
    int node;
    int tick;
    int cost;

    S(int node,int tick,int cost):
        node(node),tick(tick),cost(cost){}
    S(){}
    bool operator <(const S arg) const{
        return cost > arg.cost;
    }
};

int dijkstra(int src,int dst){
    priority_queue<S> q;
    int memo[n+1][c+1];
    S tmp;
    fill((int *)memo, (int *)memo+(n+1)*(c+1), INF);
    memo[src][c] = 0;
    q.push(S(src,c,0));

    while(!q.empty()){
        tmp = q.top();
        q.pop();
        for(int i=0;i<=n;i++){
            if(cost[tmp.node][i] != INF){
                if(cost[tmp.node][i] + tmp.cost < memo[i][tmp.tick]){
                    q.push(S(i,tmp.tick,cost[tmp.node][i] + tmp.cost));
                    memo[i][tmp.tick] = cost[tmp.node][i] + tmp.cost;
                }
                if(tmp.tick && cost[tmp.node][i]/2 + tmp.cost < memo[i][tmp.tick-1]){
                    q.push(S(i,tmp.tick-1,cost[tmp.node][i]/2 + tmp.cost));
                    memo[i][tmp.tick-1] = cost[tmp.node][i]/2 + tmp.cost;
                }
            }
        }
    }
    int ret = 1<<29;
    for(int i=0;i<=c;i++){
        ret = min(ret, memo[dst][i]);
    }
    return ret;
}

int main(){
    while(cin >> c >> n >> m >> s >> d){
        if((c|n|m|s|d) == 0) break;
        int src,dst,c;
        fill((int *)cost, (int *)cost+101*101, INF);
        for(int i=0;i<m;i++){
            cin >> src >> dst >> c;
            cost[src][dst] = c;
            cost[dst][src] = c;
        }

        cout << dijkstra(s,d) << endl;
    }
}
