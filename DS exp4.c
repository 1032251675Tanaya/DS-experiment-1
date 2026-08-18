#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
};
struct node * start = NULL;
//Insert at start
void insert()
{	struct node *newNode;
	int value;
	printf("Enter element you want to insert: ");
	scanf("%d",&value);
	newNode->data=value;
	if(start==NULL) {
		start=newNode;
	}
	else {
		newNode->next = start;
		start=newNode;
	}
}
//insert at end
void end()
{	struct node *newNode,*P;
	int value;
	scanf("%d",&value);
	newNode->data=value;
	if(start==NULL) {
		start=newNode;
	}
	else {
		P=start;
		while(P->next!=NULL) {
			P=P->next;
		}
		P->next=newNode;
		newNode->next=NULL;
	}
}
//insertion any where
void anywhere()
{
	struct node *newNode,*P;
	int value,position,C;
	printf("Enter element you want to insert: ");
	scanf("%d",&value);
	printf("Enter position from where you like to insert: ");
	scanf("%d",&position);
	newNode= (struct node *)malloc(sizeof(struct node));
	newNode->data=value;
	C=1;
	P=start;
	while(P->next!=0 && C<position) {
		P=P->next;
		C++;
	}
	newNode->next = P->next;
	P->next = newNode;
}
// Deletion at start
void deleteStart() {
	struct node *P;
	if(start == NULL) {
		printf("List is empty\n");
	} else {
		P = start;
		start = start->next;
		free(P);
	}
} // Deletion at end
void deleteEnd()
{	struct node *P, *C;
	if(start == NULL) {
		printf("List is empty\n");
	} else if(start->next == NULL) {
		P = start;
		start = NULL;
		free(P);
	}
	else {
		P = start;
		while(P->next != NULL) {
			C = P;
			P = P->next;
		}
		C->next = NULL;
		free(P);
	}
} // Deletion anywhere
void deleteAnywhere() {
	struct node *P, *C;
	int position, i;
	if(start == NULL) {
		printf("List is empty\n");
	}
	else if(position == 1) {
		P = start;
		start = start->next;
		free(P);
	}
	else {
		P = start;
		i = 1;
		C = P;
		P = P->next;
		i++;
	}
	C->next = P->next;
	free(P);
}

// Traversal and display
void display()
{	struct node *P;
	if(start == NULL) {
		printf("List is empty\n");
	}
	else {
		P = start;
		while(P != NULL) {
			printf("%d -> ", P->data);
			P = P->next;
		}
	}
}
int main() {
	while(1) {
		printf("\n===== SINGLY LINKED LIST =====\n");
		printf("1. Insert at Start\n");
		printf("2. Insert at End\n");
		printf("3. Insert Anywhere\n");
		printf("4. Delete at Start\n");
		printf("5. Delete at End\n");
		printf("6. Delete Anywhere\n");
		printf("7. Display / Traverse\n");
		printf("8. Exit\n");
		int choice;
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
		case 1:
			insert();
			break;
		case 2:
			end();
			break;
		case 3:
			anywhere();
			break;
		case 4:
			deleteStart();
			break;
		case 5:
			deleteEnd();
			break;
		case 6:
			deleteAnywhere();
			break;
		case 7:
			display();
			break;
		case 8:
			printf("Program terminated.\n");
			exit(0);
		default:
			printf("Invalid choice.\n");
		}
	}
	return 0;
}
