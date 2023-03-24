#include "interCheck.h"
struct _BinSTreeNode* SortStruct(struct _BinSTreeNode* d,const int n){
  int i,j;
  struct _BinSTreeNode tmp;

  for(i = 0 ; i < n ; i++){
    for(j = n-1 ; j>i ; j--){
      if(d[j-1].word > d[j].word){
        tmp = d[j];
        d[j] = d[j-1];
        d[j-1] = tmp;
      }
    }
  }
  return d;
}

