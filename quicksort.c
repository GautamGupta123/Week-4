#include<stdio.h>
void quick(int [],int,int);
int main()
{
	int arr[50],n,i,start,end,comparisions=0,swaps=0;
	printf("Enter the range:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&arr[i]);
	}
	partition(arr,start,end);
	quick(arr,0,n-1);
	printf("The sorted array is:\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nComparisions=%d\n",comparisions);
	printf("Swaps=%d",swaps);
	return 0;
}
int partition(int arr[50],int start,int end)
{
	int pivot=arr[end],comparisions,swaps;
	int i=start-1;
	int j;
	for(j=start;j<=end;j++)
	 {
	 	if(arr[j]<pivot)
	 	 {
	 	 	comparisions++;
	 	 	i++;
	 	 	int temp=arr[i];
	 	 	arr[i]=arr[j];
	 	 	arr[j]=temp;
	 	 	swaps++;
		  }
	 }
	 int temp=arr[i+1];
	 arr[i+1]=arr[end];
	 arr[end]=temp;
	 swaps++;
	 return (i+1);
}
void quick(int arr[50],int start,int end)
{
	if(start<end)
	{ 
	  int p=partition(arr,start,end);
	  quick(arr,start,p-1);
	  quick(arr,p+1,end);
	}
}
