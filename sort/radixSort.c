#include <stdio.h>
void swap(char* s[], int i, int j);
void three_way_rsort(char* s[], int low, int hi, int d);

int main(){
    int size = 10;
    char * s[10] = {"mobydick", "twenty-thousand leagues under sea", "sherlock holmes", "to kill a mockingbird", "the great gatsby",
                        "the catcher in the rye", "war and peace", "animal farm", "gulliver's travels", "little woman"};

    three_way_rsort(s, 0, size - 1, 0);

    for (int i = 0; i < 10; i++){
        while (*s[i] != '\0')
            putchar(*s[i]++);
        putchar('\n');
    }
}

void three_way_rsort(char* s[], int lo, int hi, int d){
    if (hi <= lo) return;

    int lt = lo;
    int gt = hi;
    int v = s[lo][d];
    int i = lo + 1;

    while (i <= gt){
        int t = s[i][d];
        if (t < v) swap(s, lt++, i++);
        else if (t > v) swap(s, i, gt--);
        else i++;
    }

    three_way_rsort(s, lo, lt-1, d);
    if (gt > lt + 1) three_way_rsort(s, lt, gt, d + 1);
    three_way_rsort(s, gt + 1, hi, d);
}

void swap(char* s[], int i, int j){
    char* temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}
