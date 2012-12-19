#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;++i){
        string m;
        string pat;

        cin >> m >> pat;
        reverse(m.begin(), m.end());
        int sz = pat.size();
        for(int j=0;j<m.size();j++){
            if(m[j] == 'A'){
                reverse(pat.begin(), pat.end());
            }else if(m[j] == 'M'){
                for(int k=0;k<pat.size();++k){
                    if(pat[k] == '9'){
                        pat[k] = '0';
                    }else if('0' <= pat[k] && pat[k] <= '8'){
                        pat[k]++;
                    }
                }
            }else if(m[j] == 'P'){
                for(int k=0;k<pat.size();++k){
                    if(pat[k] == '0'){
                        pat[k] = '9';
                    }else if('1' <= pat[k] && pat[k] <= '9'){
                        pat[k]--;
                    }
                }
            }else if(m[j] == 'C'){
                pat += pat[0];
                pat = pat.substr(1,sz);
            }else if(m[j] == 'J'){
                string tmp = "";
                tmp += pat[sz-1];
                tmp += pat.substr(0,sz-1);
                pat = tmp;
            }else if(m[j] == 'E'){
                string pre="",suf="", mid="";
                for(int k=0;k<sz/2;++k){
                    pre += pat[k];
                }
                if(sz % 2 == 1){
                    mid += pat[sz/2];
                }
                for(int k=(sz+1)/2;k<sz;++k){
                    suf += pat[k];
                }
                pat = suf + mid + pre;
            }
        }
        cout << pat << endl;
    }
}
