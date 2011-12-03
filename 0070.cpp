#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
  int n,s;
  int array[10] = {0,1,2,3,4,5,6,7,8,9};
  int tmp;
  int ret;
  int fact;

  while(cin >> n){
    cin >> s;

    ret = 0;
    for(int i=0;i<10;i++) array[i] = i; //initialize array;

    do{
      tmp = 0;
      for(int i=1;i<=n;i++){
	tmp += i * array[10-i];
	if(tmp > s) break;
	//cout << i << "*" << array[10-i] << "  + ";
      }
      //cout << endl;
      if(tmp == s) ret++;
    }while(next_permutation(array, array+10));
    fact = 1;
    for(int i=2;i<=10-n;i++){
      fact *= i;
    }
    cout << ret / fact << endl;
  }
}
