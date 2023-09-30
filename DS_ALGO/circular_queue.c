#include<stdio.h>

struct cqueue
{
    int size;
    int arr[50];
    int front,rear;
};
void init(struct cqueue *cq)
{
     cq->size=5;
     cq->front=(cq->size)-1;
     cq->rear=(cq->size)-1;
}
void insert(struct cqueue *cq, int val)
{
     if(!isfull(cq))
     {
          cq->rear=((cq->rear)+1)%cq->size;               //we can skip this and can write next line 
          cq->arr[cq->rear]=val;   //we can write (*s).arr[++(*s).top]=val
 
     }
     else
     {
           printf("circular queue is full..\n");
     }

}
int remove_ele(struct cqueue *cq)
{
    int temp=-1;
    if(!isempty(cq))
    {    
         (cq->front)=((cq->front)+1)%cq->size;
         temp=cq->arr[cq->front];
         
    }
    else
    {        
      printf("circular queue is empty....");
    }
  return temp;
}
int isfull(struct cqueue *cq)
{
      if(cq->front==((cq->rear)+1)%cq->size)
      {
           return 1;
      }
      else
      {
           return 0;
      }
}
int isempty(struct cqueue *cq)
{
      if(cq->rear==cq->front)             //it is only empty when front and top at the same position
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
   struct cqueue cq;
   init(&cq);
   
   insert(&cq,10);
   insert(&cq,30);
   insert(&cq,40);
   insert(&cq,50);
  // insert(&cq,70);                     //this wil show circular queue is full
   printf("%d\n",remove_ele(&cq));
   printf("%d\n",remove_ele(&cq));
   printf("%d\n",remove_ele(&cq));
   printf("%d\n",remove_ele(&cq));
  // printf("%d\n",remove_ele(&cq));     //this will show circular queue is empty
   printf("\n");
return 0;
}
