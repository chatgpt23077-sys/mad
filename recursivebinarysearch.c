#include <stdio.h>

int recursiveBinary(int arr[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) return mid;
    else if (arr[mid] < key) return recursiveBinary(arr, mid + 1, high, key);
    else return recursiveBinary(arr, low, mid - 1, key);
}

int main() {
    int n, i, key;
    printf("Enter number of elements (sorted): ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d sorted integers:\n", n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    int pos = recursiveBinary(arr, 0, n - 1, key);
    if (pos != -1) printf("%d found at index %d\n", key, pos);
    else printf("%d not found\n", key);
    return 0;
}
