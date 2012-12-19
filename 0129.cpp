#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>

#define EPS 1e-7

using namespace std;

typedef complex<double> P;

struct L : public vector<P> {
    L(const P &a, const P &b){
        push_back(a);
        push_back(b);
    }
};

struct C{
    P p;
    double r;
    C(const P &p, double r) : p(p), r(r) { }
};

double dot(const P &a, const P &b){
    return real(conj(a) * b);
}

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

int main(){
    int n,m;                                     
    double x,y,r;
    double a,b;

    while(cin >> n && n){
        vector<C> circles;
        bool isok = false;
        for(int i=0;i<n;i++){
            cin >> x >> y >> r;
            circles.push_back(C(P(x,y), r));
        }
        cin >> m;
        for(int i=0;i<m;i++){
            isok = false;
            cin >> x >> y;
            cin >> a >> b;
            L line = L(P(x,y), P(a,b));
            for(int j=0;j<n;j++){
                if((abs(line[0]-circles[j].p) < circles[j].r &&
                    abs(line[1]-circles[j].p) < circles[j].r) ||
                   distanceSP(line, circles[j].p) > circles[j].r){
                }else{
                    isok = true;
                }
            }
            if(isok){
                cout << "Safe" << endl;
            }else{
                cout << "Danger" << endl;
            }
        }
    }
}
