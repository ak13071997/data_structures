#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int arr[20];
    int top;
};
void init(struct stack *s)
{
     (*s).size=10;
     (*s).top=-1;
}
void push(struct stack *s, int val)
{
     if(!isfull(s))
     {
          (*s).top++;                //we can skip this and can write next line 
          (*s).arr[(*s).top]=val;   //we can write (*s).arr[++(*s).top]=val
 
     }
     else
     {
           printf("stack is full..");
     }

}
int pop(struct stack *s)
{
    int temp=-1;
    if(!isempty(s))
    {    
         temp=(*s).arr[(*s).top];
         (*s).top--;
    }
  return temp;
}
int isfull(struct stack *s)
{
      if((*s).top==(*s).size-1)
      {
           return 1;
      }
      else
      {
           return 0;
      }
}
int isempty(struct stack *s)
{
      if((*s).top==-1)
      {
           return 1;
      }
      else
      {
           return 0;
      }
}

int main()
{
   struct stack s1;
   init(&s1);
  
     struct stack s2;
       init(&s2);
     int num,rem,num2,temp,n;
     printf("enter the number to be pallindrome\n");
     scanf("%d",&num);
     temp=num;
     while(num>0)
     {  
        rem=num%10;
        push(&s1,rem);
        num=num/10;
     }
     while(!isempty(&s1))
     {
       push(&s2,pop(&s1));
     }
     n=0;
     while(!isempty(&s2))
    {
        num2=pop(&s2);
        n=n*10+num2;
      
    }
     
    if(temp==n){
            printf("the number is palindrome \n");
            }
          else{
          printf("the number is not palindrome\n");
          }
return 0;
}
