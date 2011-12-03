#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> w,s,hist,ret;
vector<string> name;
int n,tmpn,tmpm;
int used;
string str;
double gmin = 1e+10;

inline double calc_g(){
    double p=0;
    double q=0;
    for(int i=0;i<n;i++){
        p += (n-i) * hist[n-1-i];
        q += hist[i];
    }
    return p/q;
}

void solve(int num, int weight){
    if(num == n){
        double g = calc_g();
        if(gmin > g){
            gmin = g;
            ret.clear();
            copy(hist.begin(), hist.end(), back_inserter(ret));
        }
        return;
    }
    
    for(int i=0;i<n;i++){
        if((used & 1 << i) == 0 && weight >= s[i]) return;
    }
    
    for(int i=0;i<n;i++){
        if((used & (1 << i)) == 0){
            if(s[i] >= weight){
                //未使用でかつ重みに耐えられたら積んでみる
                used += 1 << i;
                hist.push_back(i);
                solve(num+1, weight+w[i]);
                hist.pop_back();
                used -= 1 << i;
            }
        }
    }
}

int main(void){
    while(cin >> n && n){
        w.clear();
        s.clear();
        hist.clear();
        ret.clear();
        name.clear();
        used = 0;
        gmin = 1e+10;
        for(int i=0;i<n;i++){
            cin >> str >> tmpn >> tmpm;
            name.push_back(str);
            w.push_back(tmpn);
            s.push_back(tmpm);
        }
        solve(0,0);
        for(int i=0;i<n;i++){
            cout << ret[n-i-1] << endl;
            cout << name[ret[n-i-1]] << endl;
        }
    }
}
