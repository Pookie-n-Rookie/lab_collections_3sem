#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int val;
	struct Node *left;
	struct Node *right;
}Node;

Node* newNode(int data){
	Node* root=(Node*)malloc(sizeof(Node));
	root->val=data;
	root->left=NULL;
	root->right=NULL;
	return root;}

Node* insertNode(Node* root,int data){
	if(root==NULL)return newNode(data);
	int choice;
	printf("insert to the left (1) or right(2) of the Node with the val %d?",root->val);
	scanf("%d",&choice);
	if(choice==1){
		root->left=insertNode(root->left,data);
	}
	else if (choice==2){
		root->right=insertNode(root->right,data);
	}
	else printf("Invalid Choice !\n");
	return root;}

void inorder(Node *root){
	if(!root) return;
	inorder(root->left);
	printf("%d ",root->val);
	inorder(root->right);
}

void preorder(Node *root){
	if(!root) return;
	printf("%d ",root->val);
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node *root){
	if(!root) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->val);
}

int main(){
	Node *root=NULL;
	int choice,value,nodes,i;
	while(1){
		printf("\n Binary Tree Menu:\n");
		printf("1. Create a binary tree \n");
		printf("2. Inorder traversal \n");
		printf("3. preorder traversal \n");
		printf("4. post order traversal \n");
		printf("5. exit \n");
		printf("Enter the choice :");
		scanf("%d",&choice);
		switch (choice){
			case 1:
				printf("Enter no. of nodes :");
				scanf("%d",&nodes);
				for(i=0;i<nodes;i++){
					printf("Enter value of node %d :",i+1);
				       	scanf("%d",&value);
					root=insertNode(root,value);}
				printf("BINARY TREE CREATED!\n");
				break;
			case 2:
				printf("Inorder Traversal :");
				inorder(root);
				printf("\n");
				break;
			case 3:
				printf("Preorder Traversal :");
				preorder(root);
				printf("\n");
				break;
			case 4:
				printf("Post order Traversal :");
				postorder(root);
				printf("\n");
				break;
			case 5:
				printf("Exiting .....");
				exit(0);
			default:
				printf("Invalid choice !...");}}
			
	return 0;}




			
		











