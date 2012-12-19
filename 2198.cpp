#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define EPS 1e-9

struct crop{
    double ef;
    string name;

    bool operator<(const crop & arg) const{
        if(abs(ef - arg.ef) < EPS){
            return name < arg.name;
        }else{
            return ef > arg.ef;
        }
    }

    crop(int income, int time, string name){
        this->name = name;
        ef = (double) income / time;
    }
};

int main(){
    int n;
    while(cin >> n && n){
        vector<crop> crops;

        string l;
        int p,a,b,c,d,e,f,s,m,time,income;
        for(int i=0;i<n;i++){
            cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
            time = a+b+c+d+e+(d+e)*(m-1);
            income = f*s*m - p;
            crops.push_back(crop(income,time,l));
        }
        sort(crops.begin(), crops.end());

        for(int i=0;i<n;i++){
            cout << crops[i].name << endl;
        }
        cout << "#" << endl;
     
    }
}
