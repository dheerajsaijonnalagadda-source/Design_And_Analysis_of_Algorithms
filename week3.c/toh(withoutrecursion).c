//Aim: To implement Tower of Hanoi algorithm without using recursion in C.

#include <stdio.h>

int main()
{
    int n, i, moves;
    char from, to;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    moves = (1 << n) - 1;

    for (i = 1; i <= moves; i++)
    {
        if (i % 3 == 1)
        {
            from = 'A';
            to = 'C';
        }
        else if (i % 3 == 2)
        {
            from = 'A';
            to = 'B';
        }
        else
        {
            from = 'B';
            to = 'C';
        }

        printf("Move disk from %c to %c\n", from, to);
    }

    return 0;
}