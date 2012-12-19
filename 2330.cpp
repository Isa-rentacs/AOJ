#include <stdio.h>
int t,n;main(){scanf("%d",&n);for(;n>1;t++)n=n%3?n/3+1:n/3;printf("%d\n",t);}
