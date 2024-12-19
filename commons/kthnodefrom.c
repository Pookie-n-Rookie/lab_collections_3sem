#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} node;

node *create_node(int value) {
    node *newe = (node *)malloc(sizeof(node));
    if (newe == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newe->val = value;
    newe->next = NULL;
    return newe;
}

node *input() {
    int n;
    printf("Enter the size of the linked list: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The linked list must have at least one node.\n");
        return NULL;
    }

    printf("Enter the elements of the linked list:\n");
    int headValue;
    scanf("%d", &headValue);
    node *head = create_node(headValue);
    node *temp = head;

    for (int i = 1; i < n; i++) {
        int value;
        scanf("%d", &value);
        temp->next = create_node(value);
        temp = temp->next;
    }

    return head;
}

node *kth_node_end(node *head, int k) {
    node *s = head;
    node *f = head;

    for (int i = 0; i < k; i++) {
        if (f == NULL) {
            printf("The list has fewer than %d nodes.\n", k);
            return NULL;
        }
        f = f->next;
    }

    while (f != NULL) {
        f = f->next;
        s = s->next;
    }

    return s;
}

void print(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    node *head1 = input();
    if (head1 == NULL) {
        return 0;
    }

    printf("Linked list: ");
    print(head1);

    int k;
    printf("Enter the position from the back: ");
    scanf("%d", &k);

    node *kth = kth_node_end(head1, k);
    if (kth != NULL) {
        printf("The %d-th node from the end has the value: %d\n", k, kth->val);
        printf("The address of the %d-th node from the end is: %p\n", k, (void *)kth);
    }

    node *temp;
    while (head1 != NULL) {
        temp = head1;
        head1 = head1->next;
        free(temp);
    }

    return 0;
}
