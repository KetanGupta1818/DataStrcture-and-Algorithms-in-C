#include<stdio.h>
void move(int, char, char,char);
int main()
{
    int n = 3;
    move(n,'A','B','C');
    return 0;
}
void move(int n, char sp, char ap, char ep)
{
    if(n==1)
    {
        printf("In If block..\n");
        printf("Move disk from peg %c to peg %c ***************\n", sp, ep);
        printf("Start block is %c Apparent block is %c End block is %c \n", sp, ap, ep);
    }
    else
    {
        printf("Satement 1   The vlaue of n is: %d\n", n);
        printf("Start block is %c Apparent block is %c End block is %c \n", sp, ap, ep);
        move(n-1, sp, ep, ap);
        printf("Satement 2 The vlaue of n is: %d\n", n);
        printf("Start block is %c Apparent block is %c End block is %c \n", sp, ap, ep);
        move(1,sp,' ',ep);
        printf("Satement 3 The vlaue of n is: %d\n", n);
        printf("Start block is %c Apparent block is %c End block is %c \n", sp, ap, ep);
        move(n-1,ap,sp,ep);
        printf("Satement 4 The vlaue of n is: %d\n", n);
        printf("Start block is %c Apparent block is %c End block is %c \n", sp, ap, ep);
    }
}
