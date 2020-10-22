#include <stdio.h>

void csort(int a[], int size,int r);

int main(){
    int a[] = {'a', 'c', 'r', 'a', '1', '>', 'z', '\n', 'p'};
    int size = sizeof(a)/sizeof(a[0]);
    printf("size: %d\n", size);
    csort(a, size, 256);

    for (int i = 0; i < size; i++)
        printf("%c ", a[i]);
}

void csort(int a[], int size, int r){
    int count[r + 1];
    int aux[size];

    for (int i = 0; i< r; i++)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[a[i] + 1]++;

    for (int j = 0; j < r; j++)
        count[j + 1] += count[j];

    for (int i = 0; i < size; i++)
        aux[count[a[i]]++] = a[i];

    for (int i = 0; i<size; i++)
        a[i] = aux[i];
}
