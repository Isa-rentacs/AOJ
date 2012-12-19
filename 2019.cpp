#include <iostream>
#include <algorithm>

using namespace std;

bool pred(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}

int main(){
    int n,m;
    while(cin >> n >> m){
        if((n|m) == 0) break;

        pair<int,int> seg[n];

        for(int i=0;i<n;i++){
            cin >> seg[i].second >> seg[i].first;
        }
        sort(seg, seg+n, pred);

        int ret=0;
        for(int i=0;i<n;i++){
            if(m > 0){
                if(seg[i].second > m){
                    ret += (seg[i].second - m) * seg[i].first;
                    m = 0;
                }else{
                    m -= seg[i].second;
                }
            }else{
                ret += seg[i].second * seg[i].first;
            }
        }
        cout << ret << endl;
    }
}
