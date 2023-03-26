#include "interCheck.h"

struct _file* filesearch(char *filename){
  int i=0;
  int j=0;
  int k=0;
  int ncount = 0;
  char output[256][256];
  char *inputa;
  inputa = (char*)malloc(sizeof(char)*512);
  
  FILE *fp;
  fp = fopen(filename,"r");
  struct _file* f = (struct _file*)malloc(sizeof(struct _file)*1500);
  
  while((fgets(inputa,512,fp)) != NULL){// ファイルを１行ずつ読み、ファイルの終端に来たらやめる。
    inputa = chomp(inputa);
    i=0;
    while(inputa[i]!= '\0'){ //1行目が終わるまで
      if(inputa[i] != ' ' && inputa[i] != '\0'){
        while( inputa[i] != ' ' && inputa[i] != '\0'){ //文字列が終わるまで
          output[ncount][j] = inputa[i];
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
  }
  fclose(fp);
  free(inputa);
  
  for(k=0 ; k < ncount ; k++){
    f[k].word = (char*)malloc(sizeof(char)*256);
    mystrcpy(f[k].word,output[k]);
  }
  return f;
}
