#include"string.h"
#include<stdio.h>

int main(int argc, char *argv[])
{
  int iNum1=32000;
  int iNum2=2400;
  int iNum3=2;
  int iNum4=0;
  
  char NumStr1[10],NumStr2[10],NumStr3[10],NumStr4[10]; 

  if(intToString(iNum1,NumStr1)!=-1){
    printf("Number 1 is: %s\n",NumStr1);
  }else{
    printf("Number 1 illegal for converstion.\n");
  }

  if(intToString(iNum2,NumStr2)!=-1){
    printf("Number 2 is: %s\n",NumStr2);
  }else{
    printf("Number 2 illegal for converstion.\n");
  }

  if(intToString(iNum3,NumStr3)!=-1){
    printf("Number 3 is: %s\n",NumStr3);
  }else{
    printf("Number 3 illegal for converstion.\n");
  }

  if(intToString(iNum4,NumStr4)!=-1){
    printf("Number 4 is: %s\n",NumStr4);
  }else{
    printf("Number 4 illegal for converstion.\n");
  }

}
