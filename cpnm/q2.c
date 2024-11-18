#include<stdio.h>
int main(){
	int n;
	printf("enter the size of the array : ");
	scanf("%d",&n);
	int a[n];
	int i;
	printf("enter the element of the array : ");
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	printf("the  list in reverse form is :");
	for(i=0;i<n/2;i++){
		int temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;}
	for(i=0;i<n;i++)printf("%d ",a[i]);}
