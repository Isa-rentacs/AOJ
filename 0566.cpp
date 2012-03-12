#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int> > v;
    map<int,int> m;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(0,i+1));
    }

    for(int i=0;i<n*(n-1)/2;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        if(c > d){
            v[a-1].first += 3;
        }else if(c < d){
            v[b-1].first += 3;
        }else{
            v[a-1].first += 1;
            v[b-1].first += 1;
        }
    }
    sort(v.rbegin(), v.rend());
    int pos=1;
    int cnt=0;
    int point;
    for(int i=0;i<n;i++){
        if(i != 0){
            if(point != v[i].first){
                pos++;
                pos += cnt;
                cnt = 0;
            }else{
                cnt++;
            }
        }       
        m[v[i].second] = pos;
        point = v[i].first;
    }

    map<int,int>::iterator it = m.begin();

    while(it != m.end()){
        cout << (*it).second << endl;
        ++it;
    }
}
