#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1 << 28

int main(){
    int n,k,kind,src,dst,tmp,c;

    while(cin >> n >> k){
        if(!(n|k)) break;
        int cost[n][n];
        fill((int *)cost, (int *)cost+n*n, INF);

        for(int i=0;i<k;i++){
            cin >> kind;
            if(kind == 0){
                cin >> src >> dst;
                if(cost[src-1][dst-1] == INF){
                    cout << -1 << endl;
                }else{
                    cout << cost[src-1][dst-1] << endl;
                }
            }else{
                cin >> src >> dst >> c;
                tmp = min(cost[src-1][dst-1], c);
                cost[src-1][dst-1] = tmp;
                cost[dst-1][src-1] = tmp;
                for(int r=0;r<n;r++){
                    for(int p=0;p<n;p++){
                        for(int q=0;q<n;q++){
                            cost[p][q] = min(cost[p][q], cost[p][r] + cost[r][q]);
                        }
                    }
                }
            }
        }
    }
}
