#include "interCheck.h"

void addque(option *headque,option *add,option *tail){
  if(headque->next == NULL){
    headque->next = add;
    tail = add;
  }
  
  else{
    addque(headque->next,add,tail);
  }
}
