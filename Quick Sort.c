#include<stdio.h>
#include<stdlib.h>
int partition(int leftend,int rightend,int a[10],int n)
{
	int leftp,rightp,pivot,temp,temp1;
	leftp=leftend;
	rightp=rightend;
	pivot=a[leftend];
	while(leftp<rightp)
	{
		while((leftp<rightp)&&(a[leftp]<=pivot))
		{
			leftp++;
		}
		while((rightp>leftend)&&(a[rightp]>pivot))
		{
			rightp--;
		}
		if(leftp<rightp)
		{
			temp=a[leftp];
			a[leftp]=a[rightp];
			a[rightp]=temp;
		}
	}
	temp1=a[leftend];
	a[leftend]=a[rightp];
	a[rightp]=temp1;
	return(rightp);
}
int quicksort(int leftend,int rightend,int a[10],int n)
{
	int point;
	if(leftend>=rightend)
		return (0);
	else
	{
		point=partition(leftend,rightend,a,n);
		quicksort(leftend,point-1,a,n);
		quicksort(point+1,rightend,a,n);
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
	quicksort(0,n-1,A,n);
	printf("The elements of the array after sorting:");
	for(int i=0;i<n;i++)
		printf("%d   ",A[i]);
	printf("\n");
	return 0;
}
