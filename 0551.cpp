#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int n,l;
    cin >> n >> l;
    int t[n];
    int ice[n];

    priority_queue<pair<int,int> > q;
    fill((int *)t, (int *)t+n,0);
    for(int i=0;i<n;i++){
        cin >> ice[i];
        q.push(make_pair(ice[i], i));
    }

    int len, index;
    while(!q.empty()){
        len = q.top().first;
        index = q.top().second;
        q.pop();
        
        if(index == 0){
            t[index] = t[1] + (l - len);
        }else if(index == n-1){
            t[index] = t[n-2] + (l - len);
        }else{
            t[index] = max(t[index-1], t[index+1]) + (l - len);
        }
    }
    int ret = -1;
    for(int i=0;i<n;i++){
        ret = max(ret, t[i]);
    }
    cout << ret << endl;
}
