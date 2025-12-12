#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int evalPostfix(char* expr) {
    int stack[100], top = -1;
    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        if (isspace(c)) continue;
        if (isdigit(c)) {
            // support multi-digit numbers: collect number
            int num = 0;
            while (isdigit(expr[i])) { num = num*10 + (expr[i]-'0'); i++; }
            i--; // step back one
            stack[++top] = num;
        } else {
            if (top < 1) { printf("Invalid expression\n"); return 0; }
            int b = stack[top--];
            int a = stack[top--];
            switch(c) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
                case '^': {
                    int res = 1;
                    for (int k = 0; k < b; k++) res *= a;
                    stack[++top] = res;
                    break;
                }
                default: printf("Unknown operator %c\n", c); return 0;
            }
        }
    }
    if (top != 0) { printf("Invalid expression\n"); return 0; }
    return stack[top];
}

int main() {
    char expr[200];
    printf("Enter postfix expression (space-separated for multi-digit numbers):\n");
    fgets(expr, sizeof(expr), stdin);
    int result = evalPostfix(expr);
    printf("Result = %d\n", result);
    return 0;
}
