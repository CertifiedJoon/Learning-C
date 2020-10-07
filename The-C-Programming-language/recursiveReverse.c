#include <stdio.h>
#include <string.h>
#define MAXSTRING 100

void reverse(char[], int, int);

int main(){
  char s[MAXSTRING] = "hello world";
  reverse(s,0, 10);
  printf("%s", s);
}

void reverse(char s[], int left, int right){
  if (left >= right)
    return;
  char temp;
  temp = s[left];
  s[left] = s[right];
  s[right] = temp;
  reverse(s, left+1, right-1);
}
