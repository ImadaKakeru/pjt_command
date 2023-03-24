#include "interCheck.h"
int getnum(BinSTreeNode* d){
  int n=0;
  while(d[n].word != NULL){
    n++;
  }
  return n;
}

BinSTreeNode*  getTree(BinSTreeNode* rootNode,BinSTreeNode* d,int *i){
  int x;
  if(rootNode == NULL){
    return 0;
  }
  //ツリーに入っている文字を同じ構造体の中に入れる//
  getTree(rootNode->left,d,i);//左側を探索
  getTree(rootNode->right,d,i);
  x = mystrlen(rootNode->word);
  d[*i].word = (char*)malloc(sizeof(char)*x);
  mystrcpy(d[*i].word,rootNode->word);//dにノードの文字を代
  *i = *i+1;
  return d;
}

BinSTreeNode* uNode(BinSTreeNode *rootNode){
  int x=0;
  int i=0;
  int j=0;
  int k =0;
  int n;
  int nn;
  struct _BinSTreeNode* d;
  struct _BinSTreeNode* dd;
  struct _BinSTreeNode* ddd;
  
  d = (struct _BinSTreeNode*)malloc(sizeof(struct _BinSTreeNode)*5000);
  dd = (struct _BinSTreeNode*)malloc(sizeof(struct _BinSTreeNode)*5000);
  
  d = getTree(rootNode,d,&x);

  n = getnum(d);
  
  for(i = 0 ; i < n ; i++){
    for(j=n-1 ; j > i ; j--){
      if(mystrcmp(d[i].word,d[j].word) == 0){
        dd[k].word = (char*)malloc(sizeof(char)*mystrlen(d[i].word));
        mystrcpy(dd[k].word,d[i].word);
        k++;
        break;
      }
    }
  }

  nn = k/2;
  if(nn == 0){
    ddd = createNode(dd[nn].word);
    ddd->right = NULL;
    ddd->left = NULL;
    for(i=0 ; i < n ; i++){
      free(d[i].word);
    }
    
    for(i=0; i<k ; i++){
      free(dd[i].word);
    }
    free(d);
    free(dd);
    
    return ddd;
  }
  else{
    ddd = createNode(dd[nn].word);
    ddd->right = NULL;
    ddd->left = NULL;
  }

  for(i=0 ; i<k ; i++){
    if(i == nn){
      continue;
    }
    addNode(ddd,createNode(dd[i].word));
  }
  
  for(i=0 ; i < n ; i++){
    free(d[i].word);
  }
  
  for(i=0; i<k ; i++){
    free(dd[i].word);
  }
  
  free(d);
  free(dd);
  return ddd;
}
