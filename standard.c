#include "interCheck.h"

struct _file* standard(char *input){
  int i=0;
  int j=0;
  int k=0;
  int ncount = 0;
  char output[256][256];
  struct _file* f = (struct _file*)malloc(sizeof(struct _file)*1500);
  
  input = chomp(input);
  while(input[i]!= '\0'){ //1行目が終わるまで
    if(input[i] != ' ' && input[i] != '\0'){
      while( input[i] != ' ' && input[i] != '\0'){ //文字列が終わるまで
        output[ncount][j] = input[i];
        i++;
        j++;
      }
      output[ncount][j] = '\0';
      j=0;
      ncount++;
    }
    else{
      i++;
    }
  }

  for(k=0 ; k< ncount ; k++){
    f[k].word = (char*)malloc(sizeof(char)*256);
    mystrcpy(f[k].word,output[k]);
  }
  return f;
}
