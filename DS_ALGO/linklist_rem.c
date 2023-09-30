#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// add at position
struct node
{
   int data;
   struct node *next;
};

void AddatEnd(struct node **phead, int val)
{
    struct node *trav;
    struct node *temp;                      //to create a node to be added
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    
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
   
       trav->next=temp;            //please explain
    }
}
void removeAtend(struct node **phead)
{
    struct node *trav=*phead;
    struct node *follow=trav;                      //to create a node to
       while(trav->next!=NULL)
       {    
            follow=trav;
            trav=trav->next;
       }
       follow->next=NULL;
       free(trav);            //please explain
}
void removeAtbegin(struct node **phead)
{
     struct node *t=*phead;
     (*phead)=(*phead)->next;
     free(t);

}

void removeAtpos(struct node **phead, int pos)
{
    struct node *trav=*phead;
    struct node *follow=trav;  
    printf("enter the node position to be removed\n");
    scanf("%d",&pos);
                                                            //to create a node to be added
       while(pos>1)
       {    
            follow=trav;
            trav=trav->next;
            pos--;
       }
       follow->next=trav->next;
       free(trav);            //please explain
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
int main()
{
   struct node *head=NULL;
   int pos;
   AddatEnd(&head,15);
   AddatEnd(&head,25);
   AddatEnd(&head,35);
   AddatEnd(&head,45);
  AddatEnd(&head,55);
  AddatEnd(&head,65);

     
     display(head);
     printf("\n");
  removeAtbegin(&head);
  
  display(head);
   printf("\n");
  
  removeAtend(&head);
  display(head);
   printf("\n");
   removeAtpos(&head,pos);
   display(head);
    printf("\n");
   
   return 0;
}
