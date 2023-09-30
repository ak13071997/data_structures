#include<stdio.h>
void BubbleSort(int arr[100],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
        {
            for(j=0; j<n-i-1; j++)
            {
                if(arr[j]>arr[j+1])
                {
                   temp=arr[j];
                   arr[j]=arr[j+1];
                   arr[j+1]=temp;
                }
            }
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
   BubbleSort(arr,n);
   for(i=0; i<n; i++)
         printf("%d   ",arr[i]);
   printf("\n");      
return 0;
}

