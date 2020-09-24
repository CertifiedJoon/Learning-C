#include <stdio.h>
#define square(x) x * x
#define swap(t,x,y){
  t _z;
  _z = x;
  x = y;
  y = _z;}

int main(){
  int x, y;
  x = 1, y = 3;
  swap(int, x, y);
  printf("%d %d\n", x, y);
}
