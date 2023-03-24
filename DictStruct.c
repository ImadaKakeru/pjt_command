#include "interCheck.h" 
 BinSTreeNode* DictStruct(BinSTreeNode* d,int n){ 
   int i,j; 
   int x; 
   struct _BinSTreeNode tmp;
   for(i=0 ; i < n ; i++){
     for(j= n-1 ; j > i ; j--){
       x = mystrcmp(d[j-1].word,d[j].word);
       if(x == 1){
         tmp = d[j-1];
         d[j-1] = d[j];
         d[j] = tmp;
       }
     }
   }
   return d;
 } 
