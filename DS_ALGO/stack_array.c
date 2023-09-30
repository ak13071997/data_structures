#include<stdio.h>

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
   
   push(&s1,10);
   push(&s1,30);
   push(&s1,40);
   push(&s1,50);
   
   printf("%d\n",pop(&s1));
    printf("%d\n",pop(&s1));
     printf("%d\n",pop(&s1));
     printf("%d\n",pop(&s1));

return 0;
}
