#include<stdio.h>
#include<stdlib.h> /* use the rand function */
#include<string.h>
#define UP_BOUND 10 /* the smallest integer for the addition test */
#define LOW_BOUND 0 /* the largest integer for the addition test */
#define BUF_LENGTH 20 /* the MAX length of the excercise */

#define TYPE_1_STR "()+op1=op2"
#define TYPE_2_STR "op1+()=op2"
#define TYPE_3_STR "op1+op2=()"

static char pResult[200];

int generateExcercise(char *pExString);
int resetBuffer(char * pBuf, int length);
int getShortResult(int iTotal, int iCorrect, char *pRstString);

int main(int argc, char*argv[])
{
  printf("****************************\n");
  printf("你好果果，欢迎进入加法测试！\n");
  printf("****************************\n");

  int iRound=0; /* the round count */
  int iCorrect=0; /* the number of correct hits */
  float fCorrectRatio=0.00;

  int iInput;					/* the integer for input */
  int iContinue=1;				/* the flag controlling the test loop, default to be true */
  char exString[BUF_LENGTH];
  int iAnswer;
  while(iContinue)
  {
    resetBuffer(exString,BUF_LENGTH);
    iAnswer=generateExcercise(exString);   
    if(iAnswer==-1)
    {
        printf("出题错误，系统异常退出！┭┮﹏┭┮\n\n");
        return -1;
    }

    printf("\n***** 第%d轮 *******\n",iRound+1);
    printf("请计算:  \n");
    printf("%s ? 请果果输入结果：\n",exString);
    printf("Eason: ");
    while(1){
      scanf("%d",&iInput);
      if(iInput>= LOW_BOUND && iInput<= UP_BOUND*2)
        break;
      else
        printf("果果，请输入个合理的结果哦，再输入一个结果：\n");
    }
    if(iInput== iAnswer) /* a correct hit */
    {
      iRound++;
      iCorrect++;
      fCorrectRatio= 1.00*iCorrect/iRound;
      //printf("恭喜果果，答对了！\n总题目数：%d,做对题目数：%d,正确率是：%f\n\n\n",iRound,iCorrect,fCorrectRatio);
      printf("恭喜果果，答对了！\n");
      if(getShortResult(iRound,iCorrect,pResult)==-1){
        printf("%s\n",pResult);
        return -1;
      }
      printf("%s",pResult);
    }
    else{
      iRound++;
      fCorrectRatio= 1.00*iCorrect/iRound;
      /* old version of printing result in each loop */
      // printf("额。。。答错了！\n总题目数：%d,做对题目数：%d,正确率是：%f\n\n\n",iRound,iCorrect,fCorrectRatio);
      printf("额。。。答错了！\n");
      if(getShortResult(iRound,iCorrect,pResult)==-1){
        printf("%s\n",pResult);
        return -1;
      }
      printf("%s",pResult);
    }
    if(iRound<=20)
      continue;
    printf("果果，还要继续吗？继续请输入1，停止请输入2\n");
    while(1){
      scanf(" %d",&iInput);
      if(iInput!=1 && iInput!=2){
        printf("果果，请进行合理输入哦。继续请输入1，停止请输入0\n");
      }else{
        break;
      }
    }
    iContinue= iInput;
  }

}

int getShortResult(int iTotal, int iCorrect, char *pRstString)
{
  if(iTotal<0 || iCorrect<0 || iTotal<iCorrect){
    sprintf(pRstString,"illegal aruments input for getShortResult function call");
    return -1;
  }
  char pStatistics[100];
  //char line[]="---------------------------------------\n";
  sprintf(pRstString,"-------------------------------------------------\n");
  sprintf(pStatistics,"总题数：%d\t做对数：%d\t正确率：%.2f%%\n",iTotal,iCorrect,100.00*iCorrect/iTotal);
  pRstString= strncat(pRstString,pStatistics,100);
  pRstString= strncat(pRstString,"-------------------------------------------------\n",100);
  return 0;
}

int resetBuffer(char * pBuf, int length)
{
    if(length<=0)
      return -1;
    int i=0;
    while(i<length)
      pBuf[i++]='\0';
    return 0;
}

int generateExcercise(char *pExString)
{
   int iOp1, iOp2; /* the two addition operands */
   int iAnswer;
    int iTypeID= rand()%3+1; /* randomly generate the excercise type */
    switch(iTypeID)
    {
      case 1: /* type 1: ()+op1=op2  */    
        while(1){ /* generate qualified operands */
            iOp1= rand()%UP_BOUND +1;
            iOp2= rand()%UP_BOUND +1;
            if(iOp1<iOp2)
              break;
        }
        sprintf(pExString,"( )+%d=%d",iOp1,iOp2);
        iAnswer= iOp2-iOp1; 
        break;
      case 2: /* type 2: op1+()=op2 */
        while(1){ /* generate qualified operands */
            iOp1= rand()%UP_BOUND +1;
            iOp2= rand()%UP_BOUND +1;
            if(iOp1<iOp2)
              break;
        }
        sprintf(pExString,"%d+( )=%d",iOp1,iOp2);
        iAnswer= iOp2-iOp1;
        break;
      case 3: /* type 3: op1+op2=() */
        iOp1= rand()%UP_BOUND +1;
        iOp2= rand()%UP_BOUND +1;
        sprintf(pExString,"%d+%d=( )",iOp1,iOp2);
        iAnswer= iOp1+iOp2;
        break;
      default:
        iAnswer= -1;;
    }  
    return iAnswer;
}
