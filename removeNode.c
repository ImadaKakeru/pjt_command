#include "interCheck.h"

//一致したノードが子ノードを持っていなかった時の処理
void nokids(BinSTreeNode *rootNode){//OK
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

BinSTreeNode* leftsearch(BinSTreeNode *rootNode){
  if(rootNode->left == NULL){
    return rootNode;
  }
  
  else{
    return leftsearch(rootNode->left);
  }
}

//一致したノードが右だけに子ノードを持っていた時の処理
void onlyright(BinSTreeNode *rootNode){//OK
  struct _BinSTreeNode *right;
  struct _BinSTreeNode *rightright;
  struct _BinSTreeNode *rightleft;
  right = rootNode->right;
  mystrcpy(rootNode->word,right->word);
  printf("ok\n");
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

BinSTreeNode* rightsearch(BinSTreeNode *rootNode){
  if(rootNode->right == NULL){
    return rootNode;
  }
  else{
    return  rightsearch(rootNode->right);
  }
}
//一致したノードが左だけに子ノードを持っていた時の処理
void onlyleft(BinSTreeNode *rootNode){
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
void doublekids(BinSTreeNode *rootNode){
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
    tmp = leftsearch(right);//右の子ノードが左の最先端に持つノードを回収
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

void rootremove(BinSTreeNode *rootNode){
  struct _BinSTreeNode *tmp;
  struct _BinSTreeNode *pare;
  struct _BinSTreeNode *right;
  //struct _BinSTreeNode *left;

  right = rootNode->right;
  //left = rootNode->left;
  if(rootNode->left == NULL && rootNode->right == NULL){
    printf("0\n");
    free(rootNode->word);
    free(rootNode);
    rootNode->word = NULL;
    rootNode = NULL;
    return;
  }

  else if(rootNode->left != NULL && rootNode->right != NULL){
    printf("1\n");
    if(right->left == NULL){//OK
      mystrcpy(rootNode->word,right->word);
      right->pare = NULL;
      tmp = right->right;
      if(tmp != NULL){
        tmp->pare = rootNode;     
      }
      right->right = NULL;
      rootNode->right = tmp;
      free(right->word);
      free(right);
    }

    else if(right->left != NULL){
      printf("2\n");
      printf("righthaveleft\n");
      tmp = leftsearch(right);//右の子ノードが左の最先端に持つノードを回収
      pare = tmp->pare;
      pare->left = NULL;//最左端の子ノードを孤立させる。
      tmp->pare = NULL;
      mystrcpy(rootNode->word,tmp->word);//ルートに取ってきたノードの文字をコピーする。
      free(tmp->word);//取ってきたものを解放する。
      free(tmp);
    }
  }

  else if(rootNode->left == NULL){
    printf("3\n");
    onlyright(rootNode);
  }
  else{
    printf("4\n");
    onlyleft(rootNode);
  }
}

void allremove(BinSTreeNode *rootNode,char *word){
  if(rootNode == NULL){
    return;
  }
  
  allremove(rootNode->left,word);
  allremove(rootNode->right,word);
  
  if(mystrcmp(rootNode->word,word) == 0){
    //子を持たない時
    if(rootNode->left == NULL && rootNode->right == NULL){
      printf("nokids\n");
      nokids(rootNode);
    }
    
    //両方に子がいる時
    else if(rootNode->left != NULL && rootNode->right != NULL){
      printf("doublekids\n");
      doublekids(rootNode);
    }
    
    //右だけに子を持つとき
    else if(rootNode->left == NULL){
      printf("onlyright\n");
      onlyright(rootNode);
    }
    
    //左だけに子を持つ時
    else if(rootNode->right == NULL){
      printf("onlyleft\n");
      onlyleft(rootNode);
    }
  }
  
  else{
    return;
  }
}

void oneremove(BinSTreeNode *rootNode,char *word){
  if(rootNode == NULL){
    return;
  }
    //消す文字がルートノードより小さかったら
  if(mystrcmp(rootNode->word,word) == 1){
    oneremove(rootNode->left,word);
  }
  
    //文字が一致した時
  if(mystrcmp(rootNode->word,word) == 0){
      //子を持たない時
    if(rootNode->left == NULL && rootNode->right == NULL){
      printf("nokids\n");
      nokids(rootNode);
      return;
    }
    
    //両方に子がいる時
    else if(rootNode->left != NULL && rootNode->right != NULL){
      printf("double\n");
      doublekids(rootNode);
      return;
    }
    
    //右だけに子を持つとき
    else if(rootNode->left == NULL){
      printf("right\n");
      onlyright(rootNode);
      return;
    }
    
    //左だけに子を持つ時
    else if(rootNode->right == NULL){
      printf("left\n");
      onlyleft(rootNode);
      return;
    }
  }
  
  //消す文字がルートノードより大きかったら
  else if(mystrcmp(rootNode->word,word) == -1){
    
    oneremove(rootNode->right,word);  
  }      
}
void removeNode(BinSTreeNode *rootNode,char *word,int delall){
  //全削除する場合
  if(delall == 0){
    if(rootNode == NULL){
      return;
    }
    if( mystrcmp(rootNode->word,word) == 0 ){
      printf("rootremove\n");
      rootremove(rootNode);
      if(rootNode->word  == NULL){
        return;
      }
      removeNode(rootNode,word,delall);
    }
    else{
      printf("allremove\n");
      allremove(rootNode,word);
    }
  }
  
  //一番近いものを削除する時
  else{
    if(mystrcmp(rootNode->word,word) == 0){
      rootremove(rootNode);
      return;
    }
    oneremove(rootNode,word);  
  }
}
