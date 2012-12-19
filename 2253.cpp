#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//[-60,60] -> [0,120]
int f[121][121];

int dx[6] = {1,1,0,-1,-1,0};
int dy[6] = {0,1,1,0,-1,-1};

int main(){
    int t,n;
    
    while(cin >> t >> n){
        if((t|n) == 0) break;
        memset(f,0,sizeof(f));
        int x,y;
        vector<pair<int,int> > diff;

        for(int i=0;i<n;i++){
            cin >> x >> y;
            f[x+60][y+60] = -1;
        }

        cin >> x >> y;
        x += 60;
        y += 60;
        f[x][y] = 1;
        
        for(int i=0;i<t;i++){
            for(int p=0;p<121;p++){
                for(int q=0;q<121;q++){
                    if(f[p][q] == 1){
                        for(int k=0;k<6;k++){
                            x = p + dx[k];
                            y = q + dy[k];

                            if(0 <= x && x < 121 &&
                               0 <= y && y < 121 &&
                                f[x][y] != -1){
                                diff.push_back(make_pair(x,y));
                            }
                        }
                    }
                }
            }
            for(int j=0;j<diff.size();j++){
                f[diff[j].first][diff[j].second] = 1;
            }
            diff.clear();
        }
        int ret = 0;

        for(int i=0;i<121;i++){
            for(int j=0;j<121;j++){
                if(f[i][j] == 1) ret++;
            }
        }
        cout << ret << endl;
    }
}
