#include<stdio.h>

void mergesort(int a[], int lb, int ub){
  int mid;
  if (lb<ub){
      mid = (ub+lb)/2;
      mergesort(a,lb,mid);
      mergesort(a,mid+1,ub);
      mergesort(a,lb,mid,ub);
   }
}
void merge(int a[], int lb,int mid, int ub){
     i = lb, j = mid + 1, k = ub;
     int n1,n2, l[200], r[200];
     n1= mid - lb +1;
     n2 = ub - mid;
     for(i=0;i<n1;i++)
     {l[i]=a[lb+i];
     }
     for(j=0;j<n2;j++)
     {
     r[j]=a[mid+1+j];
     }
     i=0,j=0,k=lb;
     while (i < n1 && j<n2){
           if (l[i] <= r[j]){
              a[k++]=l[i++];
            
           }
     else {
        a[k++] = r[j++];
        j++;
     }
    
     }
while(i<n1)
a[k++]=l[i++];
while(j<n2)
a[k++]=r[j++];
     
     }
  int main()
  {
  int a[100],i,n;
  printf("enter the value of n");
  scanf("%d",&n);
  printf("enter the elements:");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  mergesort(a,0,n-1);
  printf("after sorting:\n");
  for(i=0;i<n;i++)
  printf("%d",a[i]);
  return 0;
  }




