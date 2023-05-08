#include<stdio.h>
int A[20],size,front,rear;
void ENQUEUE_CQ(int item)
{
	if((rear+1)%size==front)
		printf("Queue is FULL\n");
	else if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		A[rear]=item;
	}
	else
	{
		rear=(rear+1)%size;
		A[rear]=item;
	}
}
void DEQUEUE_CQ()
{
	if(front==-1&&rear==-1)
		printf("Queue is EMPTY\n");
	else if(front==rear)
	{
		printf("The dequeued item is %d\n",A[front]);
		front=rear=-1;
	}
	else
	{
		printf("The dequeued item is %d\n",A[front]);
		front=(front+1)%size;
	}
}
void DISPLAY_CQ()
{
	if(front==-1&&rear==-1)
		printf("Queue is EMPTY\n");
	else if(front<=rear)
	{
		for(int i=front;i<=rear;i++)
			printf("%d\t",A[i]);
	}
	else
	{
		for(int i=front;i<=(size-1);i++)
			printf("%d\t",A[i]);
		for(int i=0;i<=rear;i++)
			printf("%d\t",A[i]);
	}
	printf("\n");
}
void main()
{
	int c,item;
	printf("Enter size of CIRCULAR_QUEUE:");
	scanf("%d",&size);
	front=-1;
	rear=-1;
	printf("1.ENQUEUE\t2.DEQUEUE\t3.DISPLAY\t4.QUIT\n");
	do
	{
		printf("Enter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter the item to be enqueued:");
				scanf("%d",&item);
				ENQUEUE_CQ(item);
				break;
			case 2:
				DEQUEUE_CQ();
				break;
			case 3:
				DISPLAY_CQ();
				break;
			case 4:
				break;
			default:
				printf("invalid choice\n");
		}
	}while(c!=4);
}
