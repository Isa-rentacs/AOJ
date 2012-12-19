#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a,b;
int n,m;

int solve(int x, int y){
    int ret=0,cnt=0;
    while(x < n && y < m){
        if(a[x] == b[y]){
            cnt++;
        }else{
            ret = max(ret,cnt);
            cnt = 0;
        }
        x++;
        y++;
    }
    return max(ret,cnt);
}

int main(){
    while(cin >> a >> b){
        int x=0,y=0,t=1,tmp=0,ret=0;
        n=a.size();
        m=b.size();
        for(int i=0;i<n;i++){
            ret = max(ret,solve(i,0));
        }
        for(int i=0;i<m;i++){
            ret = max(ret,solve(0,i));
        }
        cout << ret << endl;
    }
}
