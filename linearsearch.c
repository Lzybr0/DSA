#include<stdio.h>

int lsearch(int arr[], int key, int n){
	int i;
	for(i=0; i<n; i++){
		if(arr[i] == key)
		return i;
	}
	return 0;
}

int main(){
	int a[100], n, i, key, j;
	printf("Enter the value of n:");
	scanf("%d",&n);
	
	printf("\n Enter the elements:");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	
	printf("\n Enter element to be searched:");
	scanf("%d",&key);
	
	j = lsearch(a,key,n);
	
	if(j)
		printf("\n Element found at %d",j);
	
	else
		printf("\n Element not found");
	return 0;
}