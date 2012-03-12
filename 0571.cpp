#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define F first
#define S second
using namespace std;
int main(){
string s;
int r=0,c=1,i;
vector<pair<char,int> > v;
cin>>s;
char t=s[0];
for(i=1;i<s.size();++i){
if(s[i] == t){
c++;
}else{
v.push_back(make_pair(t,c));
c=1;
t=s[i];
}
}
v.push_back(make_pair(t,c));
for(int i=0;v.size()>=3&&i<v.size()-2;++i){
if(v[i].F=='J' &&
v[i+1].F=='O' &&
v[i+2].F=='I'){
if(v[i].S>=v[i+1].S &&
v[i+2].S>=v[i+1].S){
r=max(r,min(v[i].S,min(v[i+1].S,v[i+2].S)));
}
}
}
cout<<r<< endl;
}
