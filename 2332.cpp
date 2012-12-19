#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define INF 1<<29

typedef int Weight; 

struct Edge{
    int src;
    int dst;
    Weight weight;

    Edge(int src, int dst, Weight weight):
        src(src), dst(dst), weight(weight){ }
};

struct Node{
    int index;
    Weight cost;
    int prev;

    Node(int index, Weight cost, int prev) :
        index(index), cost(cost), prev(prev){ }
};

bool operator <(const Node &a, const Node &b){
    if(a.cost == b.cost){
        return a.index > b.index;
    }else{
        return a.cost > b.cost;
    }
}

void dijkstra(int s, vector<Weight> &costs, vector<int> &prev, vector<vector<Edge> > &edges){
    int n=costs.size();
    priority_queue<Node> q;

    costs.assign(n,INF);
    prev.assign(n,-1);
    costs[s] = 0;
    q.push(Node(s,0,-2));

    while(!q.empty()){
        Node fix = q.top(); 
        q.pop();
        if(prev[fix.index] != -1) continue;
       
        costs[fix.index] = fix.cost;
        prev[fix.index] = fix.prev;

        for(int i=0;i<edges[fix.index].size();i++){ //foreach edge from fixed
            if(costs[edges[fix.index][i].dst] > costs[fix.index] + edges[fix.index][i].weight){
                q.push(Node(edges[fix.index][i].dst, edges[fix.index][i].weight + costs[fix.index], fix.index));
            }
        }
    }
}

int main(){
    int n,tmp;
    cin >> n;
    vector<Weight> costs(n);
    vector<int> prev(n);
    vector<vector<Edge> > edges(n);

    for(int i=0;i<n;i++){
        cin >> tmp;
        if(tmp == 0){
            for(int j=1;j<=6;j++){
                edges[i].push_back(Edge(i,min(n-1,i+j),1));
            }
        }else{
            edges[i].push_back(Edge(i,min(n-1,i+tmp),0));
        }
    }
    dijkstra(0,costs,prev,edges);
    cout << costs[n-1] << endl;
}
