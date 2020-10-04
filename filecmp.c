#include <stdio.h>
#include <string.h>

#define MAXLINE 300

int main(int argc, char *argv[]){
  FILE *fp1,*fp2;
  fp1 = fopen(argv[1]);
  fp2 = fopen(argv[2]);
  char *line1[], *line2[];
  while (fgets(line1, MAXLINE, fp1) == fgets(line2, MAXLINE, fp2))
    ;
  printf("%s\n%s\n", line1, line2);
  fclose(fp1);
  fclose(fp2);
  return 0;
}
