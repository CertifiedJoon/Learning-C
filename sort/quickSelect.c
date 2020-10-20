#include <stdio.h>
#include <stdbool.h>
void swap(int a[], int i, int j){
    int z = a[i];
    a[i] = a[j];
    a[j] = z;
}

int partition(int nums[], int left, int right){
    int last = left;
    swap(nums, left, left + (right - left) / 2);

    for (int i = left; i <= right; i++)
        if (nums[i] < nums[left])
            swap(nums, ++last, i);

    swap(nums, last, left);
    return last;
}

int quickSelect(int nums[],int size, int k){
    int lo = 0;
    int hi = size - 1;

    while (lo < hi){
        int j = partition(nums, lo, hi);
        if (k+1 > j)
            lo = j + 1;
        else if (k+1 < j)
            hi = j - 1;
        else
            return nums[k];
    }
    return nums[k];
}


int main(){
    int nums[10] = {0,1,3,6,4,7,2,5,8,9};
    for(int i = 0; i < 10; i++)
        printf("%d", quickSelect(nums, sizeof(nums)/sizeof(*nums), i));
}
