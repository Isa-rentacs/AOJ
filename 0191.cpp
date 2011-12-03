#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int n,m;
double dp[101][100];
double t[100][100];

double solve(int times, int prev){
  if(dp[times][prev] != -1) return dp[times][prev];
  if(times == m) return dp[times][prev]=1;

  double tmp=-1;
  for(int i=0;i<n;i++){
    if(times == 0){
      tmp = max(tmp, solve(times+1, i) * 1);
    }else{
      tmp = max(tmp, solve(times+1, i) * t[prev][i]);
    }
  }
  
  return dp[times][prev] = tmp;
}

int main(void){
  while(cin >> n >> m){
    if(!(n|m)) break;
    fill((double *)dp, (double *)dp+101*101, -1);
    double retd;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	cin >> t[i][j];
      }
    }
    retd = solve(0,0) * 100;
    printf("%.2lf\n", round(retd) /  100);
  }
}
