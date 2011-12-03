#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ret=0;
bool chked[12][12];
bool f[12][12]; //0:sea 1:land

void bfs(int x, int y){
  //chk lands
  chked[x][y] = true;

  //cout << "(x,y) = (" << x << "," << y << ")" << endl;
  for(int i=0;i<4;i++){
    if((0 <= x+dx[i] && x+dx[i] <= 11 && 0 <= y+dy[i] && y+dy[i] <= 11) &&
       chked[x+dx[i]][y+dy[i]] == false && f[x+dx[i]][y+dy[i]] == 1){
      bfs(x+dx[i], y+dy[i]);
    }
  }
}


int main(void){
  string str;

  while(getline(cin,str)){
    memset(chked, false, sizeof(chked));
    ret = 0;

    if(str.empty()) continue;
    for(int i=0;i<12;i++){
      for(int j=0;j<12;j++){
	f[i][j] = str[j] - '0';
      }
      getline(cin,str);
    }

    for(int i=0;i<12;i++){
      for(int j=0;j<12;j++){
	if(f[i][j] == 1 && chked[i][j] == false){
	  bfs(i,j);
	  ret++;
	}
      }
    }
    cout << ret << endl;
  }
}
