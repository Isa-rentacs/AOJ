#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define EPS 1e-9

using namespace std;

int n;
double W;

bool pred(pair<int,int> a, pair<int,int> b){
    return a.first * b.second > a.second * b.first;
}

int main(){
    cin >> n >> W;
    vector<pair<int,int> > vp;
    double ret=0;
    double w,v;
    for(int i=0;i<n;i++){
        cin >> w >> v;
        if(w <= 0 && v >= 0){
            W -= w;
            ret += v;
        }else if(w >=0 && v <= 0){
            //do nothing
        }else if(v < 0 && w < 0){
            W -= w;
            ret += v;
            vp.push_back(make_pair(-v,-w));
        }else{
            vp.push_back(make_pair(v,w));
        }
    }
    sort(vp.begin(), vp.end(), pred);
    for(int i=0;i<vp.size();i++){
        double tmp = min(1.0, W/vp[i].second);
        ret += vp[i].first * tmp;
        W -= tmp * vp[i].second;
        if(W < EPS) break;
    }
    printf("%.9f\n", ret);
}
