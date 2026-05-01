#include <stdio.h>

/*
Working:
- Instead of swapping, shift elements to maintain order
- Preserves relative order of equal elements

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

void stableSelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }

        int key = arr[min];

        // Shift elements instead of swapping
        while (min > i) {
            arr[min] = arr[min - 1];
            min--;
        }
        arr[i] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    stableSelectionSort(arr, n);

    printf("Stable sorted array:\n");
    printArray(arr, n);

    return 0;
}