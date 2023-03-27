# include "interCheck.h"
void subst(BinSTreeNode *rootNode,char *sstr,char *rstr,int *n){
  char *new_str;
  if(rootNode == NULL){
    return;
  }
  subst(rootNode->right,sstr,rstr,n);
  subst(rootNode->left,sstr,rstr,n);
  new_str = mystrsubst(rootNode->word,sstr,rstr);//入れ替えを行う。
  if(mystrcmp(new_str,rootNode->word) !=0){//探索先で入れ替えが起こったらnを＋１して返す。
    mystrcpy(rootNode->word,new_str);//確認を終えたら代入する。      
    *n+=1;
  }
  free(new_str);
}

int substString(BinSTreeNode *rootNode,char *sstr,char* rstr){
  int m=0;
  //char s='\0';
  subst(rootNode,sstr,rstr,&m);
  //removeNode(rootNode,&s,0);
  return m;
}
