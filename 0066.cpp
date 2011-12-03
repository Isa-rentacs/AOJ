#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void){
  char b[3][3];
  char tmp;
  char ret;
  string str;

  while(getline(cin,str)){
    istringstream iss(str);

    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	iss >> tmp;
	b[i][j] = tmp;
      }
    }
    
    if(b[0][0] == b[0][1] && b[0][1] == b[0][2] && b[0][0] != 's'){
      ret = b[0][0];
    }else if(b[1][0] == b[1][1] && b[1][1] == b[1][2] && b[1][0] != 's'){
      ret = b[1][0];
    }else if(b[2][0] == b[2][1] && b[2][1] == b[2][2] && b[2][0] != 's'){
      ret = b[2][0];
    }else if(b[0][0] == b[1][0] && b[1][0] == b[2][0] && b[0][0] != 's'){
      ret = b[0][0];
    }else if(b[0][1] == b[1][1] && b[1][1] == b[2][1] && b[0][1] != 's'){
      ret = b[0][1];
    }else if(b[0][2] == b[1][2] && b[1][2] == b[2][2] && b[0][2] != 's'){
      ret = b[0][2];
    }else if(b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0] != 's'){
      ret = b[0][0];
    }else if(b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[0][2] != 's'){
      ret = b[0][2];
    }else{
      ret = 'd';
    }
    cout << ret << endl;
  }
}
