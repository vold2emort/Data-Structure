#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int stack[MAX];
int top =- 1;
 
void push(int x);
int pop();
int isEmpty();
int isFull();
void displayStack();

int main(){
	
	int x, choice;
	while(1){
		printf("\n1. Push an element in stack\n");
		printf("2. Pop element from stack\n");
		printf("3. Display element from stack\n");
		printf("6. Quit\n");
		scanf("%d",&choice);
		if(choice==6)
			break;
		switch(choice){
			case 1:
				printf("Element to push into stack\n");
				scanf("%d",&x);
				push(x);
			break;
			case 2:
				x = pop();
				printf("\n%d popped from stack\n",x);
				break;
			case 3:
				displayStack();
				break;
				
		}
	}
	return 0;
}

int isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if(top == MAX-1)
		return 1;
	else
		return 0;
}

void push(int x)
{
	if(isFull()){
		printf("Stack overflow\n");
		return;
	}
	else{
		top += 1;
		stack[top] = x;
	}
	printf("\n");
}

int pop()
{
	int x;
	if(isEmpty()){
	
		printf("Stack is underflow\n");
		exit(1);
	}
	else{
		x = stack[top];
		top -= 1;
		return x;
	}
	printf("\n");
}

void displayStack(){
	int i;
	if(isEmpty()){
		printf("Stack is empty\n");
		return;
	}
	printf("\nStack Elements:\n\n");
	for(i=top;i>=0;i--){
		printf("%d\n",stack[i]);
	} 
	printf("\n");
}