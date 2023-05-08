#include<stdio.h>
void ENQUEUE(int item);
void DEQUEUE();
void DISPLAY();
int rear=-1;
int front=-1;
int A[20];
int size;

void main(void)
{
    int choice;
    printf("Enter the size of the queue\n");
    scanf("%d",&size);
    while(choice!=5)
    {
        printf("QUEUE OPERATIONS\n");
        printf("1:ENQUEUE\n");
        printf("2:DEQUEUE\n");
        printf("3:DISPLAY\n");
        printf("4:EXIT\n");

        printf("Enter choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            int item;
            printf("Enter the item\n");
            scanf("%d",&item);
            ENQUEUE(item);
            break;
        }
        case 2:
        {
            DEQUEUE();
            break;
        }
        case 3:
        {
            DISPLAY();
            break;
        }
        case 4:
        {
            break;
        }
        default:
            printf("Invalid Input\n");
        }
    }
}

void ENQUEUE(int item)
{
    if(rear==size-1)
        printf("Queue is full\n");

    else if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        A[rear]=item;
    }
    else
    {
        rear++;
        A[rear]=item;
    }
}

void DEQUEUE()
{
    if (front==-1)
    {
      printf("Queue is empty\n");
    }
    else if(rear==front)
    {
        printf("The deleted item is %d\n",A[front]);
        front=rear=-1;
    }
    else
    {
         printf("The deleted item is %d\n",A[front]);
         front++;
    }
}

void DISPLAY()
{
    if (front==-1&&rear==-1)
        printf("queue is empty");

    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d",A[i]);
        }
        printf("\n");
    }
}



