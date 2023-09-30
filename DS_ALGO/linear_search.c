#include<stdio.h>
int LinearSearch(int *arr, int n, int val)
{
    int i;
    for(i=0; i<n;i++)
    {
        if(val==arr[i])
        {
           return i;
        } 
        
    }
    return -1;
}

int main()
{
    int arr[100],n,i,val;
    int index;
    
    printf("how many elements in an array\n");
    scanf("%d",&n);
    
    printf("enter the elements\n");
    for(i=0; i<n; i++)
         {
         scanf("%d",&arr[i]);
         }
     
    for(i=0; i<n; i++)
    {
        printf("%d   ",arr[i]);
    }
    printf("\n");
    
    printf("enter the element to be search\n");
    scanf("%d",&val);
    
    index=LinearSearch(arr,n,val);
    
    if(index!=-1)
    {
        printf("element found at index %d\n",index);
    }
    else
     {
        printf("element not found\n"); 
     }
return 0;
}
