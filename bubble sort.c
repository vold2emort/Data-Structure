#include<stdio.h>
#define max 10
int i,j;
void BubbleSort(int a[], int n){
	int temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int main(){
	int n,array[10];
	printf("enter no of elements in array:\n");
	scanf("%d",&n);
	printf("Enter unsorted elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	BubbleSort(array,n);
	printf("The sorted list is :\n");
	for(i=0;i<n;i++){
		printf("%d\t",array[i]);
	}
}