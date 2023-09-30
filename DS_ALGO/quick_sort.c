#include<stdio.h>
//quick sorting of integers

int partition(int *arr, int lower, int upper)
{
    int i,j,pivot,temp;
    pivot=arr[upper];
    i=lower-1;
    j=lower;
    while(j<upper)
    {
        if(arr[j]<pivot)               //for swapping to left right
        {
           i=i+1;
           temp=arr[i];
           arr[i]=arr[j];
           arr[j]=temp;
        }
        j++;
    }
    temp=arr[upper];                  //for swapping pivot
    arr[upper]=arr[i+1];
    arr[i+1]=temp;
    return i+1;                               //new pivot one//value will return in q inside quicksort fun
}
void QuickSort(int *arr, int lower, int upper)
{
    int q;
    if(lower<upper)
        {  
            q=partition(arr,lower,upper);
            QuickSort(arr,lower,q-1);                 //for leftend arr lower is same but upper=q-1
            QuickSort(arr,q+1,upper);                  //for rightend arr lower =q+1 and upper is same
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
   QuickSort(arr,0,n-1);                              //arr,lower,upper
   for(i=0; i<n; i++)
         printf("%d   ",arr[i]);
   printf("\n");      
return 0;
}
