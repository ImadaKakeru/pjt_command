#include "interCheck.h"
int getnumber(BinSTreeNode* d){
  int n=0;
  while(d[n].word != NULL){
    n++;
  }
  return n;
}

BinSTreeNode*  getBinSTree(BinSTreeNode* rootNode,BinSTreeNode* d,int *i){
  //int x;
  if(rootNode == NULL){
    return 0;
  }
  //ツリーに入っている文字を同じ構造体の中に入れる//
  getBinSTree(rootNode->left,d,i);//左側を探索
  getBinSTree(rootNode->right,d,i);
  //x = mystrlen(rootNode->word);
  //printf("malloc start\n");
  d[*i].word = (char*)malloc(sizeof(char)*1000);
  //printf("malloc end\n");
  mystrcpy(d[*i].word,rootNode->word);//dにノードの文字を代
  //printf("mystrcpy\n");
  *i = *i+1;
  //free(rootNode->word);
  //free(rootNode);
  //rootNode = NULL;
  return d;
}
void sortBinSTree(BinSTreeNode* rootNode){
  struct _BinSTreeNode* d;
  d = (struct _BinSTreeNode*)malloc(sizeof(struct _BinSTreeNode)*1500);
  //printf("tree malloc\n");
  int n;
  int nn;
  int x=0;
  //int y=0;
  int i=0;
  
  d = getBinSTree(rootNode,d,&x);//ノードに入っている文字を全てとってくる。
  //printf("d get\n");
  //printTree(rootNode,1);
  clearBinSTree(rootNode);
  rootNode = NULL;
  n = getnumber(d);//ノードの数を数える。
  //printf("%d\n",n);
  d = DictStruct(d,n); //取ってきたノードの文字を格納した構造体の配列をソートする。
  //printf("dict struct\n");
  nn = n/2;
  //y = mystrlen(d[nn].word);
  rootNode = createNode(d[nn].word);
  
  rootNode->right = NULL;
  rootNode->left = NULL;
  
  for(i=0 ; i<n ; i++){
    if(i == nn){
      continue;
    }
    addNode(rootNode,createNode(d[i].word));
  }
  //printTree(rootNode,1);
  for(i = 0; i < n; i++){
    free(d[i].word); 
  }
  free(d);
  return;
}

