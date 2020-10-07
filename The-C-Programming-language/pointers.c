char *alloc(int);
void afree(char*);

int main(){
  ;
}

char *alloc(int n){
  if(allocbuf + ALLOCSIZE - allocp >= n){
    allocp += n;
    return allocp - n;
  }
  else
    return 0;
}

void afree(char *p){
  if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
