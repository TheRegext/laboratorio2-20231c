#include <iostream>
using namespace std;

int main(){
  int vec[5] = {10, 20, 30, 40, 50};
  int *p;
  p = &vec[0];

  int i;
  for(i=0; i<5; i++){
    cout << *(p+i) << endl;
  }

  return 0;
}
