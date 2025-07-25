# include <stdio.h>

void sortArray(int arr[], int n) {
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == key){
            return mid; 
        }
        
        else if(arr[mid] < key){
            left = mid + 1;
        }
        
        else{
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int n, key;

   
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    sortArray(arr, n);

    printf("Enter the element to search:");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if(result != -1){
        printf("Element found at index: %d\n", result);
    } 
	else{
        printf("Element not found in the array.\n");
    }
	return 0;
}