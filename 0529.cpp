#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        if((n|m) == 0) break;

        int p[n+1];
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        p[n] = 0;
        vector<int> d;
        for(int i=0;i<n+1;i++){
            for(int j=i;j<n+1;j++){
                d.push_back(p[i]+p[j]);
            }
        }
        sort(d.begin(),d.end());

        int ret=0;
        for(int i=0;i<d.size();i++){
            if(d[i] > m) continue;
            ret = max(ret, d[i] + *(upper_bound(d.begin(), d.end(), m-d[i])-1));
        }
        cout << ret << endl;
    }
}
