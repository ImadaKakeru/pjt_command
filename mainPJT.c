#include "interCheck.h"
char* testcase(char* test,char* argv){
  int i=0;
  int k = 0;
  test = (char*)malloc(sizeof(char)*mystrlen(argv));
  
  while(argv[i] != '/'){
    i++;
  }
  i++;

  while(argv[i] != '\0'){
    test[k] = argv[i];
    k++;
    i++;
  }
  test[k] = '\0';
  return test;
}
int filecheck(char* file){
  FILE* fp;
  fp = fopen(file,"r");
  if(fp == NULL){
    return 0;
    }
  else{
    return 1;
  }
}
int commandsearch(char* word){
  int i = 1;
  while(word[i] != '/'){
    i++;
  }
  i = i+1;

  while(word[i] != '/'){
    i++;
  }
  if(word[i+1] == '\0'){
    return 0;
  }
  else{
    return 1;
  }
}
char* firstsearch(char* word,char* s1){
  int i=1;
  int n=0;
  while(word[i] != '/'){
    s1[n] = word[i];
    n++;
    i++;
  }
  s1[n] = '\0';
  return s1;
}

char* secondsearch(char* word,char* s2){
  int i=1;
  int n=0;
  while(word[i] != '/'){
    i++;
  }

  i = i+1;
  
  while(word[i] != '/'){
    s2[n] = word[i];
    n++;
    i++;
  }
  s2[n] = '\0';

  return s2;
}


