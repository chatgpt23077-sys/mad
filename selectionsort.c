#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        if (minIdx != i) {
            int t = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = t;
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    selectionSort(a, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
