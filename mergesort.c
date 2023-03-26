#include<stdio.h>
void merge(int [],int ,int ,int);
void mergesort(int [],int ,int);
int main()
{
	int arr[50],n,i,mid,beg,end,comparisions;
	printf("Enter the range:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{ 
	  scanf("%d",&arr[i]);
	}
	mergesort(arr,0,n-1);
	printf("The sorted array is:\n");
	for(i=0;i<=n-1;i++)
	{ 
	   printf("%d ",arr[i]);
	}
	printf("Comparisions=%d",comparisions);
	return 0;
}
void merge(int arr[50],int beg,int mid,int end)
{
	int i,j,k,comparisions=0;
	int n1=mid-beg+1;
	int n2=end-mid;
	int la[n1],ra[n2];
	for(i=0;i<=n1-1;i++)
	 {
	 	la[i]=arr[beg+i];
	 }
	for(j=0;j<=n2-1;j++)
	 {
	 	ra[j]=arr[mid+j+1];
	 }
	i=0;
	j=0;
	k=beg;
	while(i<n1 && j<n2)
	{
		
		if(la[i]<=ra[j]){
			arr[k]=la[i];
			i++;
			k++;
		}
		else{
			arr[k]=ra[j];
			j++;
			k++;
		}
		comparisions++;
	}
	while(i<n1)
	{
		arr[k]=la[i];
		i++;
		k++;
	}
    while(j<n2)
    {
    	arr[k]=ra[j];
    	j++;
    	k++;
	}
}
void mergesort(int arr[50],int beg,int end)
{
	if(beg<end)
	{
		int mid=(beg+end)/2;
		mergesort(arr,beg,mid);
		mergesort(arr,mid+1,end);
	    merge(arr,beg,mid,end);
	}
}
