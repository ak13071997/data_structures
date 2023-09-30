#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// add at END
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
   
   AddatEnd(&head,15);
   AddatEnd(&head,25);
   AddatEnd(&head,35);
   AddatEnd(&head,35);
   AddatEnd(&head,45);
   AddatEnd(&head,55);
   AddatEnd(&head,65);
   AddatEnd(&head,75);
   
   display(head);
   return 0;

}