int main(int argc,char* argv[]){
  struct _option *head=NULL;
  struct _option *oldhead;
  struct _option *tail=NULL;
  struct _option *headque;
  struct _file *f;
  struct _BinSTreeNode *rootNode = NULL;
  char* testfile=NULL;
  int i=1;
  int j=0;
  int x;
  int filecount=0;
  char soption[3]; //option_number = 1
  soption[0] = '-';
  soption[1] = 's';
  soption[2] = '\0';
  
  char poption[3] = "-p"; //option_number = 2
  poption[0] = '-';
  poption[1] = 'p';
  poption[2] = '\0';
  
  char uoption[3] = "-u"; //option_number = 3
  uoption[0] = '-';
  uoption[1] = 'u';
  uoption[2] = '\0';
  
  char roption[3] = "-r"; //option_number = 4
  roption[0] = '-';
  roption[1] = 'r';
  roption[2] = '\0';
  
  char *input;
  //char *nonword = '\0';
  char *s1;
  char *s2;
  int s;
  
  int options[100];       //option情報を格納

  int option_count = 0; //optionの数を格納
  int command;
  int p_number = 1;//printTreeの走査方法を格納。
  int pcount = 0;
  int scount =0;
  int ucount = 0;
  FILE* fp;
  while(i < argc){
    //optionの整理
    if(argv[i][0] == '-'){
      //soption
      if(mystrcmp(argv[i],soption) == 0){
        options[option_count] = 1;
        option_count ++;
        if((i+1) ==  argc){
          printf("usage: ERROR(incorrect -s format follow -s/match/replace/ )\n");
          clearque(head,tail);
          return 0;
        }
        else if(argv[i+1][0] != '/'){
          printf("usage: ERROR(incorrect -s format follow -s/match/replace/)\n");
          clearque(head,tail);
          return 0;
        }
        
        else{
          if(head == NULL){
            headque = createque(argv[i+1]);
            head = headque;
            tail = headque;
          }
          else{
            addque(headque,createque(argv[i+1]),tail);
          }
        }
        i = i+2;
      }
      //p option
      else if(mystrcmp(argv[i],poption) == 0){
        pcount++;
        //ここで-pが重複していないか調べる関数を実装
        if(pcount > 1){
          printf("usage: ERROR(incorrect -p format '-p' is one)\n");
          return 0;
        }
        if(i+1 == argc){
          i++;
          break;
        }
        //pの次の引数が0〜2だった時それがファイルじゃないか調べる関数を実装
        if( atoi(argv[i+1]) == 0 || atoi(argv[i+1]) == 1 || atoi(argv[i+1]) == 2){
          if( filecheck(argv[i+1]) == 0){
            p_number = atoi(argv[i+1]);
            if(i+2 != argc){
              i = i+2;
            }
          }
          else{
            p_number = 1;
            i++;
          }
        }
        else{
          i++;
        }
      }
      
      //u option
      else if(mystrcmp(argv[i],uoption) == 0){
        ucount++;
        i++;
      }
      
      //r option
      else if(mystrcmp(argv[i],roption) == 0){
        options[option_count] = 4;
        option_count ++;
        if((i+1) == argc){
          printf("usage: ERROR(incorrect -r format follow -r/match/delall/ )\n");
          clearque(head,tail);
          return 0;
        }
        
        else if(argv[i+1][0] != '/'){
          printf("usage: ERROR(incorrect -r format follow -r/match/delall/ )\n");
          clearque(head,tail);
          return 0;
        }
        
        else{
          if(head == NULL){
            headque = createque(argv[i+1]);
            head = headque;
            tail = headque;
          }
          else{
            addque(headque,createque(argv[i+1]),tail);
          }
        }
        i = i+2;
      }
      else{
        printf("usage: ERROR(options are invalid\n)");
        return 0;
      }
    }
    //optionが出なくなったら抜ける。
    else{
      break;
    }
  }
  while( i < argc){
    if(argv[i][0] == '-'){
      printf("usage: some options are invalid\n");
      clearBinSTree(rootNode);
      free(testfile);
      return 0;
    }
    else{
      free(testfile);
    }
    fp = fopen(argv[i],"r");
    j = 0;
    if(fp != NULL){
      f = filesearch(argv[i]);
      if(rootNode == NULL){
        rootNode = createNode(f[j].word);
        free(f[j].word);
        j++;
        while(f[j].word != NULL){
          addNode(rootNode,createNode(f[j].word));
          free(f[j].word); 
          j++;
        }
      }
      else{
        while(f[j].word != NULL){
          addNode(rootNode,createNode(f[j].word));
          free(f[j].word);
          j++;
        }
      }
      filecount++;
      i++;
      fclose(fp);
      free(f);
    }
    else{
      printf("usage: file open ERROR\n");
      return 0;
    }
  }
  //filecountが０だったら標準入力にする。---OK---
  if(filecount == 0){
    input = (char*)malloc(sizeof(char)*1000);
    while(fgets(input,256,stdin) != NULL){
      j =0;
      f = standard(input);
      if(rootNode == NULL){
        rootNode = createNode(f[j].word);
        free(f[j].word);
        j++;
        while(f[j].word != NULL){
          addNode(rootNode,createNode(f[j].word));
          free(f[j].word); 
          j++;
        }
      }
      else{
        while(f[j].word != NULL){
          addNode(rootNode,createNode(f[j].word));
          free(f[j].word);
          j++;
        }
      }
      free(f);
    }
    free(input);
    //free(f);
    if(j == 0){
      printf("---input ERROR---\n");
      return 0;
    }
  }
  
  //実際の処理を行う。ok
  if(option_count == 0){
  }
  for(int k=0 ; k < option_count ; k++){
    //s-option
    if(options[k] == 1){
      scount++;
      command = commandsearch(head->word);
      if(command == 1){
        printf("usage: -s /word/word/\n");
        clearBinSTree(rootNode);
        clearque(head,tail);
        return 0;
      }
      //構造体optionのheadを取ってくる。フリーも同時に行う。
      oldhead = head;
      x = mystrlen(head->word);
      s1 = (char*)malloc(sizeof(char)*(x+1));
      s2 = (char*)malloc(sizeof(char)*(x+1));
      s1 = firstsearch(head->word,s1);
      s2 = secondsearch(head->word,s2);
      substString(rootNode,s1,s2);
      free(s1);
      free(s2);
      free(head->word);
      if(head->next != NULL){
        head = head->next;
      }
      free(oldhead);
    }
    //r-option
    else{
      oldhead = head;
      x = mystrlen(head->word);
      s1 = (char*)malloc(sizeof(char)*(x+1));
      s2 = (char*)malloc(sizeof(char)*(x+1));
      
      s1 = firstsearch(head->word,s1);
      s2 = secondsearch(head->word,s2);
      s = *s2;
      if(s < 48 || s >57){
        removeNode(rootNode,s1,1);
        free(s1);
        free(s2);
      }
      else if(atoi(s2)  == 0){
        if(mystrlen(s2) != 1){
          if(rootNode->word == NULL){
            free(s1);
            free(s2);
            //free(head->word);
            //free(head);
            break;
          }
          removeNode(rootNode,s1,1);
        }
        else{
          if(rootNode->word == NULL){
            free(s1);
            free(s2);
            if(head->word != NULL){
              free(head->word);
              free(head);
            }
            break;
          }
          removeNode(rootNode,s1,atoi(s2));
        }
        free(s1);
        free(s2);
      }
      else{
        if(rootNode->word == NULL){
          free(s1);
          free(s2);
          //free(head->word);
          //free(head);
          break;
        }
        removeNode(rootNode,s1,atoi(s2));
        free(s1);
        free(s2);
      }
      free(head->word);
      //free(oldhead);
      if(head->next != NULL){
        head = head->next;
      }
      free(oldhead);
    }
  }
  // printTree(rootNode,1);
  if(scount != 0){
    if(rootNode->right == NULL){
      
    }
    else{
      sortBinSTree(rootNode);
      removeNode(rootNode,"\0",0);
    }
  }
  if(ucount == 1){
    if(rootNode->word != NULL){
      uNode(rootNode);
    }
  }
  else if(ucount == 0){
    
  }
  else{
    printf("usage: u option should not duplicated\n");
    clearBinSTree(rootNode);
    return 0;
  }
  
  if(rootNode->word == NULL){
    printf("---BinSTree---\n");
    printf("There is no node\n");
    free(rootNode);
    //free(rootNode->word);
  }
  else{
    printf("---BinSTree---\n");
    printTree(rootNode,p_number);
    clearBinSTree(rootNode);
  }
  //clearBinSTree(rootNode);
  return 0;
}

