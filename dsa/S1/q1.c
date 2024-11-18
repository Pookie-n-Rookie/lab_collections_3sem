#include<stdio.h>


void del(int a[],int n,int ind){
	ind--;
	int i;
	for(i=ind;i<n-1;i++)a[i]=a[i+1];}
	
int main(){
	int a[10];
	int i;
	printf("ENTER THE ARRAY WITH 10 ELEMENTS :");
	for(i=0;i<10;i++)scanf("%d",&a[i]);
	del(a,10,6);
	del(a,10,3);
	printf(" THE array after deleting 3rd and 6th element is :\n");
	for(i=0;i<8;i++)printf("%d ",a[i]);
	printf("\nthe 5th element is : %d",a[4]);
	return 0;}
	
