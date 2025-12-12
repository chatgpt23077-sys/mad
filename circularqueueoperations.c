#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear+1)%MAX);
}
int isEmpty() {
    return (front == -1);
}

void enqueue(int x) {
    if (isFull()) { printf("Circular Queue is full\n"); return; }
    if (isEmpty()) { front = rear = 0; cq[rear] = x; return; }
    rear = (rear + 1) % MAX;
    cq[rear] = x;
}

int dequeue() {
    if (isEmpty()) { printf("Circular Queue is empty\n"); return -99999999; }
    int val = cq[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
    return val;
}

void display() {
    if (isEmpty()) { printf("Circular Queue is empty\n"); return; }
    printf("Circular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int ch, x;
    printf("Circular Queue Demo (size %d)\n", MAX);
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Enter value: "); scanf("%d",&x); enqueue(x); break;
            case 2: { int v = dequeue(); if (v != -99999999) printf("Dequeued %d\n", v); break; }
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
