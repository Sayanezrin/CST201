#include<stdio.h>
void tuple(int x[10][10],int r,int c,int T[10][3]);
void transpose(int y[10][3]);
void sum(int T1[10][3],int T2[10][3]);
void main()
{
   	int A1[10][10],A2[10][10],T1[10][3],T2[10][3],r1,c1,r2,c2,count1=0,count2=0,choice;
  	printf("Enter the no. of rows of the First matrix\n");
   	scanf("%d",&r1);
	printf("Enter the no. of columns of the First matrix\n");
	scanf("%d",&c1);
	printf("Enter the %d elements of the First matrix\n",(r1*c1));
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			scanf("%d",&A1[i][j]);
			if(A1[i][j]!=0)
				{
				    count1++;
				}
		}
	}
	if(count1<=((r1*c1)/2))
    {
        printf("First Sparse Matrix is:\n");
		for(int i=0;i<r1;i++)
		{
			for(int j=0;j<c1;j++)
			{
				printf("%d\t",A1[i][j]);
			}
			printf("\n");
		}
		tuple(A1,r1,c1,T1);
	}
	else
       printf("The First matrix entered is not Sparse Matrix\n");

    printf("Enter the number of rows of the second matrix\n");
   	scanf("%d",&r2);
	printf("Enter the number of columns of the second matrix\n");
	scanf("%d",&c2);
	printf("Enter the %d elements of the second matrix\n",(r2*c2));
	for(int i=0;i<r2;i++)
	{
		for(int j=0;j<c2;j++)
		{
			scanf("%d",&A2[i][j]);
			if(A2[i][j]!=0)
				{
				    count2++;
				}
		}
	}
	if(count2<=((r2*c2)/2))
    {
		printf("Second Sparse Matrix is:\n");
		for(int i=0;i<r2;i++)
		{
			for(int j=0;j<c2;j++)
			{
				printf("%d\t",A2[i][j]);
			}
			printf("\n");
		}
		tuple(A2,r2,c2,T2);
	}
	else

        printf("The Second matrix entered is not Sparse Matrix\n");
	printf("MENU\n");
	printf("1.Find Transpose of the two sparse matrix\n");
	printf("2.Add the two sparse matrix\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("First Transpose Tuple Matrix is:\n");
			transpose(T1);
			printf("Second Transpose Tuple Matrix is:\n");
			transpose(T2);
			break;
		case 2:
			sum(T1,T2);
			break;
		default:
			printf("Entered option not available in the menu");
	}
}
void tuple(int x[10][10],int r,int c,int T[10][3])
{
	int i,j,k=1;
	T[0][0]=r;
	T[0][1]=c;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(x[i][j]!=0)
			{
				T[k][0]=i;
				T[k][1]=j;
				T[k][2]=x[i][j];
				k++;
			}
		}
	}
	T[0][2]=k-1;
	printf("Tuple Matrix is:\n");
	for(i=0;i<k;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",T[i][j]);
		}
		printf("\n");
	}
}
void transpose(int y[10][3])
{
	int T[10][3],m,n,i,j,k;
	T[0][0]=y[0][1];
	T[0][1]=y[0][0];             //m=number of rows of tuple
	T[0][2]=y[0][2];             //n=number of cols of tuple
	k=1;
	m=y[0][1];
	n=y[0][2];
	for(i=0;i<m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(y[j][1]==i)
			{
				T[k][0]=y[j][1];
				T[k][1]=y[j][0];
				T[k][2]=y[j][2];
				k++;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",T[i][j]);
		}
		printf("\n");
	}
}
void sum(int T1[10][3],int T2[10][3])
{
	int r1,c1,r2,c2,m,n,i,j,k,S[20][3];
	r1=T1[0][0];
	r2=T2[0][0];
	c1=T1[0][1];
	c2=T2[0][1];
	if(r1!=r2||c1!=c2)
		printf("Incompactable Matrix size\n");
	else
	{
		S[0][0]=T1[0][0];
		S[0][1]=T1[0][1];
		m=1;
		n=1;
		k=1;
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				if(T1[m][0]==i&&T1[m][1]==j&&T2[n][0]==i&&T2[n][1]==j)
				{
					S[k][0]=T1[m][0];
					S[k][1]=T1[m][1];
					S[k][2]=T1[m][2]+T2[n][2];
					m++;
					n++;
					k++;
				}
				else if(T1[m][0]==i&&T1[m][1]==j)
				{
					S[k][0]=T1[m][0];
					S[k][1]=T1[m][1];
					S[k][2]=T1[m][2];
					m++;
					k++;
				}
				else if(T2[n][0]==i&&T2[n][1]==j)
				{
					S[k][0]=T2[n][0];
					S[k][1]=T2[n][1];
					S[k][2]=T2[n][2];
					n++;
					k++;
				}
			}
		}
		S[0][2]=k-1;
		printf("SUM is:\n");
		for(i=0;i<=S[0][2];i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%d\t",S[i][j]);
			}
			printf("\n");
		}
	}
}

