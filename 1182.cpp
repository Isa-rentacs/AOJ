#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cassert>
#include <cstdio>

#define INF 1<<29

using namespace std;

int n,m,c,s,g;
int comp, dist, src, dst, tmp;

class edge{
public:
    int dst;
    int dist;

    edge(int _dst, int _dist):dst(_dst),dist(_dist){}
};

class state{
public:
    int pos;
    int last_comp;
    int dist;  //max 100*200
    int cost;  //max 100*200*100

    state(){}
    state(int a, int b, int c, int d):pos(a), last_comp(b), dist(c), cost(d){}

    bool operator<(const state &arg) const{
        if(cost != arg.cost){
            return cost > arg.cost;
        }else{
            return pos > arg.pos;
        }
    }
};

vector<edge> edges[101][21]; //edges[i][j] := i番目の駅から出ているj番目の会社の道
int p[21];
vector<int> q[21], r[21]; //q:=折れ目,
int res[101];

void initialize(){
    for(int i=0;i<101;i++){
        for(int j=0;j<21;j++){
            edges[i][j].clear();
        }
    }
    for(int i=0;i<21;i++){
        q[i].clear();
        r[i].clear();
    }
}

int calc_price(int comp, int dist){
    int ret = 0;
    if(dist == 0) return 0;
    for(int i=1;i<(int)q[comp].size();i++){
        if(q[comp][i-1] < dist && dist <= q[comp][i]){
            ret += (dist - q[comp][i-1]) * r[comp][i-1];
            break;
        }else{
            ret += (q[comp][i] - q[comp][i-1]) * r[comp][i-1];
        }
    }
    //cerr << "company = " << comp << " ,distance = " << dist << " :price = " << ret << endl; 
    return ret;
}

void bfs(){
    priority_queue<state> q;
    state st;
    int price,price2,price3;
    fill(res, res+101, INF);
    res[s] = 0;
    q.push(state(s,-1,0,0));

    while(!q.empty()){
        st = q.top();
        q.pop();
        
        //printf("current:pos = %d, comp = %d, dist = %d, cost = %d\n", st.pos, st.last_comp, st.dist, st.cost);
        if(st.pos == g){
            res[g] = min(res[g], st.cost);
            //cerr << "UPDATED GOAL:" << res[g] << endl; 
            //continue;
            return;
        }

        //現在地点から出ているedgeを全て舐める
        for(int i=0;i<c;i++){
            for(int j=0;j<(int)edges[st.pos][i].size();j++){
                if(st.last_comp == -1 || st.last_comp == i){
                    //同じcompany、あるいは始めなら距離を加えるだけ
                    price = calc_price(i, st.dist + edges[st.pos][i][j].dist);
                    price2 = calc_price(i, st.dist);
                    if(st.cost + price - price2 <= res[edges[st.pos][i][j].dst]){
                        //cerr << "pushed" << endl;
                        res[edges[st.pos][i][j].dst] = st.cost + price - price2;
                        q.push(state(edges[st.pos][i][j].dst,
                                     i,
                                     st.dist + edges[st.pos][i][j].dist,
                                     st.cost + price - price2));
                    }
                }else{
                    //違う会社であればそこまでの運賃を計算した上で積む+枝狩り
                    price = calc_price(i,edges[st.pos][i][j].dist);
                    if(st.cost + price <= res[edges[st.pos][i][j].dst]){
                        //cerr << "pushed" << endl;
                        //res[edges[st.pos][i][j].dst] = st.cost + price;
                        res[edges[st.pos][i][j].dst] = st.cost + price;
                        q.push(state(edges[st.pos][i][j].dst, 
                                     i, 
                                     edges[st.pos][i][j].dist, 
                                     st.cost + price));
                    }
                }
            }
        }
    }
    
}


int main(){
    while(cin >> n >> m >> c >> s >> g){
        if((n|m|c|s|g) == 0) break;
        s--; g--;
        initialize();
        for(int i=0;i<m;i++){
            cin >> src >> dst >> dist >> comp;
            edges[src-1][comp-1].push_back(edge(dst-1,dist));
            edges[dst-1][comp-1].push_back(edge(src-1,dist));
        }
        
        for(int i=0;i<c;i++){
            cin >> p[i];
        }

        for(int i=0;i<c;i++){
            q[i].push_back(0);
            for(int j=0;j<p[i]-1;j++){
                cin >> tmp;
                q[i].push_back(tmp);
            }
            q[i].push_back(INF); //番兵
            for(int j=0;j<p[i];j++){
                cin >> tmp;
                r[i].push_back(tmp);
            }
        }
        bfs();
        if(res[g] == INF) res[g] = -1;
        cout << res[g] << endl;
    }
}
