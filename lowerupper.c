#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char *argv[]){
  int c, islower = 0;
  if(strcmp(argv[1], "lower") == 0)
    islower = 1;
  while((c = getchar()) != EOF){
    putchar((int (*)(char))(islower? tolower(c) : toupper(c)));
    fflush(stdout);
  }
}
