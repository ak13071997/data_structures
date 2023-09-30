#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
void insert(struct node **proot, int val)
{
     struct node *temp,*trav=NULL;
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=val;
     temp->left=NULL;
     temp->right=NULL;
     if(*proot==NULL){
         *proot=temp;
         }
         else{
              trav=*proot;
              while(1){
                    if(trav->data>temp->data){
                         if(trav->left==NULL){
                               trav->left=temp;
                               break;
                               }
                               else
                                   trav=trav->left;
                             }    
                    else if(trav->data<temp->data){
                         if(trav->right==NULL){
                               trav->right=temp;
                               break;
                               }
                               else
                                  trav=trav->right;
                            }      
                          else
                                break;      
                        
                }
        }
}     

void inorder(struct node *trav)            //reading the tree using inorder method
{
   if(trav!=NULL){
         inorder(trav->left);
         printf("%d  ",trav->data);
         inorder(trav->right);
    }
}
void remove_node(struct node **proot, int data)           //to remove the perticular data in t/node to be deleted
{
    struct node *t=*proot, *p=*proot;
    struct node *trav=*proot;
    struct node *tr=*proot;
    while(1)
    {
          if(trav->data==data)
          {
                t=trav;
                break;
          }
          else if(trav->data>data)
          {      
                p=trav;
                trav=trav->left;
          }
          else if(trav->data<data)
          {
                p=trav;
                trav=trav->right;
          }
    
    }
    
    if(t->left!=NULL && t->right!=NULL)              //for two child operation that is for deleting internal node or root node
    {
         tr=t;
         p=t;
         t=t->right;
         while(t->left!=NULL)
         {
              p=t;
              t=t->left;
         }
         tr->data=t->data;
    }
    if(t->left==NULL && t->right==NULL)         //for no child operation that is for deleting leaf node
    {
        if(p->left==t)
            p->left=NULL;
        else if(p->right==t)
            p->right=NULL;
    
    }
    else if(t->left!=NULL && t->right==NULL)         //for one child present at left of node to be deleted of that of right side of the parent
    { 
        if(t==*proot)                            //to delete root when one right child is NULL
        {
          *proot=(*proot)->left;
        }
        if(p->left==t)
            p->left=t->left;
        else if(p->right==t)
            p->right=t->left;  
    }
    else if(t->left==NULL && t->right!=NULL)         //for one child present at left of node to be deleted of that of right side of the parent
    {    
        if(t==*proot)                          ////to delete root when one left child is NULL
        {
          *proot=(*proot)->right;
        }
        if(p->left==t)
            p->left=t->right;
        else if(p->right==t)
            p->right=t->right;  
    }
    free(t);
}

int main()
{
    struct node *root=NULL;
    
      
    insert(&root,75);
    insert(&root,80);
    insert(&root,73);
    insert(&root,74);
    insert(&root,70);
    insert(&root,82);
    
    inorder(root);
    printf("\n");
    
    remove_node(&root,82);
    inorder(root);
    printf("\n");
    
return 0;

}
