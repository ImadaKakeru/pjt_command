#include "interCheck.h"
void clearque(struct _option *head,struct _option *tail){
  if(head == NULL){
    return;
  }
  clearque(head->next,tail);
  free(head->word);
  free(head);
}
