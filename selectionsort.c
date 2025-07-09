#include<stdio.h>
void selectionsort(int a[], int n);

int main(){
    int a[500];
    int i,n,j;
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

    selectionsort(a,n);
    printf("\nThe elements after sorting are:");
    for(i=0; i<n; i++){
        printf("%d\t",a[i]);
    }
    return 0;
}

void selectionsort(int a[], int n){
    int i,j,min,temp;

    for (i = 0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if (a[j] < a[min]){
                min = j;
            }
         }   
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
    }
}
