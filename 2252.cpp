#include <iostream>
#include <string>

using namespace std;

bool r[26];

int main(){
    int state=-1;
    string str;
    int ret=0;
    r['y' - 'a'] = true;
    r['u' - 'a'] = true;
    r['i' - 'a'] = true;
    r['o' - 'a'] = true;
    r['p' - 'a'] = true;
    r['h' - 'a'] = true;
    r['j' - 'a'] = true;
    r['k' - 'a'] = true;
    r['l' - 'a'] = true;
    r['n' - 'a'] = true;
    r['m' - 'a'] = true;
    while(cin >> str){
        ret = 0;
        state = -1;
        if(str == "#") return 0;
        for(int i=0;i<str.size();i++){
            if(r[str[i]- 'a'] == false){
                if(state == 1) ret++;
                state = 0;
            }else{
                if(state == 0) ret++;
                state = 1;
            }
        }
        cout << ret << endl;
    }
}
