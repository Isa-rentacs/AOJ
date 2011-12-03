#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
  int n;
  int cases=1;

  while(cin >> n && n){
    int lines = n*2-1;
    int mid = lines/2;
    int f[n][n];
    int num;
    int val=1;
    for(int i=0;i<lines;i++){
      if(i<mid){
	num = i+1;
      }else if(i==mid){
	num = n;
      }else{
	num = n-(i-mid);
      }
      bool order;
      i%2?order=true:order=false;
      for(int j=0;j<num;j++){
	if(i <= mid){
	  if(order){
	    f[j][i-j] = val++;
	  }else{
	    f[i-j][j] = val++;
	  }
	}else{
	  if(!order){
	    f[n-j-1][i-n+1+j] = val++;
	  }else{
	    f[i-n+1+j][n-j-1] = val++;
	  }
	}
      }
    }

    printf("Case %d:\n", cases++);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	printf("%3d", f[i][j]);
      }
      printf("\n");
    }
  }
}
