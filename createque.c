#include "interCheck.h"
struct _option* createque(char *word){
  option* t;
  int length;
  
  t = (option* )malloc(sizeof(option));
  length = mystrlen(word);
  t->word = (char*)malloc(sizeof(char)*length);
  
  mystrcpy(t->word,word);
  t->next = NULL;

  return t;
}
