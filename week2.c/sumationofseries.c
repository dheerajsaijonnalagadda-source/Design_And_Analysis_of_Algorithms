//Aim: To implement sumation of series algorithm in C.


#include <stdio.h>
#include <math.h>

int main() {
    int x, r;

    printf("Enter the value of x: ");
    scanf("%d", &x);

    printf("Enter value of power to get added: ");
    scanf("%d", &r);

    int sum = 0;
    int a;

    for (int n = 0; n <= r; n++) {
        a = pow(x, n);
        sum = sum + a;
    }

    printf("The summation of series is %d", sum);

    return 0;
}