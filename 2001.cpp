#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct edge{
    int h,p,q;

    edge(int hh, int pp, int qq){
        h = hh;
        p = pp;
        q = qq;
    }

    bool operator<(const edge &arg)const {
        return h > arg.h;
    }
};

int main(){
    int n,m,a,h,p,q;

    while(cin >> n >> m >> a){
        if((n|m|a) == 0) break;
        
        vector<edge> v;
        for(int i=0;i<m;i++){
            cin >> h >> p >> q;
            v.push_back(edge(h,p,q));
        }

        sort(v.begin(), v.end());
        for(int i=0;i<m;i++){
            if(v[i].p == a){
                a = v[i].q;
            }else if(v[i].q == a){
                a = v[i].p;
            }
        }
        cout << a << endl;
    }
}
