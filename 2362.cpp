#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool p(string a, string b){
    return a.size() > b.size();
}
main(){
    string str,tmpstr="";
    vector<string> vs;
    int pos;
    cin >> str;
    while((pos = str.find("egg")) != string::npos){
        str.replace(pos, 3, "A");
    }
    while((pos = str.find("chicken")) != string::npos){
        str.replace(pos, 7, "B");
    }
    int n=str.size();
    char tmp = str[0];
    tmpstr += tmp;
    for(int i=1;i<n;i++){
        if(str[i] != tmp){
            tmp = str[i];
        }else{
            vs.push_back(tmpstr);
            tmpstr = "";
        }
        tmpstr += tmp;
    }
    vs.push_back(tmpstr);
    stable_sort(vs.begin(),vs.end(),p);
    string ret = vs[0][vs[0].size()-1] == 'A'?"egg":"chicken";
    cout << ret << endl;
}
