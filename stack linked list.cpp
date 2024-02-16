#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};

struct node *top;
void initializeStack();
int isEmpty();
int size();
void push(int x);
int pop();
int peek();
void display();

int main(){
	int choice,x;
	initializeStack();
	while(1){
		printf("1. Push element in stack\n");
		printf("2. Pop element from stack\n");
		printf("3. Display top element of stack\n");
		printf("4. Display element of stack\n");
		printf("5. Size of stack\n");
		printf("6. Quit\n");
		scanf("%d", &choice);
		if(choice == 6)
			break;
		switch(choice){
			case 1:
				printf("Enter the no. to be pushed: ");
				scanf("%d",&x);
				push(x);
				break;
			case 2:
				x = pop();
				printf("%d is popped from stack", x);
				break;
			case 3:
				x = peek();
				printf("The top element of stack is %d",x);
				break;
			case 4:
				display();
				break;
			case 5:
				x = size();
				printf("The size of stack is %d",x);
				break;
		}
}
}
void initializeStack(){
	top =NULL;
}

int isEmpty(){
	if(top == NULL)
		return 1;
	else
		return 0;
}

int size(){
	int s= 0;
	struct node *p = top;
	if(p!=NULL){
		p=p->link;
		s++;
	}
	printf("\n");
	return s;
}

void push(int x){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("No memory: Stack overflow\n");
		return;
	}
	temp->info = x;
	temp->link = top;
	top = temp;
	printf("\n");
}

int pop(){
	struct node *temp;
	int x;
	if(isEmpty()){
		printf("Stack underflow\n");
		exit(1);
	}
	temp = top;
	x = temp->info;
	top = temp->link;
	free(temp);
	printf("\n");
	return x;
}

int peek(){
	int x;
	if(top == NULL){
		printf("Stack empty\n");
		exit(1);
	}
	printf("\n");
	return top->info;
}

void display(){
	struct node *p;
	p = top;
	if(isEmpty()){
		printf("Stack is empty\n");
		return;
	}
	printf("Stack:\n\n");
	while(p != NULL){
		printf("%d\n",p->info);
		p = p->link;
	}
	printf("\n");
}