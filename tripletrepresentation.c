#include <stdio.h>

int main() {
    int r, c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    int mat[r][c];
    printf("Enter matrix elements (%d):\n", r*c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);

    // count non-zero
    int count = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (mat[i][j] != 0) count++;

    printf("Triplet representation (row col value). Non-zero count = %d\n", count);
    printf("Row Col Value\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (mat[i][j] != 0)
                printf("%d   %d   %d\n", i, j, mat[i][j]);

    return 0;
}
