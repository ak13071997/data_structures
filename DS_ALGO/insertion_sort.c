#include<stdio.h>
//insertion sorting of integers

void InsertionSort(int arr[100],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
        {  
            key=arr[i];
            for(j=i-1; j>=0; j--)           //please explain
            {
                if(arr[j]>key)
                     arr[j+1]=arr[j];       //for right shift
                else
                     break;
            } 
            arr[j+1]=key;
        }
}

int main()
{
   int arr[100],n,i;
   printf("enter the number of elements in an array\n");
   scanf("%d",&n);
   printf("enter the integers to be sorted\n");
   for(i=0; i<n; i++)
         scanf("%d",&arr[i]);
   for(i=0; i<n; i++)
         printf("%d   ",arr[i]);
   printf("\n");
   InsertionSort(arr,n);
   for(i=0; i<n; i++)
         printf("%d   ",arr[i]);
   printf("\n");      
return 0;
}
