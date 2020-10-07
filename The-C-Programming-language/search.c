#include <stdio.h>
#include <time.h>
#define ARR_SIZE 1000
int binarySearch(int nums[], int target, int length);

int main(){
  int num[ARR_SIZE];
  clock_t t;
  double time_taken;
  for(int i = 0; i < ARR_SIZE; ++i)
    num[i] = i;

  t = clock();
  printf("%d", binarySearch(num, 4, 1000));
  t = clock() - t;
  time_taken = ((double)t)/CLOCKS_PER_SEC;

  printf("searching took %f seconds to execute \n", time_taken);
  return 0;
}

int binarySearch(int num[], int target, int length){
  int low, high, mid;

  low = 0;
  high = length - 1;
  while(low <= high){
    mid = (low + high) / 2;
    if (num[mid] > target)
      high = mid - 1;
    else if (num[mid] < target)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}
