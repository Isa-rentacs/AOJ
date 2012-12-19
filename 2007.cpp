#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline int calc(int a,int b,int c,int d){
    return a*10+b*50+c*100+d*500;
}

int val(int arg, int &x1, int &x2, int &x3 , int &x4){
    int ret = 0, tmp;
    tmp = arg / 500;
    ret += tmp;
    x1 = tmp;
    arg -= tmp * 500;
    tmp = arg / 100;
    ret += tmp;
    x2 = tmp;
    arg -= tmp * 100;
    tmp = arg / 50;
    ret += tmp;
    x3 = tmp;
    arg -= tmp * 50;
    tmp = arg / 10;
    ret += tmp;
    x4 = tmp;
    return ret;
}

struct pay{
    int p,q,r,s,v,sum;

    pay(int vv, int pp, int qq, int rr, int ss, int xx){
        v = vv;
        p = pp;
        q = qq;
        r = rr;
        s = ss;
        sum = xx;
    }
};

int main(){
    int n;
    bool f = true;
    while(cin >> n && n){
        if(f){
            f = false;
        }else{
            cout << endl;
        }
        int a,b,c,d,y1=0,y2=0,y3=0,y4=0,x[4];
        vector<pay> v;
        int ret = 1 << 20;
        int ret2 = 1 << 20;
        cin >> a >> b >> c >> d;
        

        for(int p=0;p<=a;p++){
            for(int q=0;q<=b;q++){
                for(int r=0;r<=c;r++){
                    for(int s=0;s<=d;s++){
                        v.push_back(pay(calc(p,q,r,s), p,q,r,s,p+q+r+s));
                    }
                }
            }
        }
    
        for(int i=0;i<v.size();i++){
            if(v[i].v >= n){
                int tmpv = a+b+c+d + val(v[i].v-n,x[0],x[1],x[2],x[3]) - v[i].sum;
                int tmpv2 = v[i].v;
                if(ret > tmpv){
                    ret = tmpv;
                    ret2 = tmpv2;
                    y1 = v[i].p;
                    y2 = v[i].q;
                    y3 = v[i].r;
                    y4 = v[i].s;
                }else if(ret == tmpv && ret2 > tmpv2){
                
                }
            }
        }
        if(y1){
            cout << "10 " << y1 << endl;
        }
        if(y2){
            cout << "50 " << y2 << endl;
        }
        if(y3){
            cout << "100 " << y3 << endl;
        }
        if(y4){
            cout << "500 " << y4 << endl;
        }
    }
}
