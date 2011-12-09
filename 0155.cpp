#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdio>

#define INF 1 << 28
#define EPS 1e-5

using namespace std;

typedef double Weight; 

struct Edge{
    int src;
    int dst;
    Weight weight;

    Edge(int src, int dst, Weight weight):
        src(src), dst(dst), weight(weight){ }
};

struct Node{
    int index;
    int cost;
    int prev;

    Node(int index, int cost, int prev) :
        index(index), cost(cost), prev(prev){ }
};

bool operator <(const Node &a, const Node &b){
    if(a.cost == b.cost){
        return a.index > b.index;
    }else{
        return a.cost > b.cost;
    }
}

void dijkstra(int s, vector<int> &costs, vector<int> &prev, vector<vector<Edge> > &edges){
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

vector<int> createpath(vector<int> &prev, int e){
    vector<int> ret;
    int pos = e;
    while(1){
        ret.push_back(pos);
        pos = prev[pos];
        if(pos == -2){
            reverse(ret.begin(),ret.end());
            return ret;
        }
    }
}

struct building{
    int index;
    int x;
    int y;
    
    building(int index, int x, int y):
        index(index), x(x), y(y){}
};

int main(){
    int n;
    while(cin >> n && n){
        vector<vector<Edge> > edges(n);
        vector<int> cost(n);
        vector<int> prev(n);
        vector<int> name(n);
        vector<building> b;
        vector<int> ans;
        double dist;
        int m;
        int src,dst;
        int index,x,y;

        for(int i=0;i<n;i++){
            cin >> name[i] >> x >> y;
            b.push_back(building(i,x,y));
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                dist = sqrt(pow(b[i].x - b[j].x,2) + pow(b[i].y - b[j].y, 2));
                if(dist <= 50.0){
                    edges[i].push_back(Edge(i,j,dist));
                    edges[j].push_back(Edge(j,i,dist));
                }
            }
        }
        
        cin >> m;
        for(int i=0;i<m;i++){
            int srcname,dstname;
            cin >> srcname >> dstname;
            for(int i=0;i<n;i++){
                if(name[i] == srcname){
                    src = i;
                }
                if(name[i] == dstname){
                    dst = i;
                }
            }
            dijkstra(src, cost, prev, edges);
            if(cost[dst] == INF){
                cout << "NA" << endl;
            }else{
                ans = createpath(prev,dst);
                for(int j=0;j<ans.size()-1;j++){
                    cout << name[ans[j]] << " ";
                }
                cout << name[ans.back()] << endl;
            }
        }
    }
}
