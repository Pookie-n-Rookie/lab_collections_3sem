#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000

typedef struct Tree {
    int data;
    struct Tree* left;
    struct Tree* right;
} node;

// Create a new node
node* newnode(int data) {
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// Build the tree using preorder and inorder arrays
node* treeform(int preorder[], int prestart, int preend, int inorder[], int instart, int inend, int hash[]) {
    if (prestart > preend || instart > inend) return NULL;

    node* root = newnode(preorder[prestart]);
    int div = hash[root->data];

    int leftSize = div - instart;

    root->left = treeform(preorder, prestart + 1, prestart + leftSize, inorder, instart, div - 1, hash);
    root->right = treeform(preorder, prestart + leftSize + 1, preend, inorder, div + 1, inend, hash);
    return root;
}

// Calculate the height of the tree
int height(node* root) {
    if (!root) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return fmax(leftHeight, rightHeight) + 1;
}

// Print spaces
void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

// Print nodes at a specific level
void printLevel(node* root, int level, int currentLevel, int spacesBetween, int initialSpaces) {
    if (currentLevel == 1) {
        printSpaces(initialSpaces); // Leading spaces for alignment
        if (root) {
            printf("%d", root->data);
        } else {
            printf(" ");
        }
        printSpaces(spacesBetween); // Spaces between nodes at the same level
    } else if (root) {
        printLevel(root->left, level, currentLevel - 1, spacesBetween / 2, initialSpaces);
        printLevel(root->right, level, currentLevel - 1, spacesBetween / 2, initialSpaces);
    } else {
        printSpaces(spacesBetween + 1); // Empty space for null nodes
    }
}

// Print the binary tree in a properly aligned manner
void printTree(node* root) {
    int h = height(root);
    int maxWidth = pow(2, h - 1) - 1; // Maximum number of nodes at the last level
    int totalWidth = maxWidth * 3;   // Total width for alignment (arbitrary scaling factor)

    for (int level = 1; level <= h; level++) {
        int initialSpaces = totalWidth / pow(2, level); // Spaces at the beginning of the level
        int spacesBetween = totalWidth / pow(2, level - 1)+ 1; // Spaces between nodes at this level
        printLevel(root, h, level, spacesBetween, initialSpaces);
        printf("\n");
    }
}

int main() {
    int hash[MAX];
    for (int k = 0; k < MAX; k++) hash[k] = -1;

    int n;
    printf("Enter the number of elements in preorder or inorder: ");
    scanf("%d", &n);

    int preorder[n];
    int  inorder[n];
    printf("Enter the inorder: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
        hash[inorder[i]] = i;
    }

    printf("Enter the preorder: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    node* root = treeform(preorder, 0, n - 1, inorder, 0, n - 1, hash);
    if (root) {
        printf("\nCenter-Aligned Tree Representation:\n");
        printTree(root);
    }

    return 0;
}
