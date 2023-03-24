#include "interCheck.h"
BinSTreeNode* createNode(char* Word){
  BinSTreeNode* t;
  int length;

  t =(BinSTreeNode* )malloc(sizeof(BinSTreeNode));
  length = mystrlen(Word);
  t->word = (char*)malloc(sizeof(char)*length);
  
  mystrcpy(t->word,Word);
  t->left = NULL;
  t->right = NULL;
  t->pare = NULL;
  
  return t;
}
