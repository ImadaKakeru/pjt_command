char* mystrcpy(char* s1,const char* s2){
  int i=0;
  while(s2[i] != '\0'){
    s1[i] = s2[i];
    i++;
  }
  s1[i]=s2[i];
  return s1;
}
