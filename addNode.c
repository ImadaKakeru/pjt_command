#include "interCheck.h"
void addNode(BinSTreeNode *rootNode,BinSTreeNode *Node){ //ルートノードと追加するノード
  int n;
  n = mystrcmp(rootNode->word,Node->word);
  if(n == 1){//ルートノードのほうが大きい時
    if(rootNode->left == NULL){//左側の枝が空いていればそこにNodeを追加する。
      rootNode->left = Node;
      Node->pare = rootNode;
      
    }
    else{
      addNode(rootNode->left,Node);
    }
  }
  
  else{
    if(rootNode->right == NULL){//右側の枝が空いていればそこにNodeを追加する
      rootNode->right = Node;
      Node->pare = rootNode;  
    }
    else{
      addNode(rootNode->right,Node);
    }
  }
}
