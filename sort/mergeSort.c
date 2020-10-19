#include <stdio.h>
#include <string.h>

void merge(int nums[], int low, int mid, int hi);

void mergeSort(int nums[], int lo, int hi);

int main(){
    int nums[10] = {6,5,4,3,2,9,1,8,7,0};

    mergeSort(nums, 0, 9);

    for (int i = 0; i < 10;i++){
        printf("%d ", nums[i]);
    }

    return 0;
}

void mergeSort(int nums[], int lo, int hi){
    if (hi <= lo) return;

    int mid = lo + (hi - lo) / 2;
    mergeSort(nums, lo, mid);
    mergeSort(nums, mid + 1, hi);

    merge(nums, lo, mid, hi);
}

void merge(int nums[], int lo, int mid, int hi){

    int aux[hi+1];
    for (int k = lo; k <= hi; k++){
        aux[k] = nums[k];
    }

    int i = lo;
    int j = mid + 1;

    for (int k = lo; k <= hi; k++){
        if (i > mid)
            nums[k] = aux[j++];
        else if (j > hi)
            nums[k] = aux[i++];
        else if (aux[j] < aux[i])
            nums[k] = aux[j++];
        else
            nums[k] = aux[i++];
    }
    return;
}
