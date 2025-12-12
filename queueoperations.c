#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = 0; // queue elements between front and rear-1

void enqueue(int x) {
    if (rear == MAX) { printf("Queue overflow\n"); return; }
    queue[rear++] = x;
}

int dequeue() {
    if (front == rear) { printf("Queue underflow\n"); return -99999999; }
    return queue[front++];
}

void display() {
    if (front == rear) { printf("Queue is empty\n"); return; }
    printf("Queue (front to rear): ");
    for (int i = front; i < rear; i++) printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int ch, x;
    printf("Simple Queue Demo\n");
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Enter value to enqueue: "); scanf("%d",&x); enqueue(x); break;
            case 2: { int v = dequeue(); if (v != -99999999) printf("Dequeued %d\n", v); break; }
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
