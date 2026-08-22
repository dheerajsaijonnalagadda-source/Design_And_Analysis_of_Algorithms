//Aim:To implement sumation of series algorithm using recursion in C.   


#include <stdio.h>
#include <math.h>

int calculate(int x, int r) {
    if (r < 0) {
        return 0;
    }

    return pow(x, r) + calculate(x, r - 1);
}

int main() {
    int x, r;

    printf("Enter the value of x: ");
    scanf("%d", &x);

    printf("Enter the maximum value for power for the summation: ");
    scanf("%d", &r);

    printf("The value after summation is %d", calculate(x, r));

    return 0;
}