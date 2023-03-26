#include "interCheck.h"
void unokids(BinSTreeNode *rootNode){//OK
  struct _BinSTreeNode *pare;
  pare = rootNode->pare;
  if(pare != NULL){
    if(pare->right == rootNode){
      pare->right = NULL;
    }
    
    if(pare->left == rootNode){
      pare->left = NULL;
    }
  }
  
  free(rootNode->word);
  rootNode->pare = NULL;
  free(rootNode);
}

BinSTreeNode* uleftsearch(BinSTreeNode *rootNode){
  if(rootNode->left == NULL){
    return rootNode;
  }
  
  else{
    return uleftsearch(rootNode->left);
  }
}

//一致したノードが右だけに子ノードを持っていた時の処理
void uonlyright(BinSTreeNode *rootNode){//OK
  struct _BinSTreeNode *right;
  struct _BinSTreeNode *rightright;
  struct _BinSTreeNode *rightleft;
  right = rootNode->right;
  mystrcpy(rootNode->word,right->word);
  //printf("ok\n");
  if(right->right != NULL){
    rightright = right->right;
    rootNode->right = rightright;
    rightright->pare = rootNode;
  }
  else{
    rootNode->right = NULL;
  }
  
  if(right->left != NULL){
    rightleft = right->left;
    rootNode->left = rightleft;
    rightleft->pare = rootNode;
  }
  else{
    rootNode->left = NULL;
  }
  right->pare = NULL;
  right->right = NULL;
  right->left = NULL;
  free(right->word);
  free(right);
}

BinSTreeNode* urightsearch(BinSTreeNode *rootNode){
  if(rootNode->right == NULL){
    return rootNode;
  }
  else{
    return  urightsearch(rootNode->right);
  }
}
//一致したノードが左だけに子ノードを持っていた時の処理
void uonlyleft(BinSTreeNode *rootNode){
  struct _BinSTreeNode *left;
  struct _BinSTreeNode *leftright;
  struct _BinSTreeNode *leftleft;
  
  left = rootNode->left;
  mystrcpy(rootNode->word,left->word);
  
  if(left->right != NULL){
    leftright = left->right;
    rootNode->right = leftright;
    leftright->pare = rootNode;
  }
  else{
    rootNode->right = NULL;
  }
  
  if(left->left != NULL){
    leftleft = left->left;
    rootNode->left = leftleft;
    leftleft->pare = rootNode;
  }
  else{
    rootNode->left = NULL;
  }
  left->pare = NULL;
  left->right = NULL;
  left->left = NULL;
  free(left->word);
  free(left);
}
    
//一致したノードが左右に子ノードを持っていた時の処理
void udoublekids(BinSTreeNode *rootNode){
  struct _BinSTreeNode *tmp;
  struct _BinSTreeNode *pare;
  struct _BinSTreeNode *right;
  //struct _BinSTreeNode *left;
  
  right = rootNode->right;
  //left = rootNode->left;
  
  if(right->left == NULL){
    mystrcpy(rootNode->word,right->word);
    right->pare = NULL;
    tmp = right->right;
    if(tmp != NULL){
      tmp->pare = rootNode;     
    }
    right->right = NULL;
    free(rootNode->word);
    free(rootNode);
  }
  
  else if(right->left != NULL){
    tmp = uleftsearch(right);//右の子ノードが左の最先端に持つノードを回収
    pare = tmp->pare;
    pare->left = NULL;//最左端の子ノードを孤立させる。
    tmp->pare = NULL;
    mystrcpy(rootNode->word,tmp->word);//ルートに取ってきたノードの文字をコピーする。
    free(tmp->word);//取ってきたものを解放する。
    free(tmp);
  }
  //置き換えたらPJTの性質を満たさなくなるのでソートして整えておく
  sortBinSTree(rootNode);
}
void uallremove(BinSTreeNode *rootNode,char *word){
  if(rootNode == NULL){
    return;
  }
  
  uallremove(rootNode->left,word);
  uallremove(rootNode->right,word);
  
  if(mystrcmp(rootNode->word,word) == 0){
    //子を持たない時
    if(rootNode->left == NULL && rootNode->right == NULL){
      //printf("nokids\n");
      unokids(rootNode);
    }
    
    //両方に子がいる時
    else if(rootNode->left != NULL && rootNode->right != NULL){
      //printf("doublekids\n");
      udoublekids(rootNode);
    }
    
    //右だけに子を持つとき
    else if(rootNode->left == NULL){
      //printf("onlyright\n");
      uonlyright(rootNode);
    }
    
    //左だけに子を持つ時
    else if(rootNode->right == NULL){
      //printf("onlyleft\n");
      uonlyleft(rootNode);
    }
  }
  
  else{
    return;
  }
}
void uNode(BinSTreeNode *rootNode){

  if(rootNode == NULL){
    return;
  }
  uNode(rootNode->left);
  uNode(rootNode->right);
  if(rootNode->right != NULL){
    uallremove(rootNode->right,rootNode->word);
  }
  
  if(rootNode->right != NULL){
    uallremove(rootNode->left,rootNode->word);
  } 
}
