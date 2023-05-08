#include<stdio.h>
int A[20],size,front,rear;
void PUSH_DQ(int item)
{
	if(front==0&&rear==size-1)
		printf("Deque is FULL\n");
	else if(front==-1&&rear==-1)
	{
		front=rear=0;
		A[front]=item;
	}
	else if(front>0)
	{
		front=front-1;
		A[front]=item;
	}
	else
	{
		for(int i=rear;i>=0;i--)
			A[i+1]=A[i];
		A[front]=item;
		rear=rear+1;
	}
}
void POP_DQ()
{
	if(front==-1&&rear==-1)
		printf("Deque is EMPTY\n");
	else if(rear==front)
	{
		printf("Dequed item is %d\n",A[front]);
		front=rear=-1;
	}
	else
	{
		printf("Dequed item is %d\n",A[front]);
		front=front+1;
	}
}
void INJECT_DQ(int item)
{
	if(front==0&&rear==size-1)
		printf("Deque is FULL\n");
	else if(front==-1&&rear==-1)
	{
		front=rear=0;
		A[rear]=item;
	}
	else if(rear<size-1)
	{
		rear=rear+1;
		A[rear]=item;
	}
	else
	{
		for(int i=front;i<=rear;i++)
			A[i-1]=A[i];
		A[rear]=item;
		front=front-1;
	}
}
void EJECT_DQ()
{
	if(front==-1&&rear==-1)
		printf("Deque is EMPTY\n");
	else if(front==rear)
	{
		printf("Dequed item is %d\n",A[rear]);
		front=rear=-1;
	}
	else
	{
		printf("Dequed item is %d\n",A[rear]);
		rear=rear-1;
	}
}
void DISPLAY_DQ()
{
	if(front==-1&&rear==-1)
		printf("Deque is EMPTY\n");
	else
	{
		for(int i=front;i<=rear;i++)
			printf("%d\t",A[i]);
	}
	printf("\n");
}
void main()
{
	int c,item;
	printf("Enter size of DEQUE:");
	scanf("%d",&size);
	front=-1;
	rear=-1;
	printf("1.PUSH   2.POP   3.INJECT   4.EJECT   5.DISPLAY   6.QUIT\n");
	do
	{
		printf("Enter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter the item to be inserted:");
				scanf("%d",&item);
				PUSH_DQ(item);
				break;
			case 2:
				POP_DQ();
				break;
			case 3:
				printf("Enter the item to be inserted:");
				scanf("%d",&item);
				INJECT_DQ(item);
				break;
			case 4:
				EJECT_DQ();
				break;
			case 5:
				DISPLAY_DQ();
				break;
			case 6:
				break;
			default:
				printf("Please Enter a valid choice(1/2/3/4/5)\n");
		}
	}while(c!=6);
}
