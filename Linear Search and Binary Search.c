//Saya Nezrin
#include<stdio.h>
void linearsearch(int a[],int n,int e);
void binarysearch(int a[],int n,int e);
void main()
{
    int a[100],n,e,c;
    printf("Enter the number of elements of the array");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched:\n");
    scanf("%d",&e);
    printf("MEANU\n");
    printf("1.Linear Search\n");
    printf("2.Binary Search\n");
    printf("Enter your choice\n");
    scanf("%d",&c);

    switch(c)
    {
    case 1:
        linearsearch(a,n,e);
        break;
    case 2:
        binarysearch(a,n,e);
        break;
    default:
        printf("The option is not present in the meanu\n");
    }

}
void linearsearch(int a[],int n,int e)
{
    int i;
    for(i=0;i<n;i++)
    {
      if(a[i]==e)
      {
          printf("Element %d is found at location%d\n",e,i);
          break;
      }
    }
    if(i==n)
    {

        printf("Element %d is not found in the array\n",e);
    }
}
void binarysearch(int a[],int n,int e)
{
    int i,j,temp,low,high,mid,flag=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("The sorted array is:\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    low=0;
    high=n-1;
    mid=(low+high)/2;
    while(low<=high)
    {
        if(a[mid]==e)
        {
            printf("\nElement %d is found at location %d\n",e,mid+1);
            flag=1;
            break;
        }
        else if(a[mid]<e)
        {
            low=mid+1;
            mid=(low+high)/2;
        }
        else
        {
            high=mid-1;
            mid=(low+high)/2;
        }
    }
    if(flag!=1)
    {
        printf("Element %d is not found in the array\n",e);
    }
}
