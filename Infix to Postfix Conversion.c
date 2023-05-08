//Saya Nezrin
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char A[20],P[20],S[20];
int S1[20];
int top=-1,top1=-1;
int precedence(char c);
void postfix();


void main()
{
int c;
printf("Enter an Infix Expression:");
scanf("%s",A);
while(c!=2)
    {
    printf("MENU\n");
printf("1.Evaluate the infix Expression by converting it to postfix expression\n");

printf("Enter your choice\n");
scanf("%d",&c);
switch(c)
{
case 1:
postfix();

break;

break;
case 2:
break;
default:
printf("Invalid Choice\n");
}
    }

}
int precedence(char c)
{
  switch(c)
  {
  case '+':
  case '-': return 1;

  case '*':
  case '/': return 2;

  case '^': return 3;
  }
 }
void postfix()
{
char x,y;
int i=0,j=0;
while(A[i]!='\0')
{
if((A[i]>='0'&&A[i]<='9')||(A[i]>='A'&&A[i]<='Z')||(A[i]>='a'&&A[i]<='z'))
P[j++]=A[i];
else if(A[i]=='(')
S[++top]=A[i];
else if(A[i]==')')
{
while(S[top]!='(')
P[j++]=S[top--];
top--;
}
else
{
x=A[i];
y=S[top];
if(top==-1||y=='('||precedence(x)>precedence(y))
S[++top]=x;
else
{
while(top!=-1&&y!='('&&precedence(x)<=precedence(y))
{
P[j++]=S[top--];
y=S[top];
}
S[++top]=x;
}
}
i++;
}
while(top!=-1)
P[j++]=S[top--];
P[j]='\0';
printf("Postfix Expression is: %s\n",P);
}



