#include <stdio.h>
void quickSort2(int nums[], int lo, int hi);
void quickSort(int nums[], int left, int right);
void swap(int nums[], int i, int j);

int main(){
    int to_sort[] = {0,4,3,6,2,2,2,2,2,7,5,8,9,1};
    quickSort2(to_sort, 0, 14);

    for (int i = 0; i < 14; i++)
        printf("%d ", to_sort[i]);

    return 0;
}

void quickSort2(int nums[], int lo, int hi){//using 2 partition and tukeys ninther
    if(hi <= lo)
        return;

    int lt = lo;
    int gt = hi;
    int v = nums[lo];
    int i = lo;

    while(i <= gt){
        if(nums[i] < v)
            swap(nums, lt++, i++);
        else if(nums[i] > v)
            swap(nums, i, gt--);
        else
            i++;
    }

    quickSort2(nums, lo, lt-1);
    quickSort2(nums, gt + 1, hi);
}

void quickSort(int nums[], int left, int right){
    if (left >= right)
        return;
    int last = left;
    swap(nums, left, left + (right - left) / 2);

    for (int i = left; i <= right; i++)
        if (nums[i] < nums[left])
            swap(nums, ++last, i);

    swap(nums, last, left);
    quickSort(nums, left, last - 1);
    quickSort(nums, last + 1, right);
}

void swap(int nums[], int i, int j){
    int z = nums[i];
    nums[i] = nums[j];
    nums[j] = z;
}
