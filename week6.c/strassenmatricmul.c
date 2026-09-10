/*3. Divide and conquer: Implementation of Strassen’s algorithm for matrix multiplication.
Also analyze how this approach is advantage when compared to normal multiplication*/


#include <stdio.h>
#define N 2

void STRASSEN(int A[N][N], int B[N][N], int C[N][N])
{
    int P, Q, R, S, T, U, V;

    P = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    Q = (A[1][0] + A[1][1]) * B[0][0];
    R = A[0][0] * (B[0][1] - B[1][1]);
    S = A[1][1] * (B[1][0] - B[0][0]);
    T = (A[0][0] + A[0][1]) * B[1][1];
    U = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    V = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = P + S - T + V;
    C[0][1] = R + T;
    C[1][0] = Q + S;
    C[1][1] = P + R - Q + U;
}

int main()
{
    
    int A[N][N], B[N][N], C[N][N];
    int i, j;

    printf("Enter Matrix A:\n");
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &B[i][j]);

    STRASSEN(A, B, C);

    printf("\nResult Matrix C:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}