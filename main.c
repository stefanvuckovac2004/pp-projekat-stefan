#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Funkcija za unos dimenzije matrice
int unosDimenzije() {
    int m;
    do {
        printf("Unesite dimenziju kvadratne matrice (1 - %d): ", MAX);
        scanf("%d", &m);

        if (m < 1 || m > MAX) {
            printf("Greska! Dimenzija mora biti u opsegu 1 - %d.\n", MAX);
        }
    } while (m < 1 || m > MAX);

    return m;
}

// Funkcija za unos elemenata matrice
void unosMatrice(int matrica[MAX][MAX], int m, char naziv) {
    printf("\nUnos elemenata matrice %c:\n", naziv);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c[%d][%d] = ", naziv, i, j);
            scanf("%d", &matrica[i][j]);
        }
    }
}

// Funkcija za ispis matrice
void ispisMatrice(int matrica[MAX][MAX], int m, char naziv) {
    printf("\nMatrica %c:\n", naziv);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d", matrica[i][j]);
        }
        printf("\n");
    }
}

// Funkcija za mnozenje matrica
void proizvodMatrica(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = 0;
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int m;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("PROGRAM ZA PROIZVOD DVIJE KVADRATNE MATRICE\n");

    m = unosDimenzije();

    unosMatrice(A, m, 'A');
    unosMatrice(B, m, 'B');

    ispisMatrice(A, m, 'A');
    ispisMatrice(B, m, 'B');

    proizvodMatrica(A, B, C, m);

    ispisMatrice(C, m, 'C');

    return 0;
}

