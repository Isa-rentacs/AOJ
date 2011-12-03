#include <iostream>
#include <numeric>
using namespace std;
main(){
int n;
while(cin>>n&&n){
int k=n*(n-1)/2,a[k],i=k;
while(i)cin>>a[--i];
cout<<accumulate(a,a+k,0)/(n-1)<<endl;
}
}
