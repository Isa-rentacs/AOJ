#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    int n,m,a,b;
    int buf[300];
    cin >> n >> m;
    memset(buf, -1, sizeof(buf));

    for(int i=0;i<m;i++){
        cin >> a >> b;
        for(int j=a;j<=b;j++){
            buf[j] = max(buf[j], b);
        }
    }
    int ret = 0,pos = 1;
    while(pos <= n){
        if(buf[pos] == -1){
            ret = -1;
            break;
        }else{
            pos = buf[pos] + 1;
            ret++;
        }
    }
    if(ret == -1){
        cout << "Impossible" << endl;
    }else{
        cout << ret << endl;
    }
}
