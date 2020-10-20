#include <stdio.h>

void quickSort(int nums[], int left, int right);
void swap(int nums[], int i, int j);

int main(){
    int to_sort[10] = {9,8,7,6,5,4,2,3,1};
    quickSort(to_sort, 0, 9);

    for (int i = 0; i < 10; i++)
        printf("%d ", to_sort[i]);

    return 0;
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
