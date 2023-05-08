#include<stdio.h>
#include<stdlib.h>
void merge(int low,int mid,int high,int a[10],int n)
{
	int h,i,j,k,b[10];
	h=low;
	i=low;
	j=mid+1;
	while ((h<=mid)&&(j<=high))
	{
	    if (a[h]<=a[j])
		{
		    b[i]=a[h];
		    h = h+1;
		}
	    else
		{
		    b[i]= a[j];
		    j=j+1;
		}
	    i++;
	}
	if(h>mid)
	{
		 for(k=j;k<=high;k++)
		 {
		    b[i]=a[k];
		    i=i+1;
		 }
	}
	 else
	 {
		  for(k=h;k<=mid;k++)
		  {
		    b[i]=a[k];
		    i=i+1;
		  }
	}
	for(k=low;k<=high;k++)
	    a[k]=b[k];
}
void mergesort(int low,int high,int a[10],int n)
{
	int mid;
	if (low<high)
	{
		mid = ((low+high)/2);
		mergesort (low,mid,a,n);
		mergesort(mid+1,high,a,n);
		merge(low,mid,high,a,n);
	}
}
int main()
{
	int A[25],n,c;
	printf("Enter the no. of elements of the array:");
	scanf("%d",&n);
	printf("Enter %d elements of the array\n",n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	printf("The elements of the array before sorting:");
	for(int i=0;i<n;i++)
		printf("%d   ",A[i]);
	printf("\n");
	mergesort(0,n-1,A,n);
	printf("The elements of the array after sorting:");
	for(int i=0;i<n;i++)
		printf("%d   ",A[i]);
	printf("\n");
	return 0;
}
