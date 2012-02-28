#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>

#define EPS 1e-8

using namespace std;

typedef complex<double> P; 
typedef vector<P> G;

double cross(const P &a, const P &b){
    return imag(conj(a)*b);
}

double dot(const P &a, const P &b){
    return real(conj(a) * b);
}

struct L : public vector<P> {
    L(const P &a, const P &b){
        push_back(a);
        push_back(b);
    }
    L(){}
};

struct C{
    P p;
    double r;
    C(const P &p, double r) : p(p), r(r) { }
    C(){}
};

bool intersectSP(const L &s, const P &p) {
    return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}

P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}

double distanceSP(const L &s, const P &p) {
  const P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}

#define curr(G, i) G[i]
#define next(G, i) G[(i+1)%G.size()]
enum { OUT, ON, IN };
int contains(const G &g, const P &p) {
    bool in = false;
    for (int i = 0; i < g.size(); ++i) {
        P a = curr(g,i) - p, b = next(g,i) - p;
        if (imag(a) > imag(b)) swap(a, b);
        if (imag(a) <= 0 && 0 < imag(b))
            if (cross(a, b) < 0) in = !in;
        if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
    }
    return in ? IN : OUT;
}

int main(){
    int tmpx, tmpy,r;
    while(cin >> tmpx >> tmpy){
        if((tmpx | tmpy) == 0) break;
        G v(3);
        L *e = new L[3];
        C c;
        v[0] = P(tmpx, tmpy);
        cin >> tmpx >> tmpy;
        v[1] = P(tmpx, tmpy);
        cin >> tmpx >> tmpy;
        v[2] = P(tmpx, tmpy);
        e[0] = L(v[0],v[1]);
        e[1] = L(v[0],v[2]);
        e[2] = L(v[1],v[2]);
        cin >> tmpx >> tmpy >> r;
        c = C(P(tmpx,tmpy), r);
        //a:T contains C
        bool isA = true;
        for(int i=0;i<3;i++){
            //for all edges
            if(distanceSP(e[i], c.p) < r){
                isA = false;
            }
        }
        if(isA && contains(v, c.p) == IN){
            cout << "a" << endl;
            continue;
        }
        //b:C contains T
        bool isB = true;
        for(int i=0;i<3;i++){
            //for all vertex
            if(abs(v[i] - c.p) > r){
                isB = false;
            }
        }
        if(isB){
            cout << "b" << endl;
            continue;
        }
        bool isC = false;
        for(int i=0;i<3;i++){
            if(distanceSP(e[i], c.p) <= r){
                isC = true;
            }
        }
        if(isC){
            cout << "c" << endl;
        }else{
            cout << "d" << endl;
        }
    }
}
