#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n,m;

    while(cin >> n >> m && n){
        vector<pair<string, int> > v;
        int val=0;
        string str;
        int tmp;
        for(int i=0;i<n;i++){
            cin >> str >> tmp;
            v.push_back(pair<string,int>(str,tmp));
        }
        for(int i=0;i<m;i++){
            cin >> str;
            bool matched;
            for(int j=0;j<n;j++){
                matched = true;
                for(int k=0;k<8;k++){
                    if(v[j].first[k] == '*') continue;
                    if(v[j].first[k] != str[k]){
                        matched = false;
                        break;
                    }
                }
                if(matched){
                    val += v[j].second;
                }
            }
        }
        cout << val << endl;
    }
}
