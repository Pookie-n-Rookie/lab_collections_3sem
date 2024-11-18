#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
int data;
struct Node *left, *right;
} Node;

Node* createNode(int data) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->data = data;
newNode->left = newNode->right = NULL;
return newNode;
}

Node* insert(Node* root, int data) {
if (root == NULL) {
return createNode(data);
}
if (data < root->data) {
root->left = insert(root->left, data);
} else {
root->right = insert(root->right, data);
}
return root;
}

Node* search(Node* root, int key) {
if (root == NULL || root->data == key) {
return root;
}
if (key < root->data) {
return search(root->left, key);
}
return search(root->right, key);
}

Node* findMin(Node* root) {
while (root && root->left != NULL) {
root = root->left;
}
return root;
}

Node* findMax(Node* root) {
while (root && root->right != NULL) {
root = root->right;
}
return root;
}

void findPreSuc(Node* root, Node** pre, Node** suc, int key) {
if (root == NULL) return;

if (root->data == key) {
if (root->left) {
*pre = findMax(root->left);
}
if (root->right) {
*suc = findMin(root->right);
}
} else if (key < root->data) {
*suc = root;
findPreSuc(root->left, pre, suc, key);
} else {
*pre = root;
findPreSuc(root->right, pre, suc, key);
}
}

Node* deleteNode(Node* root, int key) {
if (root == NULL) return root;
if (key < root->data) {
root->left = deleteNode(root->left, key);
} else if (key > root->data) {
root->right = deleteNode(root->right, key);
} else {
if (root->left == NULL) {
Node* temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
Node* temp = root->left;
free(root);
return temp;
}
Node* temp = findMin(root->right);
root->data = temp->data;
root->right = deleteNode(root->right, temp->data);
}
return root;
}

void inorder(Node* root) {
if (root) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}

int main() {
Node* root = NULL;
int choice, key;
Node *pre = NULL, *suc = NULL;

do {
printf("\nMenu:\n");
printf("1. Insert\n");
printf("2. Search\n");
printf("3. Find In-Order Predecessor and Successor\n");
printf("4. Delete\n");
printf("5. Display In-Order\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
printf("Enter key to insert: ");
scanf("%d", &key);
root = insert(root, key);
break;
case 2:
printf("Enter key to search: ");
scanf("%d", &key);
if (search(root, key)) {
printf("Key %d found in the BST.\n", key);
} else {
printf("Key %d not found in the BST.\n", key);
}
break;
case 3:
printf("Enter key to find predecessor and successor: ");
scanf("%d", &key);
findPreSuc(root, &pre, &suc, key);
if (pre) {
printf("Predecessor: %d\n", pre->data);
} else {
printf("No predecessor found.\n");
}
if (suc) {
printf("Successor: %d\n", suc->data);
} else {
printf("No successor found.\n");
}
break;
case 4:
printf("Enter key to delete: ");
scanf("%d", &key);
root = deleteNode(root, key);
break;
case 5:
printf("In-Order Traversal: ");
inorder(root);
printf("\n");
break;
case 6:
printf("Exiting...\n");
break;
default:
printf("Invalid choice! Please try again.\n");
}
} while (choice != 6);

return 0;
}

