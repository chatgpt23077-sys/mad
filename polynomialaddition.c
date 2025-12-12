#include <stdio.h>

int main() {
    int deg1, deg2, maxd;
    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    int a[deg1+1];
    printf("Enter coefficients from highest to lowest degree (%d to 0):\n", deg1);
    for (int i = deg1; i >= 0; i--) scanf("%d", &a[i]);

    printf("Enter degree of second polynomial: ");
    scanf("%d", &deg2);
    int b[deg2+1];
    printf("Enter coefficients from highest to lowest degree (%d to 0):\n", deg2);
    for (int i = deg2; i >= 0; i--) scanf("%d", &b[i]);

    maxd = (deg1 > deg2) ? deg1 : deg2;
    int res[maxd+1];
    for (int i = 0; i <= maxd; i++) {
        int av = (i <= deg1) ? a[i] : 0;
        int bv = (i <= deg2) ? b[i] : 0;
        res[i] = av + bv;
    }

    printf("Resultant polynomial coefficients (degree %d to 0):\n", maxd);
    for (int i = maxd; i >= 0; i--) {
        if (res[i] != 0) {
            if (i != maxd && res[i] > 0) printf(" + ");
            if (i == 0) printf("%d", res[i]);
            else if (i == 1) printf("%dx", res[i]);
            else printf("%dx^%d", res[i], i);
        }
    }
    printf("\n");
    return 0;
}
