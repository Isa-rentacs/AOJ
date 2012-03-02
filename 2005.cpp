#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 1e+9
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define int long long

using namespace std;

main(){
    int n,m,s,g1,g2;

    while(cin >> n >> m >> s >> g1 >> g2){
        if((n|m|s|g1|g2) == 0) break;
        int cost[n][n];
        int ret = 1e+18;
        int src,dst,c;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cost[i][j] = INF;
            }
        }

        for(int i=0;i<n;i++) cost[i][i] = 0;

        //load roads lol
        for(int i=0;i<m;i++){
            cin >> src >> dst >> c;
            cost[src-1][dst-1] = c;
        }

        //WF
        for(int r=0;r<n;r++){
            for(int p=0;p<n;p++){
                for(int q=0;q<n;q++){
                    cost[p][q] = min(cost[p][q], cost[p][r] + cost[r][q]);
                }
            }
        }

        for(int i=0;i<n;i++){
            ret = min(ret, cost[s-1][i] + cost[i][g1-1] + cost[i][g2-1]);
        }
        cout << ret << endl;
    }
}
