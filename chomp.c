char* chomp(char* str){
  int i=0;
  while(str[i]!='\0'){
    if(str[i]=='\n'){
      str[i]='\0';
    }
    else{
      i++;
    }
  }
  return str;
}
