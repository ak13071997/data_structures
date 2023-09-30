#include<stdio.h>

struct queue
{
    int size;
    int arr[50];
    int front,rear;
};
void init(struct queue *q)
{
     q->size=20;
     q->front=-1;
     q->rear=-1;
}
void insert(struct queue *q, int val)
{
     if(!isfull(q))
     {
          (q->rear)++;                //we can skip this and can write next line 
          q->arr[q->rear]=val;   //we can write (*s).arr[++(*s).top]=val
 
     }
     else
     {
           printf("stack is full..");
     }

}
int remove_ele(struct queue *q)
{
    int temp=-1;
    if(!isempty(q))
    {    
         (q->front)++;
         temp=q->arr[q->front];
         
    }
    else
    {
      q->rear=q->front=-1;         //use to set the index position to home position= at -1
      printf("queue is empty....");
    }
  return temp;
}
int isfull(struct queue *q)
{
      if(q->rear==(q->size)-1)
      {
           return 1;
      }
      else
      {
           return 0;
      }
}
int isempty(struct queue *q)
{
      if(q->rear==q->front)             //it is only empty when front and top at the same position
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
   struct queue q;
   init(&q);
   
   insert(&q,10);
   insert(&q,30);
   insert(&q,40);
   insert(&q,50);
   
   printf("%d\n",remove_ele(&q));
   printf("%d\n",remove_ele(&q));
   printf("%d\n",remove_ele(&q));
   printf("%d\n",remove_ele(&q));
   
   printf("\n");
return 0;
}
