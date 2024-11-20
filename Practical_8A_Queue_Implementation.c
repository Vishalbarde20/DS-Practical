#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// Function to add an element to the queue (Enqueue)
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot add more elements.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue (Dequeue)
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! No elements to dequeue.\n");
        return;
    }
    printf("Dequeued: %d\n", q->data[q->front]);
    q->front++;
}

// Function to print the queue
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Queue q;
    initializeQueue(&q);

    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
