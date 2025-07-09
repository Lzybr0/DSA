#include<stdio.h>
void insertionsort(int a[], int n);

int main(){
    int a[100];
    int i,n;
    printf("\nEnter the value of n:");
    scanf("%d",&n);
    for (i=0; i<n; i++){
        printf("\nEnter the value of elements [%d]: ",i);
        scanf("%d",&a[i]);    
    }

    printf("\nThe elements before sorting");
    for (i=0; i<n; i++){
        printf("\t%d",a[i]);
    }

    insertionsort(a,n);
    printf("\nThe elements after sorting are:");
    for(i=0; i<n; i++){
        printf("%d\t",a[i]);
    }
    return 0;
}

void insertionsort(int a[], int n){
    int i,j,temp;

    for (i = 1; i<n; i++){
       temp = a[i];
       j = i - 1;
       while (j>=0 && a[j] > temp){
            a[j+1] = a[j];
            j--;
       }       
       a[j+1] = temp;
       }
}       
