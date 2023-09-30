#include<stdio.h>
#include<stdlib.h>
//inorder method for tree
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
void preorder(struct node *trav)            //reading the tree using preorder method
{
   if(trav!=NULL){
         printf("%d  ",trav->data);  
         inorder(trav->left);
         inorder(trav->right);
    }                                                                                                                                                                                
}

void postorder(struct node *trav)            //reading the tree using postorder method
{
   if(trav!=NULL){
         inorder(trav->left);
         inorder(trav->right);
         printf("%d  ",trav->data);
    }
}
int main()
{
    struct node *root=NULL;
    
    insert(&root,50);
    insert(&root,24);
    insert(&root,30);
    insert(&root,13);
    insert(&root,23);
    
    inorder(root);
    printf("\n");
    
    preorder(root);
    printf("\n");
    
    postorder(root);
    printf("\n");
    
return 0;
}
