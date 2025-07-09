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

// Function to merge two halves
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int L[n1], R[n2];

    // Copy data to temp arrays
    for (i = 0; i < n1; i++) L[i] = arr[left + i];
    for (j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    // Initial indexes
    i = 0; j = 0; k = left;

    // Merge the temp arrays back
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    // Copy the remaining elements
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    // Print merging step
    printf("Merging: ");
    printArray(arr, left, right);
    printf("\n");
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Print dividing step
        printf("Dividing: ");
        printArray(arr, left, right);
        printf(" -> ");
        printArray(arr, left, mid);
        printf(" and ");
        printArray(arr, mid + 1, right);
        printf("\n");

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Main function
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, 0, n - 1);
    printf("\n\n");

    mergeSort(arr, 0, n - 1);

    printf("\nSorted Array: ");
    printArray(arr, 0, n - 1);
    printf("\n");

    return 0;
}
