#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main(){
    string str1, str2, str3;

    while(cin >> str1){
        if(str1 == "-") break;
        string ret = "";
        deque<char> qu, ql;
        char c;
        cin >> str2 >> str3;
        for(int i=0;i<str1.size();i++) qu.push_back(str1[i]);
        for(int i=0;i<str2.size();i++) ql.push_back(str2[i]);

        c = ql.front();
        ql.pop_front();
        while(!qu.empty() || !ql.empty()){
            if(str3.find(c,0) == string::npos){
                ret += c;
                if(ql.empty()){
                    c = qu.front();
                    qu.pop_front();
                }else{
                    c= ql.front();
                    ql.pop_front();
                }
            }else{
                if(qu.empty()){
                    c = ql.front();
                    ql.pop_front();
                }else{
                    c = qu.front();
                    qu.pop_front();
                }
            }
        }
        ret += c;
        cout << ret << endl;
    }
}
