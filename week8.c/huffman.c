//1. Greedy Approach: Implementation of Huffman code

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

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

void printCodes(struct Node* root, char code[], int top) {
    if (root->left == NULL && root->right == NULL) {
        code[top] = '\0';
        printf("%c : %s\n", root->ch, code);
        return;
    }

    code[top] = '0';
    printCodes(root->left, code, top + 1);

    code[top] = '1';
    printCodes(root->right, code, top + 1);
}

int main() {
    int n, i, freq;
    char ch, code[100];
    struct Node* a[100];
    struct Node *left, *right, *parent;

    printf("Enter number of characters: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Enter between 1 and 100 characters.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter character and frequency: ");
        scanf(" %c %d", &ch, &freq);
        a[i] = createNode(ch, freq);
    }

    while (n > 1) {
        sort(a, n);

        left = a[0];
        right = a[1];

        parent = createNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        for (i = 2; i < n; i++) {
            a[i - 2] = a[i];
        }

        a[n - 2] = parent;
        n--;
    }

    printf("\nHuffman Codes:\n");
    printCodes(a[0], code, 0);

    return 0;
}
