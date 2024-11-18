#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef struct Tree {
    int data;
    struct Tree* left;
    struct Tree* right;
} node;

node* newnode(int data) {
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

node* treeform(int preorder[], int prestart, int preend, int inorder[], int instart, int inend, int hash[]) {
    if (prestart > preend || instart > inend) return NULL;

    node* root = newnode(preorder[prestart]);
    int div = hash[root->data];

    // Check if div is a valid index in inorder
    if (div < instart || div > inend) {
        printf("Error: Invalid index for inorder traversal.\n");
        return NULL;
    }

    int leftSize = div - instart; // Size of the left subtree

    root->left = treeform(preorder, prestart + 1, prestart + leftSize, inorder, instart, div - 1, hash);
    root->right = treeform(preorder, prestart + leftSize + 1, preend, inorder, div + 1, inend, hash);
    
    return root;
}

int main() {
    int hash[MAX];
    for (int k = 0; k < MAX; k++) hash[k] = -1; // Initialize hash to avoid undefined behavior

    int n;
    printf("Enter the number of elements in preorder or inorder: ");
    scanf("%d", &n);

    int preorder[n], inorder[n];
    printf("Enter the inorder: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
        if (inorder[i] < MAX) // Ensure the value is within the valid range
            hash[inorder[i]] = i;
        else {
            printf("Error: Inorder value exceeds maximum index.\n");
            return -1;
        }
    }

    printf("Enter the preorder: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
        if (preorder[i] < MAX) {
            if (hash[preorder[i]] == -1) {
                printf("Error: Preorder value does not exist in inorder.\n");
                return -1;
            }
        } else {
            printf("Error: Preorder value exceeds maximum index.\n");
            return -1;
        }
    }

    node* ans = treeform(preorder, 0, n - 1, inorder, 0, n - 1, hash);
    if (ans != NULL)
        printf("The root of the tree is: %d\n", ans->data);
    
    return 0;
}

