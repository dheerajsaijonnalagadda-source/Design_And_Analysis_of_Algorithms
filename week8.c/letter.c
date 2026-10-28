// Huffman Coding Implementation5

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

int totalBits = 0;

struct Node* createNode(char ch, int freq) {
    struct Node* n = malloc(sizeof(struct Node));

    n->ch = ch;
    n->freq = freq;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void sort(struct Node* a[], int n) {
    int i, j;
    struct Node* temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j]->freq > a[j + 1]->freq) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void printNode(struct Node* n) {
    if (n->left == NULL && n->right == NULL)
        printf("%c(%d)", n->ch, n->freq);
    else
        printf("Node(%d)", n->freq);
}

void printCodes(struct Node* root, char code[], int top) {
    if (root->left == NULL && root->right == NULL) {
        if (top == 0) {
            code[top++] = '0';
        }

        code[top] = '\0';

        printf("%c\t%d\t%s\n",
               root->ch, root->freq, code);

        totalBits += root->freq * 100 * top;
        return;
    }

    code[top] = '0';
    printCodes(root->left, code, top + 1);

    code[top] = '1';
    printCodes(root->right, code, top + 1);
}

int main() {
    int n = 9, i;
    int freq[] = {20, 11, 2, 10, 15, 8, 10, 22, 2};
    char ch[] = {'a', 'c', 'd', 'e', 'o',
                 'm', 's', 't', 'u'};

    char code[100];

    struct Node* a[100];
    struct Node *left, *right, *parent;

    for (i = 0; i < n; i++) {
        a[i] = createNode(ch[i], freq[i]);
    }

    printf("Huffman Merging Steps:\n");

    while (n > 1) {
        sort(a, n);

        left = a[0];
        right = a[1];

        parent = createNode('$',
                            left->freq + right->freq);

        printf("Combine ");
        printNode(left);
        printf(" + ");
        printNode(right);
        printf(" = %d\n", parent->freq);

        parent->left = left;
        parent->right = right;

        for (i = 2; i < n; i++) {
            a[i - 2] = a[i];
        }

        a[n - 2] = parent;
        n--;
    }

    printf("\nHuffman Codes:\n");
    printf("Character\tFrequency\tCode\n");

    printCodes(a[0], code, 0);

    printf("\nTotal characters = 10000");
    printf("\nTotal memory = %d bits", totalBits);
    printf("\nMemory in bytes = %d bytes\n",
           totalBits / 8);

    return 0;
}
