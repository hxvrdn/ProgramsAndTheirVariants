#include <stdio.h>

// 1. Standard Linear Search (First Occurrence)
int linearSearchFirst(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// 2. Linear Search (Last Occurrence)
int linearSearchLast(int arr[], int n, int key) {
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// 3. Linear Search (All Occurrences)
void linearSearchAll(int arr[], int n, int key) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Found at index %d\n", i);
            found = 1;
        }
    }
    if (!found)
        printf("Element not found\n");
}

// 4. Sentinel Linear Search
int sentinelSearch(int arr[], int n, int key) {
    int last = arr[n - 1];
    if (arr[n - 1] == key)
        return n - 1;

    arr[n - 1] = key;  // place sentinel

    int i = 0;
    while (arr[i] != key)
        i++;

    arr[n - 1] = last; // restore

    if (i < n - 1)
        return i;
    return -1;
}

// 5. Move-To-Front Search
int moveToFrontSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            int temp = arr[i];
            for (int j = i; j > 0; j--)
                arr[j] = arr[j - 1];
            arr[0] = temp;
            return 0;
        }
    }
    return -1;
}

// 6. Transposition Search
int transpositionSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            if (i > 0) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                return i - 1;
            }
            return i;
        }
    }
    return -1;
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    printf("Linear Search Variants:\n\n");
    int arr[] = {4, 0, 7, 2, 9, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2;

    printf("Array: ");
    printArray(arr, n);
    printf("Searching for: %d\n\n", key);

    // 1. First occurrence
    int first = linearSearchFirst(arr, n, key);
    printf("First occurrence index: %d\n", first);

    // 2. Last occurrence
    int last = linearSearchLast(arr, n, key);
    printf("Last occurrence index: %d\n", last);

    // 3. All occurrences
    printf("All occurrences:\n");
    linearSearchAll(arr, n, key);

    // 4. Sentinel search
    int sent = sentinelSearch(arr, n, key);
    printf("Sentinel search index: %d\n", sent);

    // 5. Move-to-front search
    int mtf = moveToFrontSearch(arr, n, key);
    printf("Move-to-front index: %d\n", mtf);
    printf("Array after Move-to-Front: ");
    printArray(arr, n);

    // Reset array for next test
    int arr2[] = {4, 0, 7, 2, 9, 2, 5};

    // 6. Transposition search
    int trans = transpositionSearch(arr2, n, key);
    printf("Transposition index: %d\n", trans);
    printf("Array after Transposition: ");
    printArray(arr2, n);

    return 0;
}