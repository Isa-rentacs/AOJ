#include <iostream>

using namespace std;

int q1,badget,c1,c2,lower,upper,mid,lim;

bool s(int arg){
  int qn = (badget - arg * c1) / c2;
  if(qn < 0) return false;
  if(qn+arg < q1) return false;
  if(arg > lim) return false;
  if(badget - arg * c1 < 0) return false;
  return true;
}

int main(){

  while(cin >> q1 && q1){
    cin >> badget >> c1 >> c2 >> lim;
    lower = 0;
    upper = 1000000;

    //binary search
    while(upper - lower > 1){
      mid = (upper + lower) / 2;
      if(s(mid)){
	lower = mid;
      }else{
	upper = mid;
      }
    }
    if(lower == 0){
      cout << "NA" << endl;
    }else{
      cout << lower << " " << (badget - lower*c1)/c2 << endl;
    }
  }
}
