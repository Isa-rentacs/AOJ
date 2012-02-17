#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,a,b;
    while(cin>>n>>a>>b){
        if((n|a|b)==0)break;
        bool c[n+1];
        int i=0,ret=0;
        fill((bool *)c,(bool *)c+n+1,false);
        c[0] = true;
        for(i;i<n+1;i++){
            if(c[i]){
                if(i+a<=n)c[i+a]=true;
                if(i+b<=n)c[i+b]=true;
            }else{
                ret++;
            }
        }
        cout << ret << endl;
    }
}
