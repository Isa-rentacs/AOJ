#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
 
using namespace std;
 
int cost[9][9];
 
struct node{
    string num;
    int cost;
    node(string n, int c):num(n), cost(c){}
    node(){}
    bool operator >(const node &arg) const{
        return cost > arg.cost;
    }
};
 
int main(){
    int n;
    string str="";
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> cost[i][j];
        }
    }
 
    for(int i=0;i<n;i++) str += (char)('1' + i);
 
    priority_queue<node, vector<node>, greater<node> > q;
    map<string,bool> mb;
    map<string,int> mi;
    string tmpstr,working;
    int tmpcost;
    node tmpnode;
    q.push(node(str, 0));
    while(!q.empty()){
        tmpnode = q.top(); q.pop();
        tmpstr = tmpnode.num;
        tmpcost = tmpnode.cost;
 
        if(mb[tmpstr] == true) continue;
        mb[tmpstr] = true;
        mi[tmpstr] = tmpcost;
 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                working = tmpstr;
                swap(working[i], working[j]);
                if(mb[working] == false){
                    q.push(node(working, tmpcost + cost[working[i] - '1'][working[j] - '1']));
                }
            }
        }
    }
    map<string,int>::iterator it = mi.begin();
    int ret = -1;
    while(it != mi.end()){
        ret = max(ret, (*it).second);
        ++it;
    }
    cout << ret << endl;
}
