#include <stdio.h>
#define LINEMAX 50
#define TAB 8
int main(){
  int nc, c, nb;
  nc = nb = 0;
  for(int i = 0; i < 50; ++i)
    printf("%d",i % 10);
  putchar('\n');
  while ((c = getchar()) != EOF){
    if (c == '\n')
      nc = 0;
    else if (c == ' ')
      nb++;
    else if (c == '\t')
      nb = nb + (TAB - nc % TAB);
    else{
      if(nc+nb >= LINEMAX){
        putchar('\n');
        nc = 0;
      }
      for(int i = 0; i < nb; ++i){
        putchar(' ');
        nc++;
      }
      nb = 0;
      putchar(c);
      nc++;
    }
  }
}
