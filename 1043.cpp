#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class team{
public:
  team(int a, int b, int c, int d){
    id = a;
    aff = b;
    ac = c;
    pen = d;
  }
  int id;
  int aff;
  int ac;
  int pen;

  bool operator <(const team arg) const{
    if(ac != arg.ac){
      return ac > arg.ac;
    }else{
      if(pen != arg.pen){
	return pen < arg.pen;
      }else{
	return id < arg.id;
      }
    }
  }
};

int main(void){
  int n;
  while(cin >> n && n){
    vector<team> v;
    map<int,int> m;
    int a,b,c,d;
    int selected = 0;
    for(int i=0;i<n;i++){
      cin >> a >> b >> c >> d;
      v.push_back(team(a,b,c,d));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
      if(selected < 10 && m[v[i].aff] < 3){
	cout << v[i].id <<endl;
	m[v[i].aff]++;
	selected++;
	continue;
      }
      if(selected < 20 && m[v[i].aff] < 2){
	cout << v[i].id <<endl;
	m[v[i].aff]++;
	selected++;
	continue;
      }
      if(selected < 26 && m[v[i].aff] == 0){
	cout << v[i].id <<endl;
	m[v[i].aff]++;
	selected++;
	continue;
      }
    }
  }
}
