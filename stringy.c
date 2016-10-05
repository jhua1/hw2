#include <stdio.h>
#include <stdlib.h>

int stringlength(char *s){
  int len = 0;
  while(*s){
    len++;
    s++;
  }
  return len;
}
char * stringncopy(char *dest, char *source, int n){
  char *src = source;
  char *des = dest;
  int x;
  for(x=0; x<n && *source; x++){
    *des = *src; 
    src++;
    des++;
  }
  *des = *src;
  return dest;
}


char * stringcat( char *dest, char *source){
  char *des = dest;
  while (*des){
    des++;
  }
  stringncopy(des,source,stringlength(source));
  return dest;
}

int stringcomp(char *s1, char *s2){
  while(*s1 || *s2){
    if( *s1 != *s2)
      return *s1 - *s2;
    else{
      s1++;
      s2++;
    }
  }
  return 0;
}

char * stringchr(char *s, char c){
  while(*s != c){
    if(*s == 0)
      return NULL;
    s++;
  }
  return s;
}

void main(){
  printf("Testing length:\n");
  char x[20] = "hehexd";
  printf("hehexd length: %d\n", stringlength(x));
  char y[20] = "spaghetti";
  printf("spaghetti length: %d\n", stringlength(y));

  printf("Testing Copy:\n");
  printf("Copying phrase same into spaghetti\n");
  stringncopy(y, "same",4);
  printf("y's phrase: %s\n", y);
  printf("Copying same into hehexd\n"); 
  stringncopy(x,y,4);
  printf("hehexd new phrase: %s\n", x);

  printf("Testing Appending:\n");
  printf("adding same to same\n");
  stringcat(x,y);
  printf("new phrase: %s\n", x);
  //  printf("add abc to xyz %s\n" , stringcat("xyz","abc"));

  printf("Testing Compare\n");
  printf("Comparing lul to lulu: %d\n", stringcomp("lul","lulu"));
  printf("Comparing same to same: %d\n", stringcomp("same","same"));
  printf("Comparing deleleel to whoop: %d\n", stringcomp("deleleel", "whoop"));

  printf("Testing StringCHr\n");
  printf("Phrase after Hello in Hello,Its me: %s\n",stringchr("Hello,Its me",','));
  printf("Phrase after h in hello: %s\n", stringchr("hello",'e'));    
}
