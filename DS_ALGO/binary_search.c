#include<stdio.h>
void SelectionSort(int *arr, int n)
{
   int i,j,temp;
   for(i=0; i<n; i++)
   {
       for(j=i+1; j<n; j++)
       {
            if(arr[i]>arr[j])
            {
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
            }
       }
   }

}
int BinarySearch(int *arr, int n, int val)
{
      int lower,upper,mid,index=-1;
      lower=0;
      upper=n-1;
      
      while(lower<=upper)
      {
           mid=(lower+upper)/2;
           if(arr[mid]==val)
           {
               index=mid;
               break;
           }
           else if(arr[mid]>val)
           {
               upper=mid-1;      //to shift the upper to next upper-
           }
           else if(arr[mid]<val)
           {
              lower=mid+1;       //to shift the lower to the next lower
           }
      }
return index;

}
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
    
    SelectionSort(arr,n);
    index=BinarySearch(arr,n,val);
    
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
