#include <stdio.h>

int main() {
    int n, i, key, pos = -1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) { pos = i; break; }
    }
    if (pos != -1)
        printf("%d found at position %d (0-based index)\n", key, pos);
    else
        printf("%d not found in array\n", key);
    return 0;
}
