#include <stdio.h>

/*
Working:
- Same as bubble sort but stops early if no swaps occur
- Detects already sorted array

Best Case: O(n)
Worst Case: O(n^2)
*/

void bubbleSortOptimized(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSortOptimized(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}