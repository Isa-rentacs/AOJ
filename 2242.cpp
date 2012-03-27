#include <iostream>
#include <string>
#include <vector>

using namespace std;

class era{
public:
    era(string s, int b, int l){
        name = s;
        begin = b;
        len = l;
    }

    string name;
    int begin;
    int len;
};

int main(){
    int n,q;
    while(cin >> n >> q && n+q!=0){
        vector<era> v;
        string str;
        int len,begin,query;
        for(int i=0;i<n;i++){
            cin >> str >> len >> begin;
            v.push_back(era(str, begin-len+1, len));
        }
        for(int i=0;i<q;++i){
            bool isok = false;
            cin >> query;
            for(int j=0;j<n;++j){
                if(v[j].begin <= query &&
                   query < v[j].begin + v[j].len){
                    isok = true;
                    cout << v[j].name << " " << query - v[j].begin+1 << endl;
                }
            }
            if(!isok) cout << "Unknown" << endl;
        }
    }
}
