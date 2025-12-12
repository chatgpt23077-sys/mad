#include <stdio.h>
#include <string.h>

int isMatching(char open, char close) {
    return (open=='(' && close==')') || (open=='{' && close=='}') || (open=='[' && close==']');
}

int isBalanced(char* expr) {
    char stack[100];
    int top = -1;
    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') stack[++top] = c;
        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1) return 0;
            char o = stack[top--];
            if (!isMatching(o, c)) return 0;
        }
    }
    return (top == -1);
}

int main() {
    char expr[200];
    printf("Enter expression: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';
    if (isBalanced(expr)) printf("Parentheses are balanced\n");
    else printf("Parentheses are NOT balanced\n");
    return 0;
}
