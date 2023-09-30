#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// add at position using doubly link_list
struct node
{
   int data;
   struct node *next;
   struct node *prev;
};
void AddatBegin(struct node **phead,int val)
{
    struct node *temp;                                  //creating temp node to be added at the begening
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    if(*phead==NULL)                //if there is no existing nodes then the temp node is first node
    {
       *phead=temp;
    }
    else
    {
       temp->next=*phead;
       (*phead)->prev=temp;
       *phead = temp;
    }

}
void AddatPosition(struct node **phead, int pos, int val)
{   
    struct node *trav;
    struct node *temp;                                  //creating temp node to be added at the begening
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    //trav=*phead;
    if(pos==1)                    //for first positon 
    {
       AddatBegin(phead,200);
    }
    else if(pos=9)
    {
       AddatEnd(phead,400);
    }
    else
    {
        trav=*phead;
        while(pos>2)            //for(int i=0; i<pos-2; i++)
        {
            trav=trav->next;
            pos--;
        }
        temp->next=trav->next;
       trav->next->prev=temp;
       temp->prev=trav;
       trav->next=temp;
    }
 
}
void AddatEnd(struct node **phead, int val)
{
    struct node *trav;
    struct node *temp;                      //to create a node to be added
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    
    if(*phead==NULL)                 //if there is no existing node them temp node will assign as first node
    {
         *phead=temp;
    }
    else                               //if existing node is there then it will add temp node at the end 
    {
       trav=*phead;
       
       while(trav->next!=NULL)
       {
            trav=trav->next;
       }
         trav->next=temp;
         temp->prev=trav;
         //tail=temp;
    }
}
void display(struct node *head)
{
   struct node *trav = head;
   while(trav!=NULL)
   {
        printf("%d  ",trav->data);
        trav=trav->next;
   }
   printf("\n");
}
void ReverseDisplay(struct node *phead)
{
   struct node *trav=phead;
   while(trav->next!=NULL)
   {
        trav=trav->next;
   }
   while(trav!=NULL)
   {
      printf("%d  ",trav->data);
      trav=trav->prev;
   }
  
}

int main()
{
   struct node *head=NULL;
   int pos;
   AddatEnd(&head,15);
   AddatEnd(&head,25);
   AddatEnd(&head,35);
   AddatEnd(&head,35);
   AddatEnd(&head,45);
   AddatEnd(&head,55);
   AddatEnd(&head,65);
   AddatEnd(&head,75);
   
   display(head);
   //AddatBegin(&head,100); 
  
    display(head);
   printf("enter the position of node to be added\n");
   scanf("%d",&pos);
   
   AddatPosition(&head,pos,200);
   
   
   display(head);
   ReverseDisplay(head);
   return 0;

}
