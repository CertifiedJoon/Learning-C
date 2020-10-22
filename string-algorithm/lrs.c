#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int lcp(char *s, char* v);
void swap(char* s[], int i, int j);
void three_way_rsort(char* s[], int low, int hi, int d);
char* longestrs(char* s);

int main(){
    char* s = "The repeated repeated string the";

    char* longest = longestrs(s);

    while(*longest != '\0')
        putchar(*longest++);

}

int lcp(char *s, char* v){
    int i = 0;
    char* k = s;
    char* j = v;
    while(*k++ == *j++)
        i++;
    return i;
}

char* longestrs(char* s){
    int n = strlen(s);
    char* suffixes[n];

    for (int i = 0; i < n; i++){
        suffixes[i] = (char*) malloc (sizeof(char) * (n-i + 1));
        strncpy(suffixes[i], &s[i], n-i);
        suffixes[i][n-i] = '\0';
    }
    printf("suffixes complete\n");

    three_way_rsort(suffixes, 0, n-1, 0);
    printf("sorting complete\n");


    int max = 0;
    char *lrs;


    for ( int i = 0; i< n-1; i++){
        int len = lcp(suffixes[i], suffixes[i + 1]);
        printf("len : %d\n", len);
        if (len > max){
            lrs = (char*) malloc (sizeof(char) * (len + 1));
            strncpy(lrs, suffixes[i], len);
            lrs[len] = '\0';
            max = len;
        }
    }

    return lrs;
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
