#include<stdio.h>
#include<stdlib.h>
int i,j;
typedef struct kstack{
  int *arr;
  int *top;
  int *next;
  int n,k;
  int free;
}kstack;

kstack* create(int k,int n){
  kstack*ks=(kstack*)malloc(sizeof(kstack));
  ks->k=k;
  ks->n=n;
  ks->arr = (int*)malloc(n * sizeof(int));
  ks->top = (int*)malloc(k * sizeof(int));
  ks->next = (int*)malloc(n * sizeof(int));
  for ( i = 0; i < k; i++)ks->top[i] = -1;
  ks->free=0;
  for ( i = 0; i < n-1; i++)ks->next[i]=i+1;
  ks->next[n-1]=-1;
  return ks;

}


int isfull(kstack*ks){
  return (ks->free==-1);
}

int isempty(kstack*ks,int sn){
  return (ks->top[sn]==-1);
}

void push(kstack*ks,int val,int sn){
    if (isfull(ks)) {
        printf("\nStack Overflow\n");
        return;
    }
    int i=ks->free;
    ks->free=ks->next[i];
    ks->next[i]=ks->top[sn];
    ks->top[sn]=i;
    ks->arr[i]=val;
    printf("Pushed %d into stack %d\n", val, sn);
}


int pop(kstack* ks,int sn){
      if (isempty(ks, sn)) {
        printf("\nStack Underflow in stack %d\n", sn);
        return 0;
    }
    int i=ks->top[sn];
    ks->top[sn]=ks->next[i];
    ks->next[i]=ks->free;
    ks->free=i;

    return ks->arr[i];
}

int main() {
    int k, n, choice, stackNum, value;

    printf("Enter the number of stacks: ");
    scanf("%d", &k);
    printf("Enter the total size of the array: ");
    scanf("%d", &n);

    kstack* ks = create(k, n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push to a stack\n");
        printf("2. Pop from a stack\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack number (0 to %d): ", k - 1);
                scanf("%d", &stackNum);
                if (stackNum < 0 || stackNum >= k) {
                    printf("Invalid stack number!\n");
                    break;
                }
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(ks, value, stackNum);
                break;
            case 2:
                printf("Enter stack number (0 to %d): ", k - 1);
                scanf("%d", &stackNum);
                if (stackNum < 0 || stackNum >= k) {
                    printf("Invalid stack number!\n");
                    break;
                }
                value = pop(ks, stackNum);
                if (value != 0) {
                    printf("Popped element from stack %d is %d\n", stackNum, value);
                }
                break;
            case 3:
                printf("Exiting...\n");
                free(ks->arr);
                free(ks->top);
                free(ks->next);
                free(ks);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}