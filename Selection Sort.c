//Saya Nezrin
#include<stdio.h>
#include<stdlib.h>
void selectionsort(int a[25],int n)
{
	int j,temp,min,k=0,loc;
	while(k<n-1)
	{
		min=a[k];
		loc=k;
		j=k+1;
		while(j<n)
		{
			if(min>a[j])
			{
				min=a[j];
				loc=j;
			}
		    j++;
		}
		temp=a[k];
		a[k]=a[loc];
		a[loc]=temp;
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
	selectionsort(A,n);
	printf("The elements of the array after sorting:");
	for(int i=0;i<n;i++)
		printf("%d   ",A[i]);
	printf("\n");
	return 0;
}
