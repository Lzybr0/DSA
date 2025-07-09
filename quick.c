#include <stdio.h>

// Function to print the array
void printArray(int arr[], int start, int end) {
    printf("[");
    for (int i = start; i <= end; i++) {
        printf("%d", arr[i]);
        if (i < end)
            printf(", ");
    }
    printf("]");
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = low - 1;        // smaller element index

    printf("Choosing pivot %d at index %d\n", pivot, high);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            printf("Swapped %d and %d: ", arr[i], arr[j]);
            printArray(arr, low, high);
            printf("\n");
        }
    }

    // Swap pivot to correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    printf("Moved pivot to index %d: ", i + 1); 
    printArray(arr, low, high);
    printf("\n\n");

    return i + 1;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        printf("Sorting subarray: ");
        printArray(arr, low, high);
        printf("\n");

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // left of pivot
        quickSort(arr, pi + 1, high); // right of pivot
    }
}

// Main function
int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, 0, n - 1);
    printf("\n\n");

    quickSort(arr, 0, n - 1);

    printf("Sorted Array: ");
    printArray(arr, 0, n - 1);
    printf("\n");


    return 0;
}
