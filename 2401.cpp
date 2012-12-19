#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cassert>
#include <vector>
#include <map>

using namespace std;
//map<char,bool> assign;
int assign;
bool formula(string &arg, int &pos){
    if('a' <= arg[pos] && arg[pos] <= 'k'){
        return assign & (1 << (arg[pos++]-'a'));
    }else if(arg[pos] == '-'){
        return !formula(arg, ++pos);
    }else if(arg[pos] == 'T'){
        pos++;
        return true;
    }else if(arg[pos] == 'F'){
        pos++;
        return false;
    }else{
        assert(arg[pos] == '(');
        bool f,b;
        char op;
        f = formula(arg, ++pos);
        op = arg[pos];
        assert(op == '*' || op == '+' || op == '-');
        if(op == '-') pos++;
        b = formula(arg, ++pos);
        assert(arg[pos] == ')');
        pos++;
        if(op == '*'){
            if(f&&b) return true;
            return false;
        }else if(op == '+'){
            if(!f&&!b) return false;
            return true;
        }else{
            if(f && !b) return false;
            return true;
        }
    }
}

bool parse(string &arg, int pos){
    bool f,b;

    f = formula(arg, pos);
    assert(arg[pos] == '=');
    b = formula(arg, ++pos);
    return f == b;
}


int main(){
    string str;
    while(cin >> str){
        if(str == "#") break;
        vector<char> vars;
        bool res = true;

        for(int i=0;i<(int)str.size();i++){
            if('a' <= str[i] && str[i] <= 'k'){
                vars.push_back(str[i]);
            }
        }

        for(int i=0;i<(1 << 10);i++){
            assign = i;
            res = parse(str, 0);
            if(!res) break;
        }
        if(res){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
