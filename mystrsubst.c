#include "interCheck.h"
int onaji(char* s1,char* s2,int n){
  int i = 0;
  for(i =0 ; i < n ; i++){
    if(s1[i] != s2[i]){
      return 0; //違う文字があったら０を返す。
    }
  }
  return 1; // 同じだったらfor文を抜けて１を返す。
}
char* mystrsubst(char*s1,char* sstr,char* rstr){
  int x,y,z;
  int i=0;
  int j=0;
  int k=0;
  int n=0;
  char* new_str;
  
  x = mystrlen(s1);
  y = mystrlen(sstr);
  z = mystrlen(rstr);

  new_str = (char*)malloc(sizeof(char)*((x+1)*(y+1)*(z+1)));

  char ss[y]; //s2と同じ長さでs1からとてきた配列
  if(y == 0){
    mystrcpy(new_str,s1);
    return new_str;
  }

  while(s1[i] != '\0'){
    if( i+y > x){ //s1の残りがs2よりも短いとき ok
      while(s1[i] != '\0'){
        new_str[n] = s1[i];
        i++;
        n++;
      }
      break;
    }
    for(j=0 ; j < y ; j++){ //s2と同じ長さだけs1をとってssにいれる。
      ss[j] = s1[i];
      i++; // y分配列をずらす。
    }
    ss[j+1] = '\0';
    
    if(onaji(ss,sstr,y) == 1){ // ssとs2が同じの時
      for(k = 0 ; k < z ; k ++){
        new_str[n] = rstr[k]; // newにs3を入れる。
        n++;
      }
    }
    else{
      new_str[n] = s1[i-y];
      n++;
      i = i - y + 1; //ssとs2が同じでないとき、s1を１つずらして戻る。
    }
  }
  new_str[n]= '\0';
  return new_str;
  
}
