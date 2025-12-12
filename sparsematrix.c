#include <stdio.h>

int main() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int mat[r][c];
    printf("Enter matrix elements (%d):\n", r*c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);

    int zeroCount = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (mat[i][j] == 0) zeroCount++;

    printf("Zero elements = %d out of %d\n", zeroCount, r*c);
    if (zeroCount > (r*c)/2) printf("Matrix is sparse\n");
    else printf("Matrix is not sparse\n");
    return 0;
}
