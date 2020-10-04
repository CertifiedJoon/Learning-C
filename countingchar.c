#include <stdio.h>

int main()
{
  int c, spaces_before;
  spaces_before = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' '){
      if (spaces_before == 0)
        putchar('\\');
      spaces_before++;
    }
    else{
      spaces_before = 0;
      putchar(c);
    }
  }
}
