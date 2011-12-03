#include<iostream>
#include<cstdio>
main(){int t;while(std::cin>>t){if(!t) break;int r=0;while(t>=5){r+=t/5;t/=5;}printf("%d\n",r);}}
