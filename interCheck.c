#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interCheck.h"

//配布されたものはint main2(void)だった
int main2(void){
  //check createNode
  BinSTreeNode *rootNode = createNode("aa");
  printf("###### check createNode... ######\n");
  printf("rootNode-address : %p\n", rootNode);
  printf("rootNode-word-address: %p\n", rootNode->word);
  printf("rootNode-word : %s\n", rootNode->word);
  printf("rootNode-left-address : %p\n", rootNode->left);
  printf("rootNode-right-address : %p\n", rootNode->right);
  printf("rootNode-pare-address : %p\n", rootNode->pare);
  free(rootNode->word);
  free(rootNode);
  printf("completed!!\n\n");
  
  //check addNode
  rootNode = createNode("aa");
  addNode(rootNode, createNode("aa"));
  addNode(rootNode, createNode("aa"));
  
  printf("###### check addNode... ######\n");
  // printf("rootNode->left-word : %s\n", rootNode->left->word);
  //printf("rootNode->left->left : %p\n", rootNode->left->left);
  //printf("rootNode->left->right : %p\n", rootNode->left->right);
  //printf("rootNode->left->pare : %p\n", rootNode->left->pare);
  printf("rootNode->right-word : %s\n", rootNode->right->word);
  printf("completed!!\n\n");
  
  addNode(rootNode, createNode("aa"));
  addNode(rootNode, createNode("aba"));
  addNode(rootNode, createNode("aa"));
  addNode(rootNode, createNode("cc"));
  addNode(rootNode, createNode("xxsa"));
  addNode(rootNode, createNode("cdc"));
  addNode(rootNode, createNode("aa"));
  addNode(rootNode, createNode("aa"));
  
  //check printTree
  printf("###### check printTree... ######\n");
  printf("---pre order---\n");
  printTree(rootNode, 0);
  printf("---end---\n\n");
  printf("---between order---\n");
  printTree(rootNode, 1);
  printf("---end---\n\n");
  printf("---post order---\n");
  printTree(rootNode, 2);
  printf("--end---\n\n");
  printf("completed!!\n\n");
  
  //check substString & sortBinSTree
  printf("##### check substString & sortBinSTree... #####\n");
//  int numOfSubsted_1 = substString(rootNode, "aa", "xt");
  int numOfSubsted_1 = substString(rootNode, "aa", "xt");
  printf("number of 'aa -> xt' : %d\n", numOfSubsted_1);
  printf("---between order (not sorted)---\n");
  printTree(rootNode, 1);
  printf("---end---\n\n");
  sortBinSTree(rootNode);
  printf("---between order (sorted)---\n");
  printTree(rootNode, 1);
  printf("--end---\n\n");
  int numOfSubsted_2 = substString(rootNode, "bc", "ba");
  printf("number of 'bc -> ba' : %d\n", numOfSubsted_2);
  printf("---between order (not sorted)---\n");
  printTree(rootNode, 1);
  printf("---end--\n\n");
  sortBinSTree(rootNode);
  printf("---between order (sorted)---\n");
  printTree(rootNode, 1);
  printf("---end--\n\n");
  printf("completed\n\n");
  printf("---remove one xt---\n");
  removeNode(rootNode,"xt",1);
  printTree(rootNode,1);
  printf("---end---\n\n");  
  printf("---remove all xt---\n");
  removeNode(rootNode,"xt",0);
  if(rootNode->word == NULL){
    printf("---BinSTree---\n");
    printf("There is no node\n\n");
  }
  else{
    printTree(rootNode,1);
    clearBinSTree(rootNode);
  }
  printf("---end---\n\n");  
  printf("##### check clearBinSTree... #####\n");
  
  //clearBinSTree(rootNode);
  printf("See the following memCheck result!\n");
  return 0;
}
