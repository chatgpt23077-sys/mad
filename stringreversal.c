#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    // remove newline if present
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') s[len-1] = '\0';
    len = strlen(s);

    char stack[100];
    int top = -1;
    for (int i = 0; i < len; i++) stack[++top] = s[i];

    char rev[100];
    int k = 0;
    while (top != -1) rev[k++] = stack[top--];
    rev[k] = '\0';
    printf("Reversed string: %s\n", rev);
    return 0;
}
