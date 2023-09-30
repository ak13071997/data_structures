#include<stdio.h>

struct stack
{
    int size;
    int arr[20];
    int top;
};
void init(struct stack *s)
{
     (*s).size=5;
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
   struct stack s;
   init(&s);
   
   push(&s,10);
   push(&s,30);
   push(&s,40);
   push(&s,50);
   
   printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));
     printf("%d\n",pop(&s));
     printf("%d\n",pop(&s));
return 0;
}
