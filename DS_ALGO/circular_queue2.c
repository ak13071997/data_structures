#include<stdio.h>
#include<stdlib.h>            //for exit fun

struct cqueue
{
    int size;
    int arr[50];
    int front,rear;
};
void init(struct cqueue *cq, int s)
{
     cq->size=s;
     cq->front=(cq->size)-1;
     cq->rear=(cq->size)-1;
}
void insert(struct cqueue *cq, int val)
{
     if(!isfull(cq))
     {
          cq->rear=((cq->rear)+1)%cq->size;               //we can skip this and can write next line 
          cq->arr[cq->rear]=val;                          //we can write (*s).arr[++(*s).top]=val
 
     }
     else
     {
           printf("circular queue is full...................\n");
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
      printf("circular queue is empty.........................\n");
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
void display(struct cqueue *cq)
{
    while(!isempty(cq))
    {
       (cq->front)=((cq->front)+1)%cq->size;
        printf("%d  ",cq->arr[cq->front]);
        
    }
}

int main()
{
   struct cqueue cq;
   int size,ch=1;                                  //to use while true loop we take it as 1
   printf("enter the size of circular queue\n");
   scanf("%d",&size);
   init(&cq,size);
   
   while(ch!=0)
   {
       printf("enter 1 to insert element into circular queue'\n");
       printf("enter 2 to remove element from circular queue'\n");
       printf("enter 3 to display circular queue'\n");
       printf("enter 0 to EXIT'\n");
       scanf("%d",&ch);
       switch(ch)
       {
          int elem;
           case 1:
                  printf("enter the elemeent to insert\n");
                  scanf("%d",&elem);
                  insert(&cq,elem);
                  break;
           case 2:
                  int temp;
                  temp=remove_ele(&cq);
                  printf("remove element is = %d \n",temp);
                  break;
           case 3:
                  printf("the circular queue elemnts are\n");
                  display(&cq);
                  printf("\n");
                  //exit(0);
                  break;
           case 0:
                  exit(0);
       }  
   }    
  return 0;
}
