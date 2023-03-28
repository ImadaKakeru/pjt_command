#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define BinSTreeNode
typedef struct _BinSTreeNode{
  char *word;
  struct _BinSTreeNode *left;
  struct _BinSTreeNode *right;
  struct _BinSTreeNode *pare;
}BinSTreeNode;

typedef struct _file{
  char* word;
}file;

//define optionque
typedef struct _option{
  char *word;
  struct _option *next;
}option;

//required functions
BinSTreeNode* createNode(char *word);
void addNode(BinSTreeNode *rootNode, BinSTreeNode *node);
void printTree(BinSTreeNode *rootNode, int order);
int substString(BinSTreeNode *rootNode,char *sstr,char *rstr);
void sortBinSTree(BinSTreeNode *rootNode);
void clearBinSTree(BinSTreeNode *rootNode);
void removeNode(BinSTreeNode *rootNode,char *word,int delall);

//your additional functions
int mystrcmp(char* s1,char *s2);
int mystrlen(char *str);
char* chomp(char *str);
char* mystrcpy(char* s1,char* s2);
char* mystrsubst(char *s1,char *sstr,char *rstr);
struct _BinSTreeNode* DictStruct(struct _BinSTreeNode* d,const int n);
struct _option* createque(char *word);
void addque(option *headque,option *add,option *tail);
struct _file* filesearch(char* filename);
void uNode(BinSTreeNode *rootNode);
struct _file* standard(char *input);
void clearque(struct _option *head,struct _option *tail);
