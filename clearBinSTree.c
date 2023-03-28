#include "interCheck.h"
void clearBinSTree(BinSTreeNode *rootNode){
  if(rootNode == NULL){
    return;
  }
  clearBinSTree(rootNode->left);
  clearBinSTree(rootNode->right);
  free(rootNode->word);
  free(rootNode);
  //rootNode = NULL;
}
