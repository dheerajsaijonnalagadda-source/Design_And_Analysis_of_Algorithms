#include <stdio.h>

#define SIZE 10

int table[SIZE];

int main()
{
    int i, num, value, pos;

    /* Initialize hash table */
    for (i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &num);

    /* Insert elements */
    for (i = 0; i < num; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

        pos = value % SIZE;

        while (table[pos] != -1)
        {
            pos++;
            if (pos == SIZE)
                pos = 0;
        }

        table[pos] = value;
    }

    /* Display hash table */
    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("Index %d : %d\n", i, table[i]);
    }

    return 0;
}
