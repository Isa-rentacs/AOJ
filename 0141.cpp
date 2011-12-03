#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int main(void){
  int d;
  cin >> d;

  for(int i=0;i<d;i++){
    int n;
    cin >> n;
    bool sharp[n+4][n+4];

    memset(sharp, true,sizeof(sharp));
    for(int p=1;p<=n+2;p++){
      for(int q=0;q<=n+2;q++){
	sharp[p][q] = false;
      }
    }


    int x=n+1,y=2;
    int vec=0;
    int cnt=0;
    if(i) cout << endl;

    while(1){
      sharp[x][y] = true;
      if(sharp[x+dx[vec]*2][y+dy[vec]*2]){
	if(cnt > 0) break;
	cnt = 2;
	vec = (vec+1)%4;
      }else{
	x += dx[vec];
	y += dy[vec];
	cnt--;
      }
    }
    
    for(int p=2;p<n+2;p++){
      for(int q=2;q<n+2;q++){
	if(sharp[p][q]){
	  cout << "#";
	}else{
	  cout << " ";
	}
      }
      cout << endl;
    }
  }
}
