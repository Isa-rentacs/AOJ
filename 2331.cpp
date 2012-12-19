#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool predication(pair<int,int> arg1, pair<int,int> arg2){
    if(arg1.first == arg2.first){
        return arg1.second > arg2.second;
    }
    return arg1.first < arg2.first;
}

int main(){
    int n,a,b;
    vector<pair<int,int> > v;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v.push_back(make_pair(a,1));
        v.push_back(make_pair(b,-1));
    }
    sort(v.begin(),v.end(),predication);
    int cnt=1;
    int ret=-1;
    for(int i=0;i<v.size();i++){
        cnt += v[i].second;
        if(i+1==v.size() || v[i].first <= cnt && cnt <= v[i+1].first){
            ret = max(ret, cnt);
        }
    }
    cout << ret-1 << endl;
}
