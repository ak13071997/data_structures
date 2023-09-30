#include<stdio.h>

struct stack
{
    int size;
    int arr[20];
    int top;
};
void init(struct stack *s)
{
     (*s).size=20;
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

void main()
{
   struct stack s;
   init(&s);
   int num,rem;
   printf("enter the number to be converted in decimal ");
   scanf("%d",&num);
  
   while(num>0)           //we can write while(num)
   {
     rem=num%2;
     push(&s,rem);
     num=num/2;
   }
   while(!isempty(&s))
   {
      printf("%d  ",pop(&s));
   }
   printf("\n");
   
//return 0;
}
