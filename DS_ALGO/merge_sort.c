#include<stdio.h>
int temp[100];
int arr[100];

void merging(int mid, int lower, int upper)
{
    int i,j,k;
    
    for(i=lower, j=mid+1; i<=mid && j<=upper; k++)
    {
         if(arr[i]<arr[j])
         {
              temp[k]=arr[i];
         }
         else if(arr[j]>arr[i])
         {
              temp[k]=arr[j];
         }
         else
         {
            while(i<=mid)
              temp[k++]=arr[i++];
              
            while(j<=upper)
              temp[k++]=arr[j++];
             
            for(i=lower; i<=upper; i++)
               arr[i]=temp[i];
         }
    }
}

void divide(int lower, int upper)
{
    int mid;
    if(lower<upper)
    {
        mid=(lower+upper)/2;
        divide(0,mid);                         //for left sub array 
        divide(mid+1,upper);                   //for right sub array
        merging(mid,lower,upper); 
    }
}

int main()
{
    int n,i,j;
    
    printf("how many elements in an array\n");
    scanf("%d",&n);
    
    printf("enter the elements\n");
    for(i=0; i<n; i++)
         {
         scanf("%d",&arr[i]);
         }
     divide(0,n-1);
     
    for(i=0; i<n; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
return 0;
}
