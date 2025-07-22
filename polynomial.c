#include <stdio.h>

struct poly {
    int coeff;
    int exp;
};

struct poly poly1[10], poly2[10], poly3[20];

int main() {
    int t1, t2, i = 0, j = 0, k = 0;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &t1);
    for (i = 0; i < t1; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &poly1[i].coeff);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &poly1[i].exp);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &t2);
    for (j = 0; j < t2; j++) {
        printf("Enter the coefficient for term %d: ", j + 1);
        scanf("%d", &poly2[j].coeff);
        printf("Enter the exponent for term %d: ", j + 1);
        scanf("%d", &poly2[j].exp);
    }

    i = j = k = 0;

    while (i < t1 && j < t2) {
        if (poly1[i].exp == poly2[j].exp) {
            poly3[k].coeff = poly1[i].coeff + poly2[j].coeff;
            poly3[k].exp = poly1[i].exp;
            i++;
            j++;
        } else if (poly1[i].exp > poly2[j].exp) {
            poly3[k] = poly1[i];
            i++;
        } else {
            poly3[k] = poly2[j];
            j++;
        }
        k++;
    }

    while (i < t1) {
        poly3[k++] = poly1[i++];
    }
    while (j < t2) {
        poly3[k++] = poly2[j++];
    }

    printf("Resultant Polynomial: ");
    for (i = 0; i < k; i++) {
        if (poly3[i].coeff == 0)
            continue;

        if (i<k-1)

        if (poly3[i].exp == 0)
            printf("%d", poly3[i].coeff);
        else if (poly3[i].exp == 1)
            printf("%dx", poly3[i].coeff);
        else
            printf("%dx^%d", poly3[i].coeff, poly3[i].exp);
    }

    printf("\n");
    return 0;
}
