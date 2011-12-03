#include <iostream>
#include <string>

using namespace std;

class DICE{
  /*
   * top = 0, right = 1, up = 2, left = 3, down = 4, bottom = 5; 
   */
public:
  DICE(int a, int b, int c, int d, int e, int f){
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    v[4] = e;
    v[5] = f;
  }

  DICE(int a, int b, int c){
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = 7-b;
    v[4] = 7-c;
    v[5] = 7-a;
  }
  int v[6];

  void rotate(int arg){
    int tmp=v[0];
    if(arg == 0){
      //North
      v[0] = v[4];
      v[4] = v[5];
      v[5] = v[2];
      v[2] = tmp;
    }else if(arg == 1){
      //East
      v[0] = v[3];
      v[3] = v[5];
      v[5] = v[1];
      v[1] = tmp;
    }else if(arg == 2){
      //West
      v[0] = v[1];
      v[1] = v[5];
      v[5] = v[3];
      v[3] = tmp;
    }else if(arg == 3){
      //South
      v[0] = v[2];
      v[2] = v[5];
      v[5] = v[4];
      v[4] = tmp;
    }else if(arg == 4){
      //right
      tmp = v[4];
      v[4] = v[1];
      v[1] = v[2];
      v[2] = v[3];
      v[3] = tmp;
    }else{
      tmp = v[4];
      v[4] = v[3];
      v[3] = v[2];
      v[2] = v[1];
      v[1] = tmp;
    }
  }

  int top(void){
    return v[0];
  }

  int bottom(void){
    return v[5];
  }
};

int main(void){
  int n;
  string str;
  while(cin >> n && n){
    DICE d = DICE(1,3,5);
    int ret = 0;
    string str;
    while(n--){
      cin >> str;
      if(str == "North"){
	d.rotate(0);
      }else if(str == "East"){
	d.rotate(1);
      }else if(str == "West"){
	d.rotate(2);
      }else if(str == "South"){
	d.rotate(3);
      }else if(str == "Right"){
	d.rotate(4);
      }else if(str == "Left"){
	d.rotate(5);
      }
      ret += d.top();
    }
    cout << ret+1 << endl;
  }
}
