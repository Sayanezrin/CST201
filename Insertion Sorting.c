#include<stdio.h>
#include<stdlib.h>
void insertionsort(int a[25],int n)
{
	int j,temp,k=1;
	while(k<n)
	{
		temp=a[k];
		j=k-1;
		while(temp<a[j]&&j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
	    a[j+1]=temp;
	    k++;
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
	insertionsort(A,n);
	printf("The elements of the array after sorting:");
	for(int i=0;i<n;i++)
		printf("%d   ",A[i]);
	printf("\n");
	return 0;
}
