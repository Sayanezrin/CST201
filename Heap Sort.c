#include<stdio.h>
#include<stdlib.h>
void createheap(int a[25],int n)
{
    int i=1,j;
	while(i<=n)
	{
		j=i;
		while(((j-1)/2>=0)&&(a[j]>a[(j-1)/2]))
		{
			int temp=a[j];
			a[j]=a[(j-1)/2];
			a[(j-1)/2]=temp;
			j=((j-1)/2);
		}
		i++;
	}
}
void removemax(int a[25],int n)
{
    int temp =a[0];
    a[0]=a[n];
    a[n]=temp;
}
void rebuildheap(int a[25],int n)
{
	int i,j=0,flag=1,child,lchild,rchild;
	if(n==0)
		return;
    while(flag==1)
    {
        lchild=2*j+1;
        rchild=2*j+2;
        if(rchild<=n)
        {
            if(a[rchild]>a[lchild])
                child=rchild;
			else
				child=lchild;
		}
		else if(lchild<=n)
		    child=lchild;
		else
			    flag=0;
		if(a[child]>a[j])
		{
			int temp=a[child];
			a[child]=a[j];
			a[j]=temp;
			j=child;
		}
		else
			flag=0;
	}

}
void heapsort(int a[25],int n)
{
	int i;
	createheap(a,n-1);
    for(i=n-1;i>0;i--)
    {
		removemax(a,i);
		rebuildheap(a,i-1);
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
	heapsort(A,n);
	printf("The elements of the array after sorting:");
	for(int i=0;i<n;i++)
		printf("%d   ",A[i]);
	printf("\n");
	return 0;
}
