#include <stdio.h>

/*
---------------------------------------------------------
1. Standard Binary Search (Iterative)
---------------------------------------------------------
Working:
- Divide the array into halves repeatedly
- Compare middle element with key
- Narrow search space (left or right)

Time Complexity: O(log n)
Space Complexity: O(1)
*/
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

/*
---------------------------------------------------------
2. Recursive Binary Search
---------------------------------------------------------
Working:
- Same logic as iterative, but uses recursion

Time Complexity: O(log n)
Space Complexity: O(log n) (due to recursion stack)
*/
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
}

/*
---------------------------------------------------------
3. First Occurrence (Lower Bound)
---------------------------------------------------------
Working:
- Keep searching left even after finding key
- Ensures first occurrence is found

Time Complexity: O(log n)
Space Complexity: O(1)
*/
int firstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;
            high = mid - 1; // go left
        } else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

/*
---------------------------------------------------------
4. Last Occurrence (Upper Bound)
---------------------------------------------------------
Working:
- Keep searching right after finding key

Time Complexity: O(log n)
Space Complexity: O(1)
*/
int lastOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;
            low = mid + 1; // go right
        } else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

/*
---------------------------------------------------------
5. Count Occurrences
---------------------------------------------------------
Working:
- Use first and last occurrence

Time Complexity: O(log n)
Space Complexity: O(1)
*/
int countOccurrences(int arr[], int n, int key) {
    int first = firstOccurrence(arr, n, key);
    if (first == -1) return 0;

    int last = lastOccurrence(arr, n, key);
    return last - first + 1;
}

/*
---------------------------------------------------------
6. Floor (largest element <= key)
---------------------------------------------------------
Time Complexity: O(log n)
*/
int floorSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= key) {
            ans = arr[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

/*
---------------------------------------------------------
7. Ceil (smallest element >= key)
---------------------------------------------------------
Time Complexity: O(log n)
*/
int ceilSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= key) {
            ans = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

/*
---------------------------------------------------------
Utility: Print array
---------------------------------------------------------
*/
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*
---------------------------------------------------------
MAIN FUNCTION
---------------------------------------------------------
*/
int main() {
    int arr[] = { 1, 3,  5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2;

    printf("Array: ");
    printArray(arr, n);
    printf("Searching for: %d\n\n", key);

    // 1. Standard Binary Search
    int index = binarySearch(arr, n, key);
    printf("Binary Search Index: %d\n", index);

    // 2. Recursive Binary Search
    int recIndex = binarySearchRecursive(arr, 0, n - 1, key);
    printf("Recursive Binary Search Index: %d\n", recIndex);

    // 3. First Occurrence
    printf("First Occurrence: %d\n", firstOccurrence(arr, n, key));

    // 4. Last Occurrence
    printf("Last Occurrence: %d\n", lastOccurrence(arr, n, key));

    // 5. Count Occurrences
    printf("Count of %d: %d\n", key, countOccurrences(arr, n, key));

    // 6. Floor
    printf("Floor of %d: %d\n", key, floorSearch(arr, n, key));

    // 7. Ceil
    printf("Ceil of %d: %d\n", key, ceilSearch(arr, n, key));

    return 0;
}