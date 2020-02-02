#include<stdio.h>
#include<stdlib.h>
#define UP_BOUND 10
#define LOW_BOUND 0

int main(int argc, char*argv[])
{
  printf("****************************\n");
  printf("你好果果，欢迎进入加法测试！\n");
  printf("****************************\n");

  int iRound=0;
  int iCorrect=0;
  float fCorrectRatio=0.00;
  int iOp1, iOp2;
  int iInput;
  int iContinue=1;
  while(iContinue)
  {
    /* iOp1= (UP_BOUND-LOW_BOUND)*rand(); 
    iOp2= (UP_BOUND-LOW_BOUND)*rand(); */
    iOp1= rand()%UP_BOUND +1;
    iOp2= rand()%UP_BOUND +1;
    
    printf("第%d轮：请计算如下两个数字的和O(∩_∩)O\n",iRound+1);
    printf("%d + %d = ? 请果果输入结果：\n",iOp1,iOp2);
    while(1){
      scanf("%d",&iInput);
      if(iInput>= LOW_BOUND && iInput<= UP_BOUND*2)
        break;
      else
        printf("果果，请输入个合理的结果哦，再输入一个结果：\n");
    }
    if(iInput== iOp1+iOp2) /* a correct hit */
    {
      iRound++;
      iCorrect++;
      fCorrectRatio= 1.00*iCorrect/iRound;
      printf("恭喜果果，答对了！\n总题目数：%d,做对题目数：%d,正确率是：%f\n\n\n",iRound,iCorrect,fCorrectRatio);
    }
    else{
      iRound++;
      fCorrectRatio= 1.00*iCorrect/iRound;
      printf("额。。。答错了！\n总题目数：%d,做对题目数：%d,正确率是：%f\n\n\n",iRound,iCorrect,fCorrectRatio);
    }
    if(iRound<=20)
      continue;
    printf("果果，还要继续吗？继续请输入1，停止请输入0\n");
    while(1){
      scanf(" %d",&iInput);
      if(iInput!=0 && iInput!=1){
        printf("果果，请进行合理输入哦。继续请输入1，停止请输入0\n");
      }else{
        break;
      }
    }
    iContinue= iInput;
  }

}
