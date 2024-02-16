#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node* link;
};

struct node *createlist(struct node *start);
void displaylist(struct node *start);
void count_Nodes(struct node *start);
void search(struct node *start, int no_to_search);
struct node *insertAtBeginning(struct node *start,int data);
void insertAtEnd(struct node *start, int data);
void insertAfter(struct node*start, int data, int x);
struct node *insertBefore(struct node*start, int data, int x);
struct node *insertAtPosition(struct node*start, int data, int position);

int main(){
struct node*start = NULL;
start = createlist(start);
int choice, x, data, position;
while(1){
	printf("\n");
	printf("Enter operation\n");
	printf("1. Display list\n");
	printf("2. Count Nodes\n");
	printf("3. Search element\n");
	printf("4. Insert at beginning\n");
	printf("5. Insert at the end\n");
	printf("6. Insert After data\n");
	printf("7. Insert Before data\n");
	printf("8. Insert at position\n");
	printf("11. Exit\n\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice);
	if(choice == 11)
		break;
	switch(choice){
		case 1:
			displaylist(start);
			printf("\n");
			break;
		case 2:
			count_Nodes(start);
			printf("\n");
			break;
		case 3:
			printf("NO. to be searched: ");
			scanf("%d",&data);
			search(start,data);
			printf("\n");
			break;
		case 4:
			printf("\nNo to insert at beginning: ");
			scanf("%d",&data);
			start = insertAtBeginning(start, data);
			break;
		case 5:
			printf("\nNo to insert at the end: ");
			scanf("%d",&data);
			insertAtEnd(start, data);
			break;
		case 6:
			printf("\nNo to insert: ");
			scanf("%d",&data);
			printf("\nNo after which data is to be inserted: ");
			scanf("%d", &x);
			insertAfter(start, data, x);
			break;
		case 7:
			printf("\nNo to insert: ");
			scanf("%d", &data);
			printf("\nNo before which data is to be inserted: ");
			scanf("%d",&x);
			start = insertBefore(start, data, x);
			break;
		case 8:
			printf("\nNo to insert: ");
			scanf("%d",&data);
			printf("\nPosition at which data is inserted: ");
			scanf("%d",&position);
			start = insertAtPosition(start, data, position);
			break;
	}
	}
}
struct node *createlist(struct node *start){
	int i, n, data;
	printf("Enter no. of nodes: ");
	scanf("%d",&n);
	if(n == 0)
		return start;
	printf("Enter the first element to be inserted: ");
	scanf("%d",&data);
	start = insertAtBeginning(start,data);
	for(i = 2; i<=n; i++){
		printf("Enter next element to be inserted: ");
		scanf("%d", &data);
		insertAtEnd(start, data);
	}
	return start;
}

void displaylist(struct node *start){
	struct node *p;
	if(start == NULL){
		printf("List is empty\n");
		return ;
	}
	else{
		p = start;
		printf("List elements:\n");
		while(p != NULL){
			printf("%d",p->info);
			printf("\t");
			p = p->link;
		}
	}
	printf("\n");
}

void count_Nodes(struct node *start){
	struct node *p;
	p = start;
	int no_of_nodes = 0;
	while(p != NULL){
		p = p->link;
		no_of_nodes++;
	}
	printf("No of node in list is %d",no_of_nodes);
	printf("\n");
}

void search(struct node *start, int no_to_search){
	struct node *p;
	p = start;
	int position = 1;
	while(p != NULL){
		if(p->info == no_to_search)
			break;
		position++;
		p=p->link;
	}
	if(p==NULL)
		printf("%d not found on list",no_to_search);
	else
		printf("%d found at position %d",no_to_search,position);
	printf("\n");
}

struct node *insertAtBeginning(struct node *start, int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->link = start;
	/* This function has local scope so the start is not changed inside the function 
		It should be returned*/
	start = temp;
	temp->info = data;
	printf("\n");
	return start;
}

void insertAtEnd(struct node *start, int data){
	struct node *temp, *p;
	temp = (struct node*)malloc(sizeof(struct node));
	p = start;
	while(p->link!=NULL){
		p = p->link;
	}
	p->link = temp;
	temp->info = data;
	temp->link = NULL;
	printf("\n");
}

void insertAfter(struct node*start, int data, int x){
	struct node *temp,*p;
	p = start;
	while(p->link != NULL){
		if(p->info == x)
			break;
		p = p->link;
	}
	if(p == NULL){
		printf("%d is not present in the list\n",x);
	}
	else{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = p->link;
		p->link = temp;
	}
	printf("\n");
}

struct node*insertBefore(struct node *start, int data, int x){
	struct node *temp, *p;	
	if(start == NULL){
		printf("List empty!\n");
		return start;
	}
	if(x == start->info){	
		temp = (struct node*)malloc(sizeof(struct node));
		temp->link = start;
		temp->info = data;
		start = temp;
		return start;
	}
	p = start;
	while(p != NULL){
		if(p->link->info == x)
			break;
		p = p->link;
	}
	if(p->link == NULL){
		printf("%d not in the list",x);
	}
	else{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = p->link;
		p->link = temp;
		
	}
	return start;
}
struct node *insertAtPosition(struct node*start, int data, int position){
	struct node *temp,*p;
	p = start;
	int i=1;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(position == 1){
		temp->info = data;
		temp->link = start;
		start = temp;
		return start;
	}
	
	for(i= 1;i<position-1 && p!=NULL;i++){
		p = p->link;
	}
	temp->info = data;
	temp->link = p->link;
	p->link = temp;
	printf("\n");
	return start;
}