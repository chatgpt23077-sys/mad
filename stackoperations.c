#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int x) {
    if (top == MAX-1) { printf("Stack overflow\n"); return;}
    stack[++top] = x;
}

int pop() {
    if (top == -1) { printf("Stack underflow\n"); return -99999999; }
    return stack[top--];
}

int peek() {
    if (top == -1) { printf("Stack is empty\n"); return -99999999; }
    return stack[top];
}

void display() {
    if (top == -1) { printf("Stack is empty\n"); return; }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice, x;
    printf("Simple Stack Operations Demo\n");
    for (;;) {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter value to push: "); scanf("%d",&x); push(x); break;
            case 2: { int v = pop(); if (v != -99999999) printf("Popped %d\n", v); break; }
            case 3: { int v = peek(); if (v != -99999999) printf("Top = %d\n", v); break; }
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
