#include<stdio.h>
int getIndex(int i,int j,int n){return i*n+j;}
int main(){
	int r,c,i,j;
	printf("enter the no. of rows and cols of 2d matrix :");
	scanf("%d %d",&r,&c);
	int matrix[r][c];
	int matrix1D[r*c];
	printf("enter the elements of the 2d matrix :\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("element at [%d][%d] is:" ,i,j); 
			scanf("%d",&matrix[i][j]);}
		printf("\n");
	}
	printf("1D array is :");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			matrix1D[getIndex(i,j,c)]=matrix[i][j];}
	for(i=0;i<r*c;i++)printf( "%d ",matrix1D[i]);
	printf("\n");
	return 0;}

