#include <limits.h>
#include <stdio.h>

long pow(int x, int n);
int main(){
  printf("limit: %ld %ld", );
}

long pow(int x, int n){
  long result = 1;
  for(int i = 0; i < n; ++i)
    result = result * x;
  return result;
}
