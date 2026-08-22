//Aim: To implement Binary Search Tree algorithm in C.



#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    temp->data = item;
    temp->left = temp->right = NULL;

    return temp;
}

struct node* insert(struct node* node, int value) {
    if (node == NULL)
        return newNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);

    return node;
}

struct node* minValueNode(struct node* node) {
    while (node->left != NULL)
        node = node->left;

    return node;
}

struct node* deleteNode(struct node* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);

    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {
    struct node* root = NULL;
    int n, value, del;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter value to delete: ");
    scanf("%d", &del);

    root = deleteNode(root, del);

    printf("Insertion and deletion completed.");

    return 0;
}