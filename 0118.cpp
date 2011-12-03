#include <iostream>
#include <string>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

int di[4] = {1,0,-1,0};
int dj[4] = {0,-1,0,1};
int h,w;

int main(void){
  int i,j,k;
  string str;



  while(cin >> h >> w && (h|w) != 0){
    char f[h][w];
    bool visited[h][w];
    int ret = 0;
    deque<pair<int,int> > q;
    memset(visited, false, sizeof(visited));

    for(i=0;i<h;i++){
      cin >> str;
      for(j=0;j<w;j++){
	f[i][j] = str[j];
      }
    }
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	if(visited[i][j] == false){
	  int tmp[2];

	  q.push_back(make_pair(i,j));
	  while(!q.empty()){
	    tmp[0] = q.front().first;
	    tmp[1] = q.front().second;
	    q.pop_front();

	    
	    if(f[i][j] == f[tmp[0]][tmp[1]] && !visited[tmp[0]][tmp[1]]){
	      //cout << tmp[0] << " " << tmp[1] << endl;
	      visited[tmp[0]][tmp[1]] = true;
	      for(int k=0;k<4;k++){
		if(0 <= tmp[0] + di[k] &&
		   tmp[0] + di[k] < h &&
		   0 <= tmp[1] + dj[k] &&
		   tmp[1] + dj[k] < w){
		  q.push_back(make_pair(tmp[0]+di[k], tmp[1]+dj[k]));
		}
	      }
	    }
	  }
	  //	  cout << endl << endl;
	  ret++;
	}
      }
    }
    cout << ret << endl;
  }
}
