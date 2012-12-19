#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class node{
public:
    node(){
        in = 0;
        out = 0;
    }
    
    int in;
    int out;
    vector<int> nxt;
    bool reachable;
};

int main(){

    int n;
    string str;
    while(cin >> n && n){
        node *v;
        v = new node[26];
        for(int i=0;i<n;i++){
            cin >> str;
            v[str[0] - 'a'].in++;
            v[str[str.size()-1] - 'a'].out++;
            v[str[0] - 'a'].nxt.push_back(str[str.size()-1] - 'a');
        }
   
        bool isok = true;
        for(int i=0;i<26;i++){
            if(v[i].in != v[i].out) isok = false;
        }
        if(isok){
            deque<int> q;
            for(int i=0;i<26;i++){
                if(v[i].in != 0){
                    v[i].reachable = true;
                    q.push_back(i);
                    break;
                }
            }
            while(!q.empty()){
                int tmp = q.front();
                q.pop_front();

                for(int i=0;i<v[tmp].nxt.size();i++){
                    if(v[v[tmp].nxt[i]].reachable == false){
                        q.push_back(v[tmp].nxt[i]);
                        v[v[tmp].nxt[i]].reachable = true;
                    }
                }
            }
            for(int i=0;i<26;i++){
                if(v[i].in != 0 && v[i].reachable == false){
                    isok = false;
                }
            }
        }

        if(isok){
            cout << "OK" << endl;
        }else{
            cout << "NG" << endl;
        }
    } 
}
