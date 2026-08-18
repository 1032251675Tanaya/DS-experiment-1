#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert an element into the queue
void enqueue(int value)
{	if (rear == SIZE - 1)
	{
		printf("Queue is Full\n");
	}     else     {
		if (front == -1)         {
			front = 0;
		}

		rear++;
		queue[rear] = value;

		printf("Inserted %d\n", value);
	}
}

// Function to delete an element from the queue
void dequeue() {
	if (front == -1 || front > rear)
	{
		printf("Queue is Empty\n");
	}     else
	{
		printf("Deleted %d\n", queue[front]);
		front++;
	}
}

// Function to display queue elements
void display()
{
	int i;

	if (front == -1 || front > rear)
	{
		printf("Queue is Empty\n");
	}     else
	{
		printf("Queue elements are: ");

		for (i = front; i <= rear; i++)
		{
			printf("%d ", queue[i]);
		}

		printf("\n");
	}
}

// Main function
int main() {
	int choice, value;

	while (1)
	{
		printf("\nQueue Menu:\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Exit\n");

		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter value to insert: ");
			scanf("%d", &value);
			enqueue(value);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;

		case 4:
			printf("Exiting program...\n");
			return 0;
		default:
			printf("Invalid choice!\n");
		}
	}

	return 0;
}
