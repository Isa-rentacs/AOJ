#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

double dp[1 << 12][12];
int n;
int c[12];

double d(int back, int next){
  return sqrt(pow(c[back]+c[next],2)-pow(c[back]-c[next],2));
}

double solve(int state, int back){
  if(dp[state][back] != -1) return dp[state][back];
  if(state == (1 << n) - 1) return dp[state][back]=c[back];

  double ret=1e+20;
  double dist;
  for(int i=0;i<n;i++){
    if(!((1 << i)&state)){
      if(state==0){
	dist = c[i];
      }else{
	dist = d(back,i);
      }
      ret = min(ret, solve(state|1<<i,i) + dist);
    }
  }
  return dp[state][back] = ret;
}

int main(void){
  string str;

  while(getline(cin, str)){
    istringstream iss(str);
    double l;
    double ret = 1e+20;
    fill((double *)dp, (double *)dp+(1<<12)*12, -1);
    memset(c, 0, sizeof(c));
    n = 0;
    iss >> l;
    while(iss >> c[n]) n++;
    ret = min(ret, solve(0, 0));

    if(ret <= l){
      cout << "OK" << endl;
    }else{
      cout << "NA" << endl;
    }
  }
}
