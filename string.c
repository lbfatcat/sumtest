/* string-related functions */

#include "string.h"


static char digitToChar(int);

int intToString(int iPara,char *pString)
{
  if(iPara< MIN_INT || iPara>MAX_INT)
    return -1;
  
  int len=5;
  int times=10000;
  int i=0;
  int iTemp=0;
  while(times>=0)
  {
    iTemp= iPara/times;
    if(iTemp==0 && iPara==0) // o is the single digit number;
    {
      len=1;
      break;
    }
    if(iTemp>0 && iTemp<=9)
      break;
    times/=10;
    len--;
  }
  
  iTemp= iPara;

  for(i=0; i<len; i++)
  {
    pString[i]= digitToChar(iTemp/times);
    iTemp= iTemp-(iTemp/times)*times; // get rid of the highest digit each loop;
    times/=10;
  }
  pString[len]='\0';
  return 0; 
}

static char digitToChar(int iDigit)
{
  char c='-';
  switch(iDigit)
  {
    case 0:
      c='0';
      break;
    case 1:
      c='1';
      break;
    case 2:
      c='2';
      break;
    case 3:
      c='3';
      break;
    case 4:
      c='4';
      break;
    case 5:
      c='5';
      break;
    case 6:
      c='6';
      break;
    case 7:
      c='7';
      break;
    case 8:
      c='8';
      break;
    case 9:
      c='9';
      break;
  }
  return c;
}
