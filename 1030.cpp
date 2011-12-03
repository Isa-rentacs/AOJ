#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MP make_pair
#define PB push_back

int main(void){
  int n,h;

  while(cin >> n >> h){
    if((n|h) == 0) break;
    string str;
    int p,q,ret=n*n*n;
    vector<pair<int,int> > xy,xz,yz;
    for(int i=0;i<h;i++){
      cin >> str >> p >> q;
      if(str == "xy"){
	xy.PB(MP(p,q));
      }else if(str == "xz"){
	xz.PB(MP(p,q));
      }else{
	yz.PB(MP(p,q));
      }
    }
    //xy
    ret -= xy.size()*n;
    //xz
    for(int i=0;i<xz.size();i++){
      int tmp=n;
      for(int j=0;j<xy.size();j++){
	if(xz[i].first == xy[j].first) tmp--;
      }
      ret -= tmp;
    }
    //yz
    for(int i=0;i<yz.size();i++){
      int tmp=n;
      for(int j=1;j<=n;j++){
	bool dosub = false;
	for(int k=0;k<xy.size();k++){
	  if(j == xy[k].first && xy[k].second == yz[i].first){
	    dosub = true;
	  }
	}
	for(int k=0;k<xz.size();k++){
	  if(j == xz[k].first && xz[k].second == yz[i].second){
	    dosub = true;
	  }
	}
	if(dosub) tmp--;
      }
      ret -= tmp;
    }

    cout << ret << endl;
  }
}
