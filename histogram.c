#include <stdio.h>

int main(){
  int c;
  int chars [128];

  for (int i = 0; i < 128; ++i)
    chars[i] = 0;

  while ((c = getchar()) != EOF){
      chars[c]++;
  }

  for (int i = 0; i < 128; ++i) {
    if (chars[i] != 0) {
      for(int j = 0; j < chars[i]; ++j)
        putchar(i);
      putchar('\n');
    }
  }
}
