#include <stdio.h>
#include <string.h>
#include <ctype.h>

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[100];
    int top = -1;
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isspace(c)) continue;
        if (isalnum(c)) postfix[k++] = c;
        else if (c == '(') stack[++top] = c;
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') postfix[k++] = stack[top--];
            if (top != -1 && stack[top] == '(') top--;
        } else if (isOperator(c)) {
            while (top != -1 && isOperator(stack[top]) &&
                   ((precedence(stack[top]) > precedence(c)) ||
                    (precedence(stack[top]) == precedence(c) && c != '^'))) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top != -1) postfix[k++] = stack[top--];
    postfix[k] = '\0';
}

int main() {
    char infix[200], postfix[200];
    printf("Enter infix expression (no multi-char operands):\n");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
