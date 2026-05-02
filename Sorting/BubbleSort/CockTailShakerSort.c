#include <stdio.h>

/*
Working:
- Bubble sort in both directions
- Forward pass moves largest to end
- Backward pass moves smallest to front

Time Complexity: O(n^2)
*/

void cocktailSort(int arr[], int n) {
    int start = 0, end = n - 1;
    int swapped = 1;

    while (swapped) {
        swapped = 0;

        // Forward pass
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        end--;

        // Backward pass
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        start++;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {5, 1, 4, 2, 8, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cocktailSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}