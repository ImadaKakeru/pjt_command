#include "interCheck.h"
void printTree(BinSTreeNode *rootNode,int order){
  if(order == 0){//前順探索
    if(rootNode == NULL){
      return;
    }
    else if(rootNode != NULL){
      printf("%s\n",rootNode->word);//訪問したらすぐ出力する。
      printTree(rootNode->left);//左側を探索。左側に行けなくなったら抜ける。
      printTree(rootNode->right);//右側を探索。右側に行けなくなったら抜けて１つ上の階層に戻る。根の場合は処理が終わる。
    }
  }

  else if(order == 1){//間順探索
    if(rootNode == NULL){ //ここの条件ではrootNodeとしているが後に左枝のポインタ、右枝のポインタが入ることで先に行けなくなったら戻ることを示している。
      return;
    }
    else if(rootNode != NULL){
      printTree(rootNode->left);//行けるところまで左側に進む。
      printf("%s\n",rootNode->word);//左側に行けなくなったら出力する。
      printTree(rootNode->right);//行けるところまで右側まで進む
    }//右枝左枝どちらも探索し切ったら１つ上に戻る。
  }
  
  else{//後順探索
    if(rootNode != NULL){
      printTree(rootNode->left);
      printTree(rootNode->right);
      printf("%s\n",rootNode->word);
    }  
    else if(rootNode == NULL){
      return;
    }
  }
}
