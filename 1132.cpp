#include <cstdio>
#include <complex>
#include <vector>
using namespace std;
typedef complex<double> P;
const double PI=3.141592653589793238462643383279;

bool inC(P p, P c, double r){return abs(p-c)<r+1e-9;}

P getE(P p){return p/abs(p);}

double sq(double x){ return  x*x;}

int main(){
    int n,i,j,k,ans,cnt;
    double x, y;
    while(scanf("%d",&n)){
        if(n==0) break;
        ans=0;
        vector<P> ps(n);
        for(i=0; i<n; i++){
            scanf("%lf%lf",&x,&y);
            ps[i] = P(x,y);
        }
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)if(abs(ps[i]-ps[j])<2){
                    double d=sqrt(1-sq(abs(ps[j]-ps[i])*0.5));
                    P c1=0.5*(ps[i]+ps[j])+getE(ps[j]-ps[i])*polar(d,PI/2);
                    P c2=0.5*(ps[i]+ps[j])+getE(ps[j]-ps[i])*polar(d,-PI/2);
                    cnt=0;
                    for(k=0;k<n;k++)if(inC(ps[k],c1,1.0))cnt++;
                    if(cnt>ans)ans=cnt;
                    cnt=0;
                    for(k=0;k<n;k++)if(inC(ps[k],c2,1.0))cnt++;
                    if(cnt>ans)ans=cnt;
                }
        if(ans==0) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
