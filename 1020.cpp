#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX_SEC 15
#define MAX_STATE 1 << 9

#define FILL(ptr, value) FILL_((ptr), sizeof(ptr)/sizeof(value), (value))
template <typename T>
void FILL_(void * ptr, size_t size, T value){
  std::fill((T*)ptr, (T*)ptr+size, value);
}

using namespace std;

double dp[MAX_SEC+1][9];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int dir[4] = {1,3,-1,-3};

int main(void){
  int n;
  while(cin >> n && n){
    FILL(dp,0);
    char tmp;
    int s,t,b,x,y;

    cin >> tmp; s = (int)(tmp - 'A');
    cin >> tmp; t = (int)(tmp - 'A');
    cin >> tmp; b = (int)(tmp - 'A');

    dp[0][s] = 1;
    for(int i=0;i<n;i++){
      for(int j=0;j<9;j++){
	if(dp[i][j] == 0) continue;
	x = j%3;
	y = j/3;
	for(int k=0;k<4;k++){
	  if(0 <= x+dx[k] && x+dx[k] < 3 &&
	     0 <= y+dy[k] && y+dy[k] < 3 &&
	     j+dir[k] != b){
	    dp[i+1][j+dir[k]] += dp[i][j] * 0.25;
	  }else{
	    dp[i+1][j] += dp[i][j] * 0.25;
	  }
	}
      }
    }
    printf("%.8lf\n", dp[n][t]);
  }
}
