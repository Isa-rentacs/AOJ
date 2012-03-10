#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

int main(){
    int n,m,p;
    while(cin >> n >> m >> p){
        if((n|m|p) == 0) break;
        int v[n],sum=0,ret;
        for(int i=0;i<n;i++){
            cin >> v[i];
            sum += v[i];
        }
        //1-控除率を掛けて配分される金額にする
        sum *= 100 - p;
        //配分される金額/当選枚数=1枚あたり
        ret = v[m-1]?sum / v[m-1]:0;
        cout << ret << endl;
            
    }
}
